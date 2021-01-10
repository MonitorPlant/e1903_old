#ifndef DEBUG_H_
#define DEBUG_H_

#include <windows.h>
#include <string.h>

void printErrorMessage( char* file_name, char* error_type )
{
    char message[1024] = "プログラムの実行中にエラーが発生しました\n";

    strcat( message, "ファイル名 : ");
    strcat( message, file_name );
    strcat( message, "\n" );
    strcat( message, "エラー箇所 : " );
    strcat( message, error_type );

    MessageBox( NULL, TEXT( message ), TEXT( "実行時エラー"), MB_ICONERROR );
}

/*
実装例：

#include <windows.h>
#include <string.h>

#include "debug.h" ←このファイルの名前(仮)

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	if( displayInit() == FALSE )
	{
		printErrorMessage( "main.c", "displayInit()" );
	}
	
	return 0;
}

*/

