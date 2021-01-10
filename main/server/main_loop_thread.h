#ifndef MAIN_LOOP_THREAD_H_
#define MAIN_LOOP_THREAD_H_

#include <windows.h>

#include "debug.h"

typedef struct _MOUSE_STATE_
{
    DWORD x;
    DWORD y;
    BOOL click_left;
    BOOL click_right;
    BOOL click_wheel;
} MouseState;



DWORD WINAPI MainLoopThread( LPVOID arg );
BOOL updateMouseState( MouseState m );

#endif /* MAIN_LOOP_THREAD_H_ */
