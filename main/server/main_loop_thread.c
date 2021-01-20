#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "../common/debug.h"
#include "graphics_thread.h"
#include "main_loop_thread.h"

extern CommonObject map_source;
extern CommonObject self, enemy;
extern CommonObject target[ MAX_TARGET_NUM ];
extern CommonObject bullet[ MAX_BULLET_NUM ];
extern MouseState self_mouse, enemy_mouse;

extern BOOL end_program;
extern BOOL game_end;
extern char point_self, point_enemy;
extern char remain_time;

static HTIMER main_timer;
static HTIMER target_timer;
static HTIMER bullet_timer;
static HTIMER generate_target_timer;

DWORD WINAPI MainLoopThread( LPVOID arg )
{
    int i;

    //対戦相手が見つかるまで待機
    map_source.x = 0;
    map_source.y = 0;
    setTimer( main_timer );
    while( enemy.isExist == FALSE )
    {
        //500msごとにロード画面を切り替え
        switch( ( passedTime( main_timer ) / 500 ) % 4 )
        {
            case 0:
                map_source.isChanging = TRUE;
                map_source.type = TYPE_LOADING0;
                map_source.isChanging = FALSE;
                break;
            case 1:
                map_source.isChanging = TRUE;
                map_source.type = TYPE_LOADING1;
                map_source.isChanging = FALSE;
                break;
            case 2:
                map_source.isChanging = TRUE;
                map_source.type = TYPE_LOADING2;
                map_source.isChanging = FALSE;
                break;
            case 3:
                map_source.isChanging = TRUE;
                map_source.type = TYPE_LOADING3;
                map_source.isChanging = FALSE;
        }
        Sleep( 1 );
    }
    
    
    //プレイヤーがマウスをクリックするまで待機 スペースを押すとルール説明
    /* map_source.type = STAR WARS */
    while( self_mouse.click_left == FALSE )
    {
        updateMouseState();
        if( GetAsyncKeyState( VK_SPACE ) & 0x8000 )
        {
            /* map_source.type = ルール説明 */
            Sleep( 100 );
            while( GetAsyncKeyState( VK_SPACE ) & 0x8000 )
            {
                Sleep( 1 );
            }
            Sleep( 100 );
            while( ( GetAsyncKeyState( VK_SPACE ) & 0x8000 ) == FALSE )
            {
                Sleep( 1 );
            }
            /* map_source.type = STAR WARS */
            Sleep( 100 );
            while( GetAsyncKeyState( VK_ESCAPE ) & 0x8000 )
            {
                Sleep( 1 );
            }
            Sleep( 100 );
        }
        Sleep( 1 );
    }


    //カウントダウン
    map_source.x = DISPLAY_MAX_CHAR_X / 2;
    map_source.y = DISPLAY_MAX_CHAR_Y / 2;
    map_source.isChanging = TRUE;
    /* map_source.type = 3秒前 */
    map_source.isChanging = FALSE;
    setTimer( main_timer );
    while( passedTime( main_timer ) < 1000 )
    {
        Sleep( 1 );
    }
    map_source.isChanging = TRUE;
    /* map_source.type = 2秒前 */
    map_source.isChanging = FALSE;
    while( passedTime( main_timer ) < 2000 )
    {
        Sleep( 1 );
    }
    map_source.isChanging = TRUE;
    /* map_source.type = 1秒前 */
    map_source.isChanging = FALSE;
    while( passedTime( main_timer ) < 3000 )
    {
        Sleep( 1 );
    }


    //ゲームスタート
    mainLoop();


    //結果画面
    map_source.isExist = TRUE;
    map_source.isChanging = TRUE;
    if( point_self > point_enemy )
    {
        /* map_source.type = 自分が勝った画面 */
    }
    else
    {
        /* map_source.type = 敵が勝った画面 */
    }
    map_source.isChanging = FALSE;
    


    ( void )arg;

    return 0;
}

void mainLoop( void )
{
    int i, j;
    srand( ( unsigned )time( NULL ) );
    //変数の再初期化
    map_source.isExist = FALSE;
    self.isExist = TRUE;
    enemy.isExist = FALSE;
    setTimer( main_timer );
    setTimer( target_timer );
    setTimer( bullet_timer );
    setTimer( generate_target_timer );
    while( passedTime( main_timer ) < 60000 )
    {
        //残り時間設定
        remain_time = passedTime( main_timer ) / 1000;

        //キャラクターの座標を移動
        updateMouseState();

        //60msごとに的を移動
        if( passedTime( target_timer ) > 60 )
        {
            setTimer( target_timer );
            for( i = 0; i < MAX_TARGET_NUM; i++ )
            {
                if( target[ i ].isExist )
                {
                    target[ i ].y++;
                    //範囲外に出れば削除
                    if( target[ i ].y > DISPLAY_MAX_CHAR_Y )
                    {
                        target[ i ].isExist = FALSE;
                    }
                }
            }
        }
        //10msごとに弾を移動
        if( passedTime( bullet_timer ) > 10 )
        {
            setTimer( bullet_timer );
            for( i = 0; i < MAX_BULLET_NUM; i++ )
            {
                //自分の弾なら右に移動 敵の弾なら左に移動
                if( bullet[ i ].isExist )
                {
                    if( bullet[ i ].type == SELF_BULLET )
                    {
                        bullet[ i ].x++;
                    }
                    else
                    {
                        bullet[ i ].x--;
                    }
                    //範囲外に出れば削除
                    if( bullet[ i ].x < 0 || DISPLAY_MAX_CHAR_X < bullet[ i ].x )
                    {
                        bullet[ i ].isExist = FALSE;
                    }
                }
            }
        }
        //1sごとに的を追加
        if( passedTime( generate_target_timer ) > 1000 )
        {
            setTimer( generate_target_timer );
            for( i = 0; i < MAX_TARGET_NUM; i++ )
            {
                if( target[ i ].isExist == FALSE )
                {
                    target[ i ].isExist = TRUE;
                    target[ i ].y = 0;
                    target[ i ].x = rand() / DISPLAY_MAX_CHAR_X;
                    break;
                }
            }
        }
        //当たり判定
        //自分と敵の弾が重なっていないか判定
        for( i = 0; i < MAX_BULLET_NUM; i++ )
        {
            if( bullet[ i ].isExist == TRUE && bullet[ i ].type == ENEMY_BULLET )
            {
                if( bullet[ i ].x + bullet[ i ].size_x > self.x && bullet[ i ].x < self.x + self.size_x && bullet[ i ].y + bullet[ i ].size_y > self.y && bullet[ i ].y < self.y + self.size_y )
                {
                    bullet[ i ].isExist = FALSE;
                    point_enemy += 10;
                }
            }
        }
        //敵と自分の弾が重なっていないか判定
        for( i = 0; i < MAX_BULLET_NUM; i++ )
        {
            if( bullet[ i ].isExist == TRUE && bullet[ i ].type == SELF_BULLET )
            {
                if( bullet[ i ].x + bullet[ i ].size_x > self.x && bullet[ i ].x < self.x + self.size_x && bullet[ i ].y + bullet[ i ].size_y > self.y && bullet[ i ].y < self.y + self.size_y )
                {
                    bullet[ i ].isExist = FALSE;
                    point_self += 10;
                }
            }
        }
        //弾丸と的が重なっていないか判定
        for( i = 0; i < MAX_TARGET_NUM; i++ )
        {
            for( j = 0; j < MAX_BULLET_NUM; j++ )
            {
                if( bullet[ j ].isExist == TRUE )
                {
                    if( bullet[ j ].x + bullet[ j ].size_x > target[ i ].x && bullet[ j ].x < target[ i ].x + target[ i ].size_x && bullet[ j ].y + bullet[ j ].size_y > target[ i ].y && bullet[ j ].y < target[ i ].y + target[ i ].size_y )
                    {
                        if( bullet[ j ].type == SELF_BULLET )
                        {
                            point_self += 1;
                        }
                        else
                        {
                            point_enemy += 1;
                        }
                    }
                }
            }
        }
    }

    //終了処理
    game_end = TRUE;
    self.isExist = FALSE;
    enemy.isExist = FALSE;
    for( i = 0; i < MAX_BULLET_NUM; i++ )
    {
        bullet[ i ].isExist = FALSE;
    }
    for( i = 0; i < MAX_TARGET_NUM; i++ )
    {
        target[ i ].isExist = FALSE;
    }
}


void updateMouseState( void )
{
    POINT pt;

    //カーソルの座標を取得
    if( !GetCursorPos( &pt ) )
    {
        printErrorMessage( "mouse.c", "GetCursorPos()" );
        return;
    }
    
    //カーソルの位置を範囲内に収める
    if( pt.x > 959 )
    {
        pt.x = 959;
        if( !SetCursorPos( pt.x, pt.y ) )
        {
            printErrorMessage( "mouse.c", "SetCursorPos()" );
            return;
        }
    }

    //座標をコピー、各ボタンの状態を更新
    self.x = pt.x / 8;
    self.y = pt.y / 18;
    self_mouse.click_left = ( GetKeyState( VK_LBUTTON ) >> 15 ) & 1;
    self_mouse.click_right = ( GetKeyState( VK_RBUTTON ) >> 15 ) & 1;
    self_mouse.click_wheel = ( GetKeyState( VK_MBUTTON ) >> 15 ) & 1;
}

void setTimer( HTIMER hTimer )
{
    //タイマー用変数のメモリ領域を確保
    hTimer = (HTIMER)malloc( sizeof( DWORD ) );

    if( hTimer == NULL )
    {
        printErrorMessage( "timer.c", "malloc()" );
    }

    //タイマーの開始時間を記録
    *hTimer = GetTickCount();
}

DWORD passedTime( HTIMER hTimer )
{
    //setTimer()した時からの経過時間
    return GetTickCount() - *hTimer;
}

void releaseTimer( HTIMER hTimer )
{
    //タイマー用変数のメモリ領域を解放
    free( hTimer );
}
