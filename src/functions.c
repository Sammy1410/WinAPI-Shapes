#include <includes.h>

void _exit(int err_code){
    fclose(err_logs);
    fclose(warn_logs);
    fclose(msg_logs);

    //WindowOn=0;
    ReleaseDC(MainHandle,defaultDC);
    exit(err_code);
}


int location(int x,int y){
    return (y*windowDefault.width+x);
}



/*
void *WorkerThread(void *vargp){
    while(!WindowThreadDone && !WindowInitialized){ }
    Circle circle;
    Rect rect;
    FCOORD start[100],end[100];
    float radius[100];

    static int framelast=0;
    static int framenow=0;
    static int _timenow=time(NULL);
    int _timelast=_timenow;

    int g[100],b[100],r[100];

    
        
    int i=22,j=16;
    do{
        for(int m=0;m<100;m++){
            start[i].X=(rand() % (windowDefault.width-0+1))+0;
            start[i].Y=(rand() % (windowDefault.height-0+1))+0;
            end[i].X=(rand() % (windowDefault.width-0+1))+0;
            end[i].Y=(rand() % (windowDefault.height-0+1))+0;

            radius[i]=(rand() % (100-0+1))+0;
            b[i]=(rand() % (255-0+1))+0;
            g[i]=(rand() % (255-0+1))+0;
            r[i]=(rand() % (255-0+1))+0;
            circle.Create(start[i].X,start[i].Y,radius[i],RGB(b[i],g[i],r[i]));
            
            //rect.Create(start[j].X,start[j].Y,end[j].X,end[j].Y,0,RGB(115,115,169));
        }
    
        
        
        
        WorkerThreadDone=1; 
        while(!MainThreadDone){}
        MainThreadDone=0;   
        framenow++;
        _timenow=time(NULL);
        if(_timenow-_timelast>=1){
            fprintf(msg_logs,"%s :: FPS = %d\n",time_str,framenow-framelast);
            printf("FPS = %d\n",framenow-framelast);
            framelast=framenow;
            _timelast=_timenow;
        }
        
    }while(WindowOn); 
    
    //_exit(0);
}
*/
