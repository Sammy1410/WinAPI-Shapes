#include <includes.h>

void *WorkerThread(void *vargp){
    while(!WindowThreadDone && !WindowInitialized){ }
    
    static int framelast=0;
    static int framenow=0;
    int _timenow=time(NULL);
    int _timelast=_timenow;


    
    

    

    int LastKeyPressed;
    int NewKeyPressed=preState;

    float newradius=50;
    

    line l1d;

    

    int sides=5;
    polyP poy=(polyP)malloc(sizeof(polyP)+sides*sizeof(FCOORD)+sides*sizeof(COLORREF));
    
    poy->points=(FCOORD *)(((char *)poy)+sizeof(polyP));
    poy->color=(COLORREF *)(((char *)poy)+sizeof(polyP)+sides*sizeof(FCOORD));
 


    poy->points[0].X=100.00f;
/*    poy->points[0].Y=20;
    poy->points[1]={10,20};
    poy->points[2]={10,20};
    poy->points[3]={10,20};
    poy->points[4]={10,20};
    */
    poy->color[0]=shadow;
    /*poy->color[1]=blue;
    poy->color[2]=red;
    poy->color[3]=blue;
    poy->color[4]=green;
    */
   
    l1d.start.X=10;
    l1d.start.Y=10;
    l1d.end.X=500;
    l1d.end.Y=40;
    l1d.width=1;
    l1d.color=red;
    //l1d.width=20;

    circle C1_data;
    rect R1_data;
    
    R1_data.start.X=10;
    R1_data.start.Y=10;
    R1_data.end.X=50;
    R1_data.end.Y=50;
    R1_data.color=blue;


    do{
        
        /*for(int i=0;i<100;i++){
            CanvasDraw(i,i,blue);
        }
        */
       //Poly_Create(poy);
       Line_Create(l1d);
            
       Rect_Create(R1_data);
        
        /*
            if(KEY_DOWN('w') || KEY_DOWN('W')){
                LastKeyPressed='W';
                posStartY-=speed;
            }
                
            if(KEY_DOWN('s') || KEY_DOWN('S')){
                LastKeyPressed='S';
                posStartY+=speed;
            }
                
            if(KEY_DOWN('a') || KEY_DOWN('A')){
                LastKeyPressed='A';
                posStartX-=speed;
            }
                
            if(KEY_DOWN('d') || KEY_DOWN('D')){
                LastKeyPressed='D';
                posStartX+=speed;
            }
                
            if(KEY_DOWN('q') || KEY_DOWN('Q')){
                newradius+=0.25;
            }
          
            if(KEY_DOWN('e') || KEY_DOWN('E')){
                if(newradius!=0)
                    newradius-=0.25;
            }

            if(KEY_DOWN('f') || KEY_DOWN('F')){
                speed=1;
                acceleration=0.01f;
                //posStartX=50;posStartY=50;radius=50;
            }
            
            /*
            if(NewKeyPressed==LastKeyPressed){
                speed+=acceleration;
            }else{
                speed =1;
            }*/
            NewKeyPressed=LastKeyPressed;

        
        WorkerThreadDone=1; 
        while(!MainThreadDone){}
        MainThreadDone=0;   
       
        framenow++;
        _timenow=time(NULL);
        if(_timenow-_timelast>=1){
            fprintf(msg_logs,"%s :: FPS = %d \n",time_str,framenow-framelast);
            printf("%d %d %d\n",poy,poy->points,poy->color);
            printf("FPS = %d\n",framenow-framelast);
            framelast=framenow;
            _timelast=_timenow;
        }
        
    }while(1);

    
}

void *InputThreadFunc(void *vargp){

    while(!(WindowInitialized && TimerInitialized)){ }
    

    
    for(int i=preState;i<=0x5A;i++)
        KeyState[i-0x30]=0;   

    circle Circle;
    Circle.radius=5;
    Circle.color=blue;
    while(1){
        
        GetCursorPos(&mouse);
        ScreenToClient(MainHandle, &mouse);
        Circle.center.X=(float)mouse.x;
        Circle.center.Y=(float)mouse.y;
        Circle_Create(Circle);
        //printf("mouse.X= %d,mouse.Y= %d \n",mouse.x,mouse.y);
         for(int x=preState;x<=0x5A;x++){
            //for(auto x=0x30;x<=0x5A;x++){
                switch(x){
                    case 0x40:
                    case 0x5E:          /*The hex numbers are reserved and so need not be checked*/
                        continue;
                }

                if(KEY_DOWN(x)){
                    KeyState[x-0x30]=1;   
                   // printf("Pressed %c\n",x);
                }else{
                    KeyState[x-0x30]=0;   
                }
            }
        
    }
        
}

void *WindowThread(void *vargp){

    int checkWindow;
    err_logs=fopen("F:\\Codes\\Windows\\Application\\logs\\error_logs.txt","a");
    msg_logs=fopen("F:\\Codes\\Windows\\Application\\logs\\message_logs.txt","a");
    warn_logs=fopen("F:\\Codes\\Windows\\Application\\logs\\warn_logs.txt","a");
    tr_logs=fopen("F:\\Codes\\Windows\\Application\\logs\\trial_logs.txt","w");

    while(!(WindowInitialized && TimerInitialized)){ }

    checkWindow=_InitializeWindow(MainInstance,ConsoleShowing);

    switch(checkWindow){
        case 0:
            fprintf(err_logs,"%sFailed To Initialize Window",ctime(&t));
            break;
        case 1:
            fprintf(msg_logs,"________________________________________________________________\n\n");
            fprintf(msg_logs,"%s :: Window Initialized\n\n",time_str);
            break;
    }
    WindowOn=1;
    WindowThreadDone=1;
    while (GetMessage(&MainWinMsg,NULL,0,0))
    {  
        Sleep(1);
        TranslateMessage(&MainWinMsg);
        DispatchMessage(&MainWinMsg);
    }
   _exit(0);   
}

void *TimerThreadFunc(void *vargp){
   TimerInitialized=1;
   do{
    Sleep(1);
    time(&t);
    time_str = ctime(&t);
    time_str[strlen(time_str)-1] = '\0';
   }while(1);
   
    
}
