#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct _MOUSE_STATE_ {
    int x;
    int y;
    int click_left;
    int click_right;
    int click_wheel;
} mouse;

mouse updateState(int left_or_right) {
        mouse m;
        POINT pt;
        GetCursorPos(&pt);
        if(left_or_right) {
            if(pt.x < 960) {
                pt.x = 960;
                SetCursorPos(pt.x, pt.y);
            }
        } else {
            if(pt.x > 959) {
                pt.x = 959;
                SetCursorPos(pt.x, pt.y);
            }
        }
        m.x = pt.x;
        m.y = pt.y;
        m.click_left = (GetKeyState(VK_LBUTTON)  >> 15) & 1;
        m.click_right = (GetKeyState(VK_RBUTTON) >> 15) & 1;
        m.click_wheel = (GetKeyState(VK_MBUTTON) >> 15) & 1;
        return m;
}

int main() {
	DWORD* in;
	in = (DWORD*)malloc( sizeof( DWORD ) );
	
	*in = 13;
	
	printf( "%lu\n", *in );
	//return 0;
    while(TRUE) {
        mouse m = updateState(0);
        printf("%d,%d,%d,%d,%d\n", m.x, m.y, m.click_left, m.click_right, m.click_wheel);
        if( m.click_left == 1 )
        {
        	exit( 0 );
        }
        Sleep(1);
    }
}
