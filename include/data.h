#ifndef FILE_DATA_SEEN
#define FILE_DATA_SEEN

#include <includes.h>

#define KEY_DOWN(vk_code)  ((GetAsyncKeyState(vk_code))&0x8000 ? 1:0)
static int preState=0x30;
int KeyState[101];




BOOL isHoldingKeyDown;

POINT mouse;
BOOL mouseLdown=0;

time_t t;


BOOL TimerInitialized=0;
BOOL WorkerThreadDone=0;
BOOL MainThreadDone=0;

typedef struct _FCOORD{
    float X;
    float Y;
}FCOORD,*PFCOORD;

char * time_str;

//std::fstream err_logs,warn_logs,msg_logs;
FILE *err_logs,*warn_logs,*msg_logs,*tr_logs;

#endif