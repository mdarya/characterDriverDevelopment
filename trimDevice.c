#include "headers.h"
#include "declarations.h"

int trimDevice(Dev *fdev)
{
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif

#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return 0;
}
