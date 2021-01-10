#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <windows.h>

#include "debug.h"

DWORD WINAPI GraphicsThread( LPVOID arg ); //グラフィック用スレッド

void displayInit( void ); //初期化関数
void displayUpdate( void ); //描画用関数

#endif /* DISPLAY_H_ */