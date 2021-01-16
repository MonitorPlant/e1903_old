#include <stdio.h>
#include <windows.h>
#include <winsock2.h>

char self_address[16] = "192.168.0.8";
char pair_address[16] = "192.168.0.8";

char send_data[2];

int main( void )
{
	WSADATA wsaData;
	SOCKET sock;
	struct sockaddr_in addr;
	int len;
	POINT pt;

	// winsock2の初期化
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	// ソケットの作成
	sock = socket(AF_INET, SOCK_STREAM, 0);

	// ソケットの設定
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(sock, (struct sockaddr *)&addr, sizeof(addr));

	// TCPクライアントからの接続要求を待てる状態にする
	listen(sock, 5);

	// TCPクライアントからの接続要求を受け付ける
	len = sizeof(addr);
	sock = accept(sock, (struct sockaddr *)&addr, &len);
	
	while( TRUE )
	{
		GetCursorPos(&pt);
		
		send_data[0] = pt.x / 8 - 127;
		send_data[1] = pt.y / 16;
		
		send( sock, send_data, sizeof(send_data), 0 );
		
		Sleep( 15 );
	}

	// TCPセッションの終了
	closesocket(sock);

	// winsock2の終了処理
	WSACleanup();
	
	return 0;
}
