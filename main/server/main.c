#include <windows.h>



#include "debug.h"
#include "main_loop_thread.h"
#include "graphics_thread.h"
#include "data_sync_thread.h"

#define MAX_TARGET_NUM 32
#define MAX_BULLET_NUM 64
#define TOTAL_OBJECT_NUM ( MAX_TARGET_NUM + MAX_BULLET_NUM + 2 )

typedef struct _COMMON_OBJECT_
{
    BOOL isExist;
    BOOL isChanging;
    DWORD x;
    DWORD y;
    size_t size_x;
    size_t size_y;
    int type;
} CommonObject;

CommonObject self, enemy;
CommonObject target[ MAX_TARGET_NUM ];
CommonObject bullet[ MAX_BULLET_NUM ];

BOOL end_program = FALSE;
int point_self = 0, point_enemy = 0;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    //各スレッドのIDを作成
    DWORD MainLoopThreadId, GraphicsThreadId, DataSyncThreadId;

    //グラフィックススレッド起動
    HANDLE GraphicsThreadHandle = CreateThread(
        NULL, //セキュリティ属性
        0, //スタックサイズ
        GraphicsThread, //スレッド関数本体
        NULL, //スレッド関数に渡す引数
        0, //作成オプション(0またはCREATE_SUSPENDED)
        &GraphicsThreadId //スレッドID
    );
    //通信スレッド起動
    HANDLE DataSyncThreadHandle = CreateThread(
        NULL, //セキュリティ属性
        0, //スタックサイズ
        DataSyncThread, //スレッド関数本体
        NULL, //スレッド関数に渡す引数
        0, //作成オプション(0またはCREATE_SUSPENDED)
        &DataSyncThreadId //スレッドID
    );
    //メインスレッド起動
    HANDLE MainLoopThreadHandle = CreateThread(
        NULL, //セキュリティ属性
        0, //スタックサイズ
        MainLoopThread, //スレッド関数本体
        NULL, //スレッド関数に渡す引数
        0, //作成オプション(0またはCREATE_SUSPENDED)
        &MainLoopThreadId //スレッドID
    );

    //各スレッド起動確認
    if( GraphicsThreadHandle == NULL )
    {
        printErrorMessage( "main.c", "CreateThread()" );
        end_program = TRUE;
    }
    if( DataSyncThreadHandle == NULL )
    {
        printErrorMessage( "main.c", "CreateThread()" );
        end_program = TRUE;
    }
    if( MainLoopThreadHandle == NULL )
    {
        printErrorMessage( "main.c", "CreateThread()" );
        end_program = TRUE;
    }

    //プログラム終了まで待機
    while( end_program == FALSE )
    {
        Sleep(10);
    }

    //各スレッド終了
    SuspendThread( MainLoopThreadHandle );
    SuspendThread( GraphicsThreadHandle );
    SuspendThread( DataSyncThreadHandle );
    CloseHandle( MainLoopThreadHandle );
    CloseHandle( GraphicsThreadHandle );
    CloseHandle( DataSyncThreadHandle );

    return 0;
}
