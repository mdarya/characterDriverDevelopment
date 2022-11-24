#include "headers.h"
#include "declarations.h"

void* closeDev(void* arg)
{
	printf("App %s: Begin\n", __func__);
	
	close(fd);

	printf("App %s: End\n", __func__);
	return (void*)0;
}
