#ifndef OBJECT_H_
#define OBJECT_H_

#define MAX_TARGET_NUM 32
#define MAX_BULLET_NUM 64
#define TOTAL_OBJECT_NUM ( MAX_TARGET_NUM + MAX_BULLET_NUM + 2 )

typedef struct _COMMON_OBJECT_
{
    BOOL isExist;
    BOOL isChanging;
    DWORD x;
    DWORD y;
    char type;
    int** design;
    size_t size_x;
    size_t size_y;
} CommonObject;

typedef struct _MOUSE_STATE_
{
    BOOL click_left;
    BOOL click_right;
    BOOL click_wheel;
} MouseState;

#endif /* OBJECT_H_ */
