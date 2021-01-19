#include <windows.h>

#include "../common/debug.h"
#include "../common/object.h"
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

extern const int char_loading0[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ], char_loading1[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ], char_loading2[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ], char_loading3[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ];
extern const int char_target1[5][10], char_target2[5][10], char_target3[3][6], char_target4[2][4];
extern const int char_bullet_self[2][8], char_bullet_enemy[2][8];
extern const int char_self[15][30], char_self_shield[15][30], char_enemy[15][30], char_enemy_shield[15][30];

DWORD WINAPI GraphicsThread( LPVOID arg )
{
    SMALL_RECT rc = { 0, 0, DISPLAY_MAX_CHAR_X, DISPLAY_MAX_CHAR_Y };
    COORD coord;
    
    coord.X = rc.Right + 1;
	coord.Y = rc.Bottom + 1;
	SetConsoleScreenBufferSize(hCon1, coord);
	SetConsoleScreenBufferSize(hCon2, coord);
	SetConsoleWindowInfo(hCon1, TRUE, &rc);
	SetConsoleWindowInfo(hCon2, TRUE, &rc);

    AllocConsole();
	SetConsoleTitle(TEXT("STAR SHOOT"));

    hCon1 = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	hCon2 = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

    while( end_program == FALSE )
    {
        displayUpdate( 
    }

    ( void )arg;
    return 0;
}

void displayUpdate( int map[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ] )
{
    int i;
    while( TRUE )
    {
        //writeObject( map, map_source ); //背景を書き込む
        //writeObject( map, self ); //自分の絵を書き込む
        //writeObject( map, enemy ); //敵の絵を書き込む
        for( i = 0; i < MAX_TARGET_NUM; i++ ) //的の絵を書き込む
        {
            if( target[ i ].isExist == TRUE )
            {
                //writeObject( map, target[ i ] );
            }
        }
        for( i = 0; i < MAX_BULLET_NUM; i++ ) //弾丸の絵を書き込む
        {
            if( bullet[ i ].isExist == TRUE )
            {
                //writeObject( map, target[ i ] );
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
