#include <Windows.h>
#include <iostream>
  
static DWORD g_NowTime = 0;
static DWORD g_StartTime = 0;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) 
{
	char message[1024] = "";
    g_StartTime = GetTickCount();
    // ‘ª’è‹æŠÔ
    g_NowTime = GetTickCount();
  
    std::cout << std::fixed << (g_NowTime - g_StartTime) / 1000.0 << "•b" << std::endl;
    MessageBox( NULL, TEXT(
	
	return 0;
}
