#include <windows.h>
#include <string.h>
#include <stdio.h>

int count = 0;

//スレッド関数
DWORD WINAPI ThreadFunc(LPVOID arg)
{
	char output[1024];
	int i;
	for (i = 0; i < 3; i++) {
		sprintf( output, "%d", count++ );
		MessageBox( NULL, TEXT( output ), TEXT( "スレッド関数" ), MB_ICONERROR );
	}
	return 0;
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	HANDLE hThread;
	DWORD dwThreadId;
	char output[1024];

	//スレッド起動
	hThread = CreateThread(
		NULL, //セキュリティ属性
		0, //スタックサイズ
		ThreadFunc, //スレッド関数
		NULL, //スレッド関数に渡す引数
		0, //作成オプション(0またはCREATE_SUSPENDED)
		&dwThreadId);//スレッドID

	Sleep(300);

	//スレッドを停止
	SuspendThread(hThread);

	Sleep(300);
	
	//スレッドを再開
	ResumeThread(hThread);
	
	for( int i = 0; i < 3; i++ )
	{
		sprintf( output, "%d", count++ );
		MessageBox( NULL, TEXT( output ), TEXT( "メイン関数" ), MB_ICONERROR );
	}

	//スレッドの終了を待つ
	WaitForSingleObject(hThread, INFINITE);

	//スレッドのハンドルを閉じる
	CloseHandle(hThread);

	return 0;
}