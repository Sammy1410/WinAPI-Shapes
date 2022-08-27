#include <includes.h>

//Here the definition of functions for graphics is written

void CanvasDraw(int x,int y,COLORREF color){
    int pos;
    if(!(x<0 || y<0 || x>=(windowDefault.width-1) || y>=(windowDefault.height-1)))
    {
        pos=y*windowDefault.width+x;
        WinBuffer0[pos]=color;
    }    
}


void Circle_Create(circle circle){
    int i,j;
    float dist;
    i=circle.center.X-circle.radius;
   
    do{
        j=circle.center.Y-circle.radius;
        do{
            dist= sqrt(pow((circle.center.X-i),2)+pow((circle.center.Y-j),2));
            
            //if(fabs(dist-radius)<0.5){
            if(dist<circle.radius){
                CanvasDraw(i,j,circle.color);
            }    
            j+=1;
        }while(j<=(circle.center.Y+circle.radius));
        i+=1;
    }while(i<=(circle.center.X+circle.radius));
     
}



void Poly_Create(polyP Poly){
    
    line ldata;
    for(int j=1;j<Poly->no;j++){
        /*
        ldata.start={poly->points[j-1].X,poly->points[j-1].Y};
        ldata.end={poly->points[j].X,poly->points[j].Y};
        ldata.color=poly->color[j-1];
        Line_Create(ldata);                                              
        */
    }
}

//Lines - Straight
void Line_Create(line Line){
    Line.slope=(Line.end.Y-Line.start.Y)/(Line.end.X-Line.start.X);
    float j;
    for(int k=0;k<Line.width;k++){
        j=Line.end.Y;
        for(float i=Line.start.X+k;i<Line.end.X+k;i++){
            CanvasDraw(i,j,Line.color);
            j+=Line.slope;
        }
    }  
}

//Rectangles
void Rect_Create(rect rect){
    rect.length=rect.end.X-rect.start.X;
    rect.breadth=rect.end.Y-rect.start.Y;
    //fprintf(msg_logs,"%f %f %f %f %d\n",rect->start.X,rect->start.Y,rect->end.X,rect->end.Y,rect->color);
    for(int j=0;j<=rect.breadth;j++){
        for (int i=0;i<rect.length;i++){
            CanvasDraw(rect.start.X+i,rect.start.Y+j,rect.color);
        }
    }
    //Checking with pointers
    /*
    rect->length=rect->end.X-rect->start.X;
    rect->breadth=rect->end.Y-rect->start.Y;
    //fprintf(msg_logs,"%f %f %f %f %d\n",rect->start.X,rect->start.Y,rect->end.X,rect->end.Y,rect->color);
    for(int j=0;j<=rect->breadth;j++){
        for (int i=0;i<rect->length;i++){
            CanvasDraw(rect->start.X+i,rect->start.Y+j,rect->color);
        }
    }
    */
}