#include "headers.h"
#include "declarations.h"

ssize_t readDevice(struct file *filep, char __user *buff, size_t sz, loff_t *seekp)
{
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif

#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return 0;
}
