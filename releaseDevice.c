#include "headers.h"
#include "declarations.h"

int releaseDevice(struct inode *inodep, struct file *filep)
{
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif

#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return 0;
}
