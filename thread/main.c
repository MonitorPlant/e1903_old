#include <process.h>
#include <windows.h>
#include <stdio.h>

// �X���b�h�֐�
unsigned int func(void *x)
{
    for(int i = 0; i < 10; ++i){
        printf( "thread %d\n", *((int*)(x)) );
    }
    _endthreadex(0);
    return 0;
}
 
int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance ,PSTR lpCmdLine , int nCmdShow) {
    HANDLE handle;
    int x = 1;
    printf( "init\n" );
 
    // �X���b�h���J�n
    handle = (HANDLE)_beginthreadex(NULL, 0, (unsigned int (__stdcall*)(void*))func, &x, 0, NULL);
 
    for( int i = 0; i < 10; i++ ){
         printf( "thread 0\n" );
    }
 
    // �X���b�h�I����҂�
    WaitForSingleObject(handle, INFINITE);
 
    // �n���h�������
    CloseHandle(handle);
 
    return 0;
}

