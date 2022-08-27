#ifndef FILE_OBJDATA_SEEN
#define FILE_OBJDATA_SEEN
#include <includes.h>

typedef struct _circledata{
        FCOORD center;
        FCOORD *points;
        float radius;
        BOOL filled;
        COLORREF color;
}circle,*circleP;


typedef struct _rectdata{
    FCOORD start;
    FCOORD end;
    FCOORD points;
    float length,breadth;
    BOOL filled;
    COLORREF color;
}rect,*rectP;

typedef struct _polydata{
    int no;
    PFCOORD points;
    COLORREF *color;
}poly,*polyP;

typedef struct _linedata{
    FCOORD start;
    FCOORD end;
    float slope;
    float theta_v;
    float theta_h;
    int width;
    COLORREF color;
}line,*lineP;

#endif