#include "headers.h"
#include "declarations.h"

void* writeDev(void* arg)
{
	int sz;
	char buf[] = "z";
	printf("App %s: Begin\n", __func__);

	sz = write(fd, buf, sizeof(buf));

	printf("App %s: Written %d bytes\n", __func__, sz);

	printf("App %s: End\n", __func__);
	return (void*)0;
}
