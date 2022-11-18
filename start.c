#include "headers.h"
#include "declarations.h"
#include "fileOpers.h"

dev_t dev_id, devno;
Dev *mydev;
unsigned int majorNo, minorNo, nod;
int regSize, noOfReg, devSize, dataSize;

module_param(nod, int, S_IRUGO);
module_param(regSize, int, S_IRUGO);
module_param(noOfReg, int, S_IRUGO);
module_param(devSize, int, S_IRUGO);

static int __init initfunc(void)
{
	int ret, i;
	dev_id = 0;
	majorNo = MAJORNO;
	minorNo = MINORNO;
	dataSize = DATASIZE;
	
#ifdef PRINT
        printk(KERN_INFO "%s: Begin...\n", __func__);
        printk(KERN_INFO "%s: nod=%d\n", __func__, nod);
        printk(KERN_INFO "%s: regSize=%d\n", __func__, regSize);
        printk(KERN_INFO "%s: noOfReg=%d\n", __func__, noOfReg);
        printk(KERN_INFO "%s: devSize=%d\n", __func__, devSize);
#endif
	/* Desc	    : Register a range of char device numbers. The major number will be chosen dynamically, 
	 * 	      and returned (along with minor number) in first arg 'dev'                          
	 * Synopsis : int alloc_chrdev_region(dev_t* dev, unsigned baseminor, unsigned count, const char* name);
	 * Inputs   : *dev - Output param for first assigned number
	 * 	      baseminor - First of the requested range of minor numbers.
	 * 	      count - The number of minor-number required.
	 * 	      *name -  Name of the associated device driver.
	 * Output   : dev_t* dev
	 * Return   : returns zero or negative error code
	 **/
	ret = alloc_chrdev_region(&dev_id, minorNo, nod, DEVNAME);
	if(ret == -1)
	{
		printk(KERN_ERR "%s: alloc_chrdev_region failure\n",__func__);
		goto OUT;
	}

	/* Desc	    : Macro that takes an argument of type dev_t, fetches it's MSB 12 bits, converts it into integer and returns it. 
	 * Synopsis : MAJOR(dev_t);
	 * Inputs   : dev_t* dev_id 
	 * Return   : int majorNo
	 **/
	majorNo = MAJOR(dev_id);
	printk(KERN_INFO "%s: majorNo:%d \n", __func__, majorNo);

	/* Desc     : kmalloc is the normal method of allocating memory for objects smaller than page size in the kernel. 
	 * Synopsis : void * kmalloc (size_t size, gfp_t flags); 
	 * Inputs   : size - How many bytes of memory are required.
	 * 	      flags - Type of memory to allocate ( a list of flags is available in linux/gfp_types.h Here we'll use;
	 *	      GFP_KERNEL - Get Free Page Kernel, It allocates normal kernel ram, May sleep.)
	 * Return   : void* pointer to allocated memory block.
	 **/
	mydev = (Dev*)kmalloc(sizeof(Dev)*nod, GFP_KERNEL);
	if(!mydev)
	{
		printk(KERN_ERR "%s: kmalloc returned failure !!!\n",__func__);
		goto OUT;
	}

	for(i = 0; i < nod; i++)
	{
		/* Desc     : Initialise the c_dev kernel structure available in linux/cdev.h.
		 * Synopsis : void cdev_init (struct cdev* cdev, const struct file_operations* fops);
		 * Inputs   : cdev - The structure to initialise
		 * 	      *fops - The file operations for this device
		 * Return   : void 
		 **/
		cdev_init(&mydev[i].c_dev, &fops);

		/* Desc     : MKDEV is the macro which takes major and minor numbers and returns combined number.
		 * Return   : Returns a combined dev_t devno 
		 **/
		devno = MKDEV(majorNo, i);

		/* Desc     : Adds a char device to the system (device table) and make it live immediately.
		 * Synopsis : int cdev_add (struct cdev* cdev, dev_t dev, unsigned count);
		 * Inputs   : *cdev - The cdev structure for the device
		 * 	      dev - The first device number for which this device is responsible
		 * 	      count - The number of consecutive minor numbers corresponding to this device
		 * Return   : A negative error code is returned on failure.
		 **/
		ret = cdev_add(&mydev[i].c_dev, devno, 1);
		if(ret < 0)
		{
			printk(KERN_ERR "%s: cdev_add() return failure !!!\n",__func__);
			goto OUT;
		}

		minorNo = MINOR(mydev[i].c_dev.dev);
		printk(KERN_INFO "%s: minorNo:%d \n", __func__, minorNo);

	}

	printk(KERN_INFO "%s: Hello Kernel!!\n", __func__);
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
