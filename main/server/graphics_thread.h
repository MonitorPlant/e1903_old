#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <windows.h>

#include "../common/object.h"
#include "debug.h"

#define DISPLAY_MAX_CHAR_X 235
#define DISPLAY_MAX_CHAR_Y 66
#define DISPLAY_MAX_RESOLUTION_X 1920
#define DISPLAY_MAX_RESOLUTION_Y 1080

DWORD WINAPI GraphicsThread( LPVOID arg ); //グラフィック用スレッド

BOOL displayInit( void ); //初期化関数
void displayUpdate( int map[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ] ); //画面出力関数
void writeObject( int map[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ], CommonObject object );

#endif /* DISPLAY_H_ */