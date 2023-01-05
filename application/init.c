#include "headers.h"
#include "declarations.h"

void* (*fptr[NOF])(void*);
void* mainMenu(void*);
void* exitFunc(void*);
void* openDev(void*);
void* closeDev(void*);
void* writeDev(void*);
void* readDev(void*);
void* lseekDev(void*);

int init()
{
	printf("App %s: Begin\n", __func__);
	
	fptr[0] = mainMenu;
	fptr[1] = exitFunc;
	fptr[2] = openDev;
	fptr[3] = closeDev;
	fptr[4] = writeDev;
	fptr[5] = readDev;
	fptr[6] = lseekDev;

	printf("App %s: End\n", __func__);
	return 0;
}
