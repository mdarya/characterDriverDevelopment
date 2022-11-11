#include "headers.h"
#include "declarations.h"

static void __exit exitfunc(void)
{
#ifdef PRINT
	printk(KERN_INFO "%s: Begin...\n", __func__);
#endif
	cdev_del(&mydev->c_dev);
	kfree(mydev);
	/* extern void unregister_chrdev_region(dev_t, unsigned); */
	unregister_chrdev_region(dev_id, num_dev);
	
	printk(KERN_INFO "%s: majorNo:%d minorNo:%d Bye Kernel!!\n", __func__, majorNo, minorNo);
#ifdef PRINT
	printk(KERN_INFO "%s: End...\n", __func__);
#endif
}

module_exit(exitfunc);
