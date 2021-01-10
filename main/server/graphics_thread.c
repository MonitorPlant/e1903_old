#include <windows.h>

#include "debug.h"
#include "graphics_thread.h"

DWORD WINAPI GraphicsThread( LPVOID arg )
{
    if( displayInit() == FALSE )
    {
        end_program = TRUE;
        printErrorMessage( "main.c", "displayInit()" );
        return -1;
    }

    while( true )
    {
        displayUpdate();
        Sleep(1);
    }

    return 0;
}