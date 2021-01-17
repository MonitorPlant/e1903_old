#ifndef MAIN_LOOP_THREAD_H_
#define MAIN_LOOP_THREAD_H_

#include <windows.h>
#include <stdlib.h>

#include "../common/object.h"
#include "debug.h"

#define HTIMER DWORD*

DWORD WINAPI MainLoopThread( LPVOID arg ); //ゲーム処理用スレッド

void updateMouseState( void ); //マウスの状態を更新
void setTimer( HTIMER hTimer );
DWORD passedTime( HTIMER hTimer );
void releaseTimer( HTIMER hTimer );

#endif /* MAIN_LOOP_THREAD_H_ */
