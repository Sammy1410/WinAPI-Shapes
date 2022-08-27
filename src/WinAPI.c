#include <includes.h>

//Window Procedure for Main Application Window
/*
This only sends message back to Windows Thread
*/
LRESULT CALLBACK MainHandleMsg(HWND _MainHandle,UINT uMsg,WPARAM wParam,LPARAM lparam){
    switch(uMsg){
        case WM_LBUTTONDOWN:
            //Sleep(100);
          mouseLdown=1;
         // printf("Mouse clicked\n");
          break;
        case WM_LBUTTONUP:
          mouseLdown=0;
          //printf("Mouse Not clicked\n");
          break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_QUIT:
            _exit(0);
        case WM_CLOSE:
            _exit(0);
    }
    return DefWindowProc(_MainHandle,uMsg, wParam, lparam);
}
