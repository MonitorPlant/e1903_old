#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winsock2.h>

void getPairAddress( char* address );
void getSelfAddress( char* address );
void sendSelfAddress( char* address );

int main( void )
{
	char self_address[16];
	char pair_address[16];
	
	getSelfAddress( self_address );
	getPairAddress( pair_address );
	
	Sleep( 50 );
	
	sendSelfAddress( self_address );
	
	printf( "self_address = %s\n", self_address );
	printf( "pair_address = %s\n", pair_address );
	
	//MessageBox( NULL, TEXT(pair_address), TEXT(self_address), MB_ICONINFORMATION );
	
	return 0;
}

void getPairAddress( char* address )
{
	struct WSAData wsaData;
	
	SOCKET sock;
	struct sockaddr_in addr;
	char buf[16];
	
	WSAStartup( MAKEWORD(2,0), &wsaData);
	
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2021);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	
	bind( sock, (struct sockaddr *)&addr, sizeof(addr));
	
	memset( buf, 0, sizeof(buf) );
	recv(sock, buf, sizeof(buf), 0);
	
	strcpy( address, buf );
	
	closesocket(sock);
	
	WSACleanup();
}

void getSelfAddress( char* address )
{
	char name[256];
	WSADATA wsad;
	struct in_addr addr;
	
	WSAStartup(0x0101, &wsad);
	
	gethostname( name, sizeof(name));
	addr.S_un.S_addr = *(u_long*)gethostbyname(name)->h_addr_list[0];
	
	strcpy( address, inet_ntoa(addr) );
	
	WSACleanup();
}

void sendSelfAddress( char* address )
{
	struct WSAData wsaData;
	
	SOCKET sock;
	struct sockaddr_in addr;
	BOOL yes = 1;
	
	WSAStartup( MAKEWORD(2,0), &wsaData);
	
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2021);
	addr.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");
	
	setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *)&yes, sizeof(yes));
	sendto(sock, address, 16, 0, (struct sockaddr *)&addr, sizeof(addr));
	
	closesocket( sock );
	
	WSACleanup();
}
