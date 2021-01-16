#ifndef DATA_SYNC_THREAD_H_
#define DATA_SYNC_THREAD_H_

#include <windows.h>
#include <winsock2.h>

#include "object.h"
#include "debug.h"

DWORD WINAPI DataSyncThread( LPVOID arg );

#endif /* DATA_SYNC_THREAD_H_ */
