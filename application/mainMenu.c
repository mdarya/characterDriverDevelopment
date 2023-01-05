#include "headers.h"
#include "declarations.h"

void* mainMenu(void* arg)
{
	int i;
	printf("App %s: Begin\n", __func__);
	
	printf("App:___MAIN MENU___\n");
	printf("App: 0: Exit Application\n");
	printf("App: 1: Open Device\n");
	printf("App: 2: Close Device\n");
	printf("App: 3: Write into Device\n");
	printf("App: 4: Read from Device\n");
	printf("App: 5: Seek into Device\n");
	printf("App: Please Enter your choice:");
	scanf(" %d", &i);
	
	if(i == 0)
		(*fptr[i+1])((void*)"success");
	else
		(*fptr[i+1])(0);
	
	printf("App %s: End\n", __func__);
	return (void*)0;
}
