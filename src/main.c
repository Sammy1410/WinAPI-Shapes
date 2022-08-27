#ifndef UNICODE
#define UNICODE
#endif
//#define _WIN32_WINNT  0x0500

#include <includes.h>

#include "graphic.c"
#include "initialize.c"
#include "default.c"
#include "functions.c"
#include "WinAPI.c"
#include "threads.c"



int WINAPI WinMain(HINSTANCE thisInstance,HINSTANCE prevInstance,PSTR _pCmdLine,int _ConsoleShowing){

    //Threads needed are defined    
    pthread_t WinThread,WorkThread0,TimerThread,InputThread;

    //The value of main Window are global so it is sent from these local variables in WinMain
    MainInstance = thisInstance;
    prevMainInstance = prevInstance;
    pCmdLine = _pCmdLine;
    ConsoleShowing = _ConsoleShowing;
    
    //Default info for the application is set here
    SetDefaults();

    //Threads initialized and connected to respective main functions
    pthread_create(&WinThread,NULL,WindowThread,NULL);
    pthread_create(&WorkThread0,NULL,WorkerThread,NULL);
    pthread_create(&TimerThread,NULL,TimerThreadFunc,NULL);
    pthread_create(&InputThread,NULL,InputThreadFunc,NULL);

    
    //Windows Rectangle's blank layer is defined
    //Memory is allocated to the buffers 0 and 1
    WinRectArray=(uint32_t *)malloc(windowDefault.width*windowDefault.height*sizeof(uint32_t));
    WinBuffer0=(uint32_t *)malloc(windowDefault.width*windowDefault.height*sizeof(uint32_t));
    //WinBuffer1=(uint32_t *)malloc(windowDefault.width*windowDefault.height*sizeof(uint32_t));

    //defaultDC=GetDC(MainHandle);
    //Blank Layer is set to contain default windows color
    for (int i=0;i<(windowDefault.width*windowDefault.height);i++){
        WinRectArray[i]=Wincolor;
        WinBuffer0[i]=Wincolor;
        //WinBuffer1[i]=Wincolor;
    }

    //and then declared as bitmap
    WinRect=CreateBitmap(windowDefault.width,windowDefault.height,1,sizeof(COLORREF)*8,(void*)WinRectArray);
    
    BufferBMP0=CreateBitmap(windowDefault.width,windowDefault.height,1,sizeof(COLORREF)*8,(void*)WinBuffer0);
    //BufferBMP1=CreateBitmap(windowDefault.width,windowDefault.height,1,sizeof(COLORREF)*8,(void*)WinBuffer1);
    
    WinRectMemDC= CreateCompatibleDC(DeviceContext);
    BufferMem0= CreateCompatibleDC(DeviceContext);
    //BufferMem1= CreateCompatibleDC(DeviceContext); 

    WindowInitialized=1; 
    while(!(WindowThreadDone && TimerInitialized)){ }



    /*static int m=0;
    static int j=0;
    do{ 
        
        fprintf(msg_logs,"%s :: m = %d\n",time_str,m++);
        if(j==4){
            //printf("White Blue\n");
            for (int i=0;i<(windowDefault.width*windowDefault.height);i++){
                WinBuffer0[i]=green;
                WinBuffer1[i]=Wincolor;
            }
            j=0;
        }else if(j==2){
            //printf("Green Red\n");
            for (int i=0;i<(windowDefault.width*windowDefault.height);i++){
                WinBuffer0[i]=red;
                WinBuffer1[i]=blue;
            }   
        }
        DeviceContext=GetDC(MainHandle);
        BufferBMP0=CreateBitmap(windowDefault.width,windowDefault.height,1,sizeof(COLORREF)*8,(void*)WinBuffer0);
        BufferBMP1=CreateBitmap(windowDefault.width,windowDefault.height,1,sizeof(COLORREF)*8,(void*)WinBuffer1);
    
        BufferMem0= CreateCompatibleDC(DeviceContext);
        BufferMem1= CreateCompatibleDC(DeviceContext); 
        
        
        SelectObject(WinRectMemDC,WinRect);
        BitBlt(DeviceContext,0,0,windowDefault.width,windowDefault.height,WinRectMemDC,0,0,SRCCOPY);


        switch (LastBufferSet){
            case 0:
                SelectObject(BufferMem1,BufferBMP1);
                BitBlt(DeviceContext,0,0,windowDefault.width,windowDefault.height,BufferMem1,0,0,SRCCOPY);
                //printf("Painted 1\n");
                LastBufferSet=1;
                BufShown1=0;
                break;
            case 1:
                SelectObject(BufferMem0,BufferBMP0);
                BitBlt(DeviceContext,0,0,windowDefault.width,windowDefault.height,BufferMem0,0,0,SRCCOPY);
                //printf("Painted 0\n");
                LastBufferSet=0;
                BufShown0=0;
                break;
        }    
        j++; 
        ReleaseDC(MainHandle,DeviceContext); 
    }while(WindowOn);
    */

    do{
        
        while(!WorkerThreadDone){}
        DeviceContext=GetDC(MainHandle);
        BufferBMP0=CreateBitmap(windowDefault.width,windowDefault.height,1,sizeof(COLORREF)*8,(void*)WinBuffer0);
        BufferMem0= CreateCompatibleDC(DeviceContext);
        SelectObject(BufferMem0,BufferBMP0);
        BitBlt(DeviceContext,0,0,windowDefault.width,windowDefault.height,BufferMem0,0,0,SRCCOPY);
        //Sleep(1);
        WorkerThreadDone=0;
        for (int i=0;i<(windowDefault.width*windowDefault.height);i++){
             WinBuffer0[i]=Wincolor;
        }
        DeleteObject(BufferBMP0);
        DeleteDC(BufferMem0);
        ReleaseDC(MainHandle,DeviceContext);
        MainThreadDone=1;
       
        
    }while(WindowOn);
    
    DeleteDC(WinRectMemDC);
    free(WinRectArray);
    free(WinBuffer0);
    free(WinBuffer1);
    

    
    //pthread_join(thread_id1,NULL);
    
    _exit(0);
}