#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winsock2.h>

int main( void )
{
	//各変数を宣言
	char host_name[256];
	char self_address[16];
	char pair_address[16];
	
	struct WSAData wsaData;
	SOCKET sock;
	struct sockaddr_in addr;
	struct in_addr local_addr;
	int len;
	BOOL yes = 1;
	char buf[1024];
	char send_data[2] = { 123, 123 };
	
	//初期化
	WSAStartup( MAKEWORD( 2, 0 ), &wsaData );
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons( 2021 ); //ポート2021を使用 参照: https://ja.wikipedia.org/wiki/TCPやUDPにおけるポート番号の一覧
	
	
	//自分のローカルIPアドレスを取得
	gethostname( host_name, sizeof( host_name ) ); //実行しているパソコンの名前を取得
	local_addr.S_un.S_addr = *( u_long *)gethostbyname( host_name )->h_addr_list[0];
	
	strcpy( self_address, inet_ntoa( local_addr ) ); //パソコンの名前からローカルIPアドレスを取得
	
	
	//サーバーに自分のIPアドレスを送信
	sock = socket( AF_INET, SOCK_DGRAM, 0 ); //UDP受信用ソケット作成
	addr.sin_addr.S_un.S_addr = inet_addr( "255.255.255.255" ); //ブロードキャストアドレスを指定
	
	setsockopt( sock, SOL_SOCKET, SO_BROADCAST, ( char *)&yes, sizeof( yes ) );
	sendto( sock, self_address, 16, 0, ( struct sockaddr *)&addr, sizeof( addr ) );
	
	closesocket( sock ); //UDPのソケットを閉じる
	
	
	//サーバーのIPアドレスを受信
	sock = socket( AF_INET, SOCK_DGRAM, 0 ); //UDP受信用ソケット作成
	addr.sin_addr.S_un.S_addr = INADDR_ANY; //ブロードキャストの受信用に設定
	
	bind( sock, ( struct sockaddr *)&addr, sizeof( addr ) );
	
	memset( pair_address, 0, sizeof( pair_address ) );
	recv( sock, pair_address, sizeof( pair_address ), 0 );
	
	closesocket( sock ); //UDPのソケットを閉じる
	
	
	//TCPでデータを受信する
	sock = socket( AF_INET, SOCK_STREAM, 0 ); //TCP受信用ソケット作成
	addr.sin_addr.S_un.S_addr = inet_addr( pair_address ); //送信策を指定
	
	connect( sock, ( struct sockaddr *)&addr, sizeof( addr ) );
	
	while( TRUE )
	{
		memset( buf, 0, sizeof( buf ) );
		recv( sock, buf, sizeof( buf ), 0 );
		send( sock, send_data, sizeof( send_data ), 0 );
		
		printf( "%d, %d\n", buf[0], buf[1] );
	}
	
	closesocket( sock );
	
	WSACleanup();
	
	return 0;
}

