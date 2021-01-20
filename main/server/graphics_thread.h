#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <windows.h>

#include "../common/debug.h"
#include "../common/object.h"

#define DISPLAY_MAX_CHAR_X 236
#define DISPLAY_MAX_CHAR_Y 67
#define DISPLAY_MAX_RESOLUTION_X 1920
#define DISPLAY_MAX_RESOLUTION_Y 1080

#define TYPE_LOADING0 1
#define TYPE_LOADING1 2
#define TYPE_LOADING2 3
#define TYPE_LOADING3 4
#define TYPE_TITLE 5
#define TYPE_RULES 6
#define TYPE_SELF_WIN 7
#define TYPE_ENEMY_WIN 8

DWORD WINAPI GraphicsThread( LPVOID arg ); //グラフィック用スレッド

void displayUpdate( int map[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ] ); //画面出力関数
void writeObject( int map[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ], CommonObject object );
void setCursorPos_1( int x, int y );
void setCursorPos_2( int x, int y );

#endif /* DISPLAY_H_ */
