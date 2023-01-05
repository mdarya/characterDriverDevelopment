#include "headers.h"
#include "declarations.h"

void* lseekDev(void* arg)
{
	int i, offset, npos;
	char origin[8];
	printf("App %s: Begin\n", __func__);
	
	printf("App %s: Enter the Origin for Seeking\n",__func__);
	i = 0;
	getchar();
	do
	{
		origin[i++] = getchar();
		if(i == 8)
			break;
	}while(1);
	printf("App %s: Enter the Offset for Seeking\n",__func__);
	scanf(" %d", &offset);

	if(strncmp(origin, "SEEK_SET", 8) == 0)
		npos = lseek(fd, offset, SEEK_SET);
	else if(strncmp(origin, "SEEK_CUR", 8) == 0)
		npos = lseek(fd, offset, SEEK_CUR);
	else if(strncmp(origin, "SEEK_END", 8) == 0)
		npos = lseek(fd, offset, SEEK_END);
	else
		printf("App %s: Invalid Origin\n", __func__);

	printf("App %s: New Position:%d\n", __func__, npos);
	printf("App %s: End\n", __func__);
	return 0;
}
