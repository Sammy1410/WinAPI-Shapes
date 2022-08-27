#include <includes.h>

//Controlled by Window Thread

//Sets values to MainWindow Class, registers it and creates a window
//Finally it shows the window in the screen
int _InitializeWindow(HINSTANCE _thisInstance,int _ConsoleShowing){
    MainWindowClass.lpfnWndProc = MainHandleMsg;
    MainWindowClass.hInstance=_thisInstance;
    MainWindowClass.lpszClassName=CLASS_NAME;

    RegisterClass(&MainWindowClass);


    MainHandle = CreateWindowEx(
        0,
        CLASS_NAME,
        AppHeader,
        WS_OVERLAPPEDWINDOW | WS_MAXIMIZE,
        windowDefault.xPos,
        windowDefault.yPos,
        windowDefault.width,
        windowDefault.height,
        NULL,
        NULL,
        _thisInstance,
        NULL
    );

    if(MainHandle == NULL){
        return 0;
    }
    ShowWindow(MainHandle,_ConsoleShowing);
    return 1;
}