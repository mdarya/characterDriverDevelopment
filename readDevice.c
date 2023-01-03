#include "headers.h"
#include "declarations.h"

ssize_t readDevice(struct file *filep, char __user *ubuff, size_t size, loff_t *seekp)
{
	int noctr, nocsr, nocnr, i;
	size_t lsize;
	Dev *ldev;
	Qset *item;
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif
	ldev = filep->private_data;
	if(!ldev)
	{
		printk(KERN_ERR "%s: ERROR: Device not found for reading.\n", __func__);
		return -1;
	}
	if(size > ldev->dataSize)
		noctr = lsize = ldev->dataSize;
	else
		noctr = lsize = size;

	i = nocsr = 0;
	item = ldev->first;
	while(noctr > 0)
	{
		if(noctr > ldev->regSize)
			noctr = ldev->regSize;

		nocnr = copy_to_user(ubuff+nocsr, item->data[i], noctr);
		if(nocnr > 0)
		{
			printk(KERN_INFO "%s: Partial Read\n", __func__);
		}
		nocsr = nocsr + (noctr - nocnr);
		noctr = lsize - nocsr;
		if(i == ldev->noOfReg-1)
		{
			item = item->next;
			i = 0;
		}
		else
			i++;
	}

#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return nocsr;
}
