#include <stdio.h>
#include <winsock2.h>

int main( void )
{
	char name[256];
	WSADATA wsad;
	struct hostent *hs;
	struct in_addr addr;
	int i;

	if( WSAStartup(0x0101, &wsad))
	{
		return 1;
	}
	gethostname(name,sizeof(name));
	hs = gethostbyname(name);

	printf( "host name = %s\n", hs->h_name);
	if( hs->h_aliases)
	{
		for( i = 0; hs->h_aliases[i]; i++ )
		{
			printf( "%s\n", hs->h_aliases[i]);
		}
	}
	printf( "ip address = ");
	if( hs->h_addr_list)
	{
		for( i = 0; hs->h_addr_list[i]; i++ )
		{
			addr.S_un.S_addr = *(u_long*)hs->h_addr_list[i];
			printf( " %s\n", inet_ntoa(addr));
		}
	}

	WSACleanup();

	return 0;
}
