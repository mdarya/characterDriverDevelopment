#include "headers.h"
#include "declarations.h"

int fd;

void* openDev(void* arg)
{
	int i;
	char ch;
	char* filename;
	printf("App %s: Begin\n", __func__);
	
	filename = (char*)malloc(20);
	if(!filename)
	{
		perror("filename malloc failed!!!");
		(*fptr[1])((void*)"failure");
	}
	memset(filename, '\0', 20);
	i = 0;
	printf("App: Give Device Name for Opening:\n");
	getchar();
	do
	{
		ch = getchar();
		if(ch == '\n')
			break;
		*(filename+i++) = ch;
	}while(1);
	printf("App %s: filename=%s\n", __func__, filename);
	
	fd = open(filename, O_WRONLY);
	if(fd == -1)
	{
		perror("File opening error!!!");
		free(filename);
		(*fptr[1])((void*)"failure");
	}

	printf("App %s: fd=%d,filename=%s\n", __func__, fd, filename);

	printf("App %s: End\n", __func__);
	return (void*)0;
}
