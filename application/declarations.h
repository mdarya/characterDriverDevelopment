#ifndef NOF
#define NOF 7
#endif

int init();
extern void* mainMenu(void*);
extern void* exitFunc(void*);
extern void* openDev(void*);
extern void* closeDev(void*);
extern void* writeDev(void*);
extern void* readDev(void*);
extern void* lseekDev(void*);

extern void* (*fptr[NOF])(void*);

extern int fd;
