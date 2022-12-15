#include "headers.h"
#include "declarations.h"

void* writeDev(void* arg)
{
	int sz;
	char buf[] = "This is Manu Deva Arya writing his first Driver";
	printf("App %s: Begin\n", __func__);

	sz = write(fd, buf, strlen(buf));
	if(sz == -1)
	{
		perror("write");
	}
	printf("App %s: Written %d bytes\n", __func__, sz);

	printf("App %s: End\n", __func__);
	return (void*)0;
}
