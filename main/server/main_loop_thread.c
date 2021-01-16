#include <windows.h>

#include "debug.h"
#include "main_loop_thread.h"

extern CommonObject self, enemy;
extern CommonObject target[ MAX_TARGET_NUM ];
extern CommonObject bullet[ MAX_BULLET_NUM ];

extern BOOL end_program;
extern int point_self, point_enemy;

DWORD WINAPI MainLoopThread( LPVOID arg )
{
    MouseState mouse;
    ( void )arg;
    while( mouse.click_left == FALSE ) //プレイヤーがマウスをクリックするまで待機
    {
        updateMouseState( mouse );
    }
    while( enemy.isExist == FALSE )//対戦相手が見つかるまで待機
    {
        Sleep( 1 );
    }

    return 0;
}


BOOL updateMouseState( MouseState m )
{
    POINT pt;

    //カーソルの座標を取得
    if( !GetCursorPos( &pt ) )
    {
        printErrorMessage( "mouse.c", "GetCursorPos()" );
        return FALSE;
    }
    
    //カーソルの位置を範囲内に収める
    if( pt.x > 959 )
    {
        pt.x = 959;
        if( !SetCursorPos( pt.x, pt.y ) )
        {
            printErrorMessage( "mouse.c", "SetCursorPos()" );
            return FALSE;
        }
    }

    //座標をコピー、各ボタンの状態を更新
    m.x = pt.x;
    m.y = pt.y;
    m.click_left = ( GetKeyState( VK_LBUTTON ) >> 15 ) & 1;
    m.click_right = ( GetKeyState( VK_RBUTTON ) >> 15 ) & 1;
    m.click_wheel = ( GetKeyState( VK_MBUTTON ) >> 15 ) & 1;

    return TRUE;
}