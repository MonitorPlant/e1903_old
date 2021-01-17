#include <windows.h>

#include "debug.h"
#include "graphics_thread.h"

extern CommonObject map_source;
extern CommonObject self, enemy;
extern CommonObject target[ MAX_TARGET_NUM ];
extern CommonObject bullet[ MAX_BULLET_NUM ];
extern MouseState self_mouse, enemy_mouse;

extern BOOL end_program;
extern BOOL game_end;
extern char point_self, point_enemy;
extern char remain_time;

DWORD WINAPI GraphicsThread( LPVOID arg )
{
    ( void )arg;
    while( end_program == FALSE )
    {
        Sleep( 1 );
    }
    return 0;
}
BOOL displayInit( void )
{
    return TRUE;
}

void displayUpdate( int map[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ] )
{
    int i;
    while( TRUE )
    {
        writeObject( map, map_source ); //背景を書き込む
        writeObject( map, self ); //自分の絵を書き込む
        writeObject( map, enemy ); //敵の絵を書き込む
        for( i = 0; i < MAX_TARGET_NUM; i++ ) //的の絵を書き込む
        {
            if( target[ i ].isExist == TRUE )
            {
                writeObject( map, target[ i ] );
            }
        }
        for( i = 0; i < MAX_BULLET_NUM; i++ ) //弾丸の絵を書き込む
        {
            if( bullet[ i ].isExist == TRUE )
            {
                writeObject( map, target[ i ] );
            }
        }

        //この後にダブルバッファリングの処理を入れる
    }
}

//引数として渡されたオブジェクトをint型の配列に数字として書き込む関数
void writeObject( int map[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ], CommonObject object )
{
    unsigned int i, j;
    for( i = 0; i < object.size_y; i++ )
    {
        for( j = 0; j < object.size_x; j++ )
        {
            map[ i + object.y ][ j + object.x ] = object.design[ i ][ j ];
        }
    }
}