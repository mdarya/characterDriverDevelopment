#include "headers.h"
#include "declarations.h"
#include "fileOpers.h"

dev_t dev_id;
Dev *mydev;
unsigned int majorNo, minorNo, num_dev;

static int __init initfunc(void)
{
	int ret;
	dev_id = 0;
	majorNo = MAJORNO;
	minorNo = MINORNO;
	num_dev = NOD;
	
#ifdef PRINT
        printk(KERN_INFO "%s: Begin...\n", __func__);
#endif
	/* int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *) */
	ret = alloc_chrdev_region(&dev_id, minorNo, num_dev, DEVNAME);
	if(ret == -1)
	{
		printk(KERN_ERR "%s: alloc_chrdev_region failure\n",__func__);
		goto OUT;
	}

	majorNo = MAJOR(dev_id);
	minorNo = MINOR(dev_id);

	mydev = (Dev*)kmalloc(sizeof(Dev), GFP_KERNEL);
	if(!mydev)
	{
		printk(KERN_ERR "%s: kmalloc returned failure !!!\n",__func__);
		goto OUT;
	}

	/* void cdev_init(struct cdev *, const struct file_operations *); */
	cdev_init(&mydev->c_dev, &fops);

	/* int cdev_add(struct cdev *p, dev_t dev, unsigned count); */
	ret = cdev_add(&mydev->c_dev, dev_id, 1);
	if(ret < 0)
	{
		printk(KERN_ERR "%s: cdev_add() return failure !!!\n",__func__);
		goto OUT;
	}

	printk(KERN_INFO "%s: majorNo:%d minorNo:%d Hello Kernel!!\n", __func__, majorNo, minorNo);
#ifdef PRINT
	printk(KERN_INFO "%s: End...\n", __func__);
#endif
	return 0;

OUT:
#ifdef PRINT
	printk(KERN_ERR "%s: Error!! exiting from OUT tag.\n",__func__);
#endif
	return -1;
}

module_init(initfunc);
