#include <windows.h>
#include <stdlib.h>

#include "debug.h"
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

DWORD WINAPI MainLoopThread( LPVOID arg )
{
    //タイマーの種を生成
    HTIMER graphics_timer; //グラフィック用


    //対戦相手が見つかるまで待機
    map_source.x = 0;
    map_source.y = 0;
    setTimer( graphics_timer );
    while( enemy.isExist == FALSE )
    {
        //500msごとにロード画面を切り替え
        switch( ( passedTime( graphics_timer ) / 500 ) % 3 )
        {
            case 0:
                map_source.isChanging = TRUE;
                /* map_source.type = LOADING. */
                map_source.isChanging = FALSE;
                break;
            case 1:
                map_source.isChanging = TRUE;
                /* map_source.type = LOADING.. */
                map_source.isChanging = FALSE;
                break;
            case 2:
                map_source.isChanging = TRUE;
                /* map_source.type = LOADING... */
                map_source.isChanging = FALSE;
                break;
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


    //対戦相手が見つかるまで待機
    while( enemy.isExist == FALSE )
    {
        Sleep( 1 );
    }


    ( void )arg;

    return 0;
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