#include <stdio.h>
#include <windows.h>
#include <winsock2.h>

int main( void )
{
	WSADATA wsaData;
	struct sockaddr_in server;
	SOCKET sock;
	char buf[32];

	// winsock2�̏�����
	WSAStartup(MAKEWORD(2,0), &wsaData);

	// �\�P�b�g�̍쐬
	sock = socket(AF_INET, SOCK_STREAM, 0);

	// �ڑ���w��p�\���̂̏���
	server.sin_family = AF_INET;
	server.sin_port = htons(12345);
	server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	// �T�[�o�ɐڑ�
	connect(sock, (struct sockaddr *)&server, sizeof(server));
	
	while( TRUE )
	{
		// �T�[�o����f�[�^����M
		memset(buf, 0, sizeof(buf));
		int n = recv(sock, buf, sizeof(buf), 0);

		printf("%d, %d\n", buf[0], buf[1]);
		
		Sleep(1);
	}

	// winsock2�̏I������
	WSACleanup();
	
	return 0;
}
