#include "headers.h"
#include "declarations.h"

ssize_t writeDevice(struct file *filep, const char __user *ubuff, size_t size, loff_t *seekp)
{
	Dev *ldev;
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif
	ldev = (Dev*)filep->private_data;
	if(!ldev)
	{
		printk(KERN_ERR "%s: Device not opened for writing.\n", __func__);
		return -1;
	}

#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return 0;
}
