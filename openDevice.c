#include "headers.h"
#include "declarations.h"

int openDevice(struct inode *inodep, struct file *filep)
{
	Dev* ldev;
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif
	ldev = container_of(inodep->i_cdev, Dev, c_dev);
	if(!ldev)
	{
		printk(KERN_ERR "%s: Error returned from container_of\n",__func__);
		goto OUT;
	}

	filep->private_data = ldev;

	if((filep->f_flags & O_ACCMODE) == O_WRONLY)
	{
		trimDevice(ldev);	
	}

#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return 0;
OUT:
#ifdef PRINT
	printk(KERN_ERR "%s: ERROR: End\n", __func__);
#endif
	return -1;
}
