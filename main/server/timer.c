#include <windows.h>
#include <stdlib.h>

#include "debug.h"
#include "timer.h"

void setTimer( HTIMER hTimer )
{
    //タイマー用変数のメモリ領域を確保
    hTimer = (HTIMER)malloc( sizeof( DWORD ) );

    if( hTimer == NULL )
    {
        printErrorMessage( "timer.c", "malloc()" );
    }

    //タイマーの開始時間を記録
    *hTimer = GetTickCount();
}

DWORD passedTime( HTIMER hTimer )
{
    //setTimer()した時からの経過時間
    return GetTickCount() - *hTimer;
}

void releaseTimer( HTIMER hTimer )
{
    //タイマー用変数のメモリ領域を解放
    free( hTimer );
}
