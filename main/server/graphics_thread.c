#include <windows.h>

#include "debug.h"
#include "graphics_thread.h"

extern CommonObject self, enemy;
extern CommonObject target[ MAX_TARGET_NUM ];
extern CommonObject bullet[ MAX_BULLET_NUM ];

extern BOOL end_program;
extern int point_self, point_enemy;

DWORD WINAPI GraphicsThread( LPVOID arg )
{
    ( void )arg;
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
    int i, j;
    for( i = 0; i < object.size_y; i++ )
    {
        for( j = 0; j < object.size_x; j++ )
        {
            map[ i + object.y ][ j + object.x ] = object.design[ i ][ j ];
        }
    }
}