#ifndef DEBUG_H_
#define DEBUG_H_

#include <windows.h>
#include <string.h>

void printErrorMessage( char* file_name, char* error_type )
{
    char message[1024] = "�v���O�����̎��s���ɃG���[���������܂���\n";

    strcat( message, "�t�@�C���� : ");
    strcat( message, file_name );
    strcat( message, "\n" );
    strcat( message, "�G���[�ӏ� : " );
    strcat( message, error_type );

    MessageBox( NULL, TEXT( message ), TEXT( "���s���G���["), MB_ICONERROR );
}

/*
������F

#include <windows.h>
#include <string.h>

#include "debug.h" �����̃t�@�C���̖��O(��)

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	if( displayInit() == FALSE )
	{
		printErrorMessage( "main.c", "displayInit()" );
	}
	
	return 0;
}

*/

