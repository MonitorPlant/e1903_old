#ifndef TIMER_H_
#define TIMER_H_

#include <windows.h>
#include <stdlib.h>

#define HTIMER DWORD*

void setTimer( HTIMER hTimer );
DWORD passedTime( HTIMER hTimer );
void releaseTimer( HTIMER hTimer );

#endif /* TIMER_H_ */
