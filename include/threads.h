#ifndef FILE_THREADS_SEEN
#define FILE_THREADS_SEEN

#include <includes.h>

//threaded functions
void *WorkerThread(void *vargp);
void *WindowThread(void *vargp);
void *TimerThreadFunc(void *vargp);
void *InputThreadFunc(void *vargp);

#endif