#ifndef MAIN_LOOP_THREAD_H_
#define MAIN_LOOP_THREAD_H_

#include <windows.h>

#include "object.h"
#include "debug.h"

typedef struct _MOUSE_STATE_
{
    DWORD x;
    DWORD y;
    BOOL click_left;
    BOOL click_right;
    BOOL click_wheel;
} MouseState;

DWORD WINAPI MainLoopThread( LPVOID arg ); //ゲーム処理用スレッド

BOOL updateMouseState( MouseState m ); //マウスの状態を更新

#endif /* MAIN_LOOP_THREAD_H_ */
