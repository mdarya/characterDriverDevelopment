#include "headers.h"
#include "declarations.h"

void* exitFunc(void* status)
{
	printf("App %s: Begin\n", __func__);

	if(strncmp((char*)status, "success", 7) == 0)
		exit(EXIT_SUCCESS);
	else if(strncmp((char*)status, "failure", 7) == 0)
		exit(EXIT_FAILURE);

	printf("App %s: End\n", __func__);
	return (void*)0;
}
