#include <stdio.h>
#include <winsock2.h>

int main( void )
{
	char name[256];
	WSADATA wsad;
	struct in_addr addr;

	WSAStartup(0x0101, &wsad);

	gethostname(name,sizeof(name));
	addr.S_un.S_addr = *(u_long*)gethostbyname(name)->h_addr_list[0];
	WSACleanup();

	printf( "ip address = %s\n", inet_ntoa(addr));

	return 0;
}
