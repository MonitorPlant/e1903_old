#include <windows.h>
#include <string.h>
#include <stdio.h>

int count = 0;

//�X���b�h�֐�
DWORD WINAPI ThreadFunc(LPVOID arg)
{
	char output[1024];
	int i;
	for (i = 0; i < 3; i++) {
		sprintf( output, "%d", count++ );
		MessageBox( NULL, TEXT( output ), TEXT( "�X���b�h�֐�" ), MB_ICONERROR );
	}
	return 0;
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	HANDLE hThread;
	DWORD dwThreadId;
	char output[1024];

	//�X���b�h�N��
	hThread = CreateThread(
		NULL, //�Z�L�����e�B����
		0, //�X�^�b�N�T�C�Y
		ThreadFunc, //�X���b�h�֐�
		NULL, //�X���b�h�֐��ɓn������
		0, //�쐬�I�v�V����(0�܂���CREATE_SUSPENDED)
		&dwThreadId);//�X���b�hID

	Sleep(300);

	//�X���b�h���~
	SuspendThread(hThread);

	Sleep(300);
	
	//�X���b�h���ĊJ
	ResumeThread(hThread);
	
	for( int i = 0; i < 3; i++ )
	{
		sprintf( output, "%d", count++ );
		MessageBox( NULL, TEXT( output ), TEXT( "���C���֐�" ), MB_ICONERROR );
	}

	//�X���b�h�̏I����҂�
	WaitForSingleObject(hThread, INFINITE);

	//�X���b�h�̃n���h�������
	CloseHandle(hThread);

	return 0;
}