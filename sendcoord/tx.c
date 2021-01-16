#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winsock2.h>

int main( void )
{
	//�e�ϐ���錾
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
	
	//������
	WSAStartup( MAKEWORD( 2, 0 ), &wsaData );
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons( 2021 ); //�|�[�g2021���g�p �Q��: https://ja.wikipedia.org/wiki/TCP��UDP�ɂ�����|�[�g�ԍ��̈ꗗ
	
	
	//�����̃��[�J��IP�A�h���X���擾
	gethostname( host_name, sizeof( host_name ) ); //���s���Ă���p�\�R���̖��O���擾
	local_addr.S_un.S_addr = *( u_long *)gethostbyname( host_name )->h_addr_list[0];
	
	strcpy( self_address, inet_ntoa( local_addr ) ); //�p�\�R���̖��O���烍�[�J��IP�A�h���X���擾
	
	
	//�T�[�o�[�Ɏ�����IP�A�h���X�𑗐M
	sock = socket( AF_INET, SOCK_DGRAM, 0 ); //UDP��M�p�\�P�b�g�쐬
	addr.sin_addr.S_un.S_addr = inet_addr( "255.255.255.255" ); //�u���[�h�L���X�g�A�h���X���w��
	
	setsockopt( sock, SOL_SOCKET, SO_BROADCAST, ( char *)&yes, sizeof( yes ) );
	sendto( sock, self_address, 16, 0, ( struct sockaddr *)&addr, sizeof( addr ) );
	
	closesocket( sock ); //UDP�̃\�P�b�g�����
	
	
	//�T�[�o�[��IP�A�h���X����M
	sock = socket( AF_INET, SOCK_DGRAM, 0 ); //UDP��M�p�\�P�b�g�쐬
	addr.sin_addr.S_un.S_addr = INADDR_ANY; //�u���[�h�L���X�g�̎�M�p�ɐݒ�
	
	bind( sock, ( struct sockaddr *)&addr, sizeof( addr ) );
	
	memset( pair_address, 0, sizeof( pair_address ) );
	recv( sock, pair_address, sizeof( pair_address ), 0 );
	
	closesocket( sock ); //UDP�̃\�P�b�g�����
	
	
	//TCP�Ńf�[�^����M����
	sock = socket( AF_INET, SOCK_STREAM, 0 ); //TCP��M�p�\�P�b�g�쐬
	addr.sin_addr.S_un.S_addr = inet_addr( pair_address ); //���M����w��
	
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

