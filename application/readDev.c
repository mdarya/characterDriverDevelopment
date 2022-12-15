#include "headers.h"
#include "declarations.h"

void* readDev(void* arg)
{
	int ret;
	char rbuf[256];
	printf("App %s: Begin\n", __func__);
	
	memset(rbuf, '\0', 256);
	lseek(fd, 0, SEEK_SET);
	ret = read(fd, rbuf, 256);
	if(ret == -1)
	{
		perror("read");
		(*fptr[1])((void*)"failure");
	}
	printf("App %s: Read bytes=%d Readbuff=%s\n", __func__, ret, rbuf);

	printf("App %s: End\n", __func__);
	return 0;
}
