#include <stdio.h>
#include <windows.h>
#include <winsock2.h>

char self_address[16] = "192.168.0.8";
char pair_address[16] = "192.168.0.8";

int main( void )
{
	char num = 236 - 127;
	printf( "%d\n", num );
	
	WSADATA wsaData;
	SOCKET sock0;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	int len;
	SOCKET sock;

	// winsock2�̏�����
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	// �\�P�b�g�̍쐬
	sock0 = socket(AF_INET, SOCK_STREAM, 0);

	// �\�P�b�g�̐ݒ�
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

	// TCP�N���C�A���g����̐ڑ��v����҂Ă��Ԃɂ���
	listen(sock0, 5);

	// TCP�N���C�A���g����̐ڑ��v�����󂯕t����
	len = sizeof(client);
	sock = accept(sock0, (struct sockaddr *)&client, &len);

	// 5�������M
	send(sock, "HELLO", 5, 0);

	// TCP�Z�b�V�����̏I��
	closesocket(sock);

	// winsock2�̏I������
	WSACleanup();
	
	return 0;
}