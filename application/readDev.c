#include "headers.h"
#include "declarations.h"

void* readDev(void* arg)
{
	int ret;
	char ch[2];
	printf("App %s: Begin\n", __func__);
	ret = 0;
	lseek(fd, 0, SEEK_SET);
	ret = read(fd, ch, 2);
	if(ret == -1)
	{
		perror("read");
		(*fptr[1])((void*)"failure");
	}
	printf("App %s: Read bytes=%d Readbuff=%s\n", __func__, ret, ch);

	printf("App %s: End\n", __func__);
	return 0;
}
