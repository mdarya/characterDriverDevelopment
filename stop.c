#include "headers.h"
#include "declarations.h"

static void __exit exitfunc(void)
{
	int i;
#ifdef PRINT
	printk(KERN_INFO "%s: Begin...\n", __func__);
#endif
	for(i = 0; i < nod; i++)
	{
		cdev_del(&mydev[i].c_dev);
	}
	
	kfree(mydev);
	/* extern void unregister_chrdev_region(dev_t, unsigned); */
	unregister_chrdev_region(dev_id, nod);
	
	printk(KERN_INFO "%s: majorNo:%d \n", __func__, majorNo);
	printk(KERN_INFO "%s: minorNo:%d \n", __func__, minorNo);
	printk(KERN_INFO "%s: Bye Kernel!!\n", __func__);
#ifdef PRINT
	printk(KERN_INFO "%s: End...\n", __func__);
#endif
}

module_exit(exitfunc);
