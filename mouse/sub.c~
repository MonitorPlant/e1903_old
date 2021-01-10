#include<windows.h>
#include<stdio.h>

typedef struct _MOUSE_STATE_ {
    int x;
    int y;
    int click_left;
    int click_right;
    int click_wheel;
} mouse;

void updateState( mouse m ) {
        GetCursorPos(&m);
        if(m.x > 959) {
            m.x = 959;
            SetCursorPos(m.x, m.y);
        }
        m.click_left = (GetKeyState(VK_LBUTTON)  >> 15) & 1;
        m.click_right = (GetKeyState(VK_RBUTTON) >> 15) & 1;
        m.click_wheel = (GetKeyState(VK_MBUTTON) >> 15) & 1;
}

int main() {
    mouse state;
    while(TRUE) {
        updateState( state );
        printf("%d,%d,%d,%d,%d\n", state.x, state.y, state.click_left, state.click_right, state.click_wheel);
        Sleep(1);
    }
}
