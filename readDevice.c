#include "headers.h"
#include "declarations.h"

ssize_t readDevice(struct file *filep, char __user *ubuff, size_t size, loff_t *seekp)
{
	int noctr, nocsr, nocnr, i, j, oiq;
	size_t lsize;
	Dev *ldev;
	Qset *item;
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif
	*seekp = filep->f_pos;
	ldev = filep->private_data;
	if(!ldev)
	{
		printk(KERN_ERR "%s: ERROR: Device not found for reading.\n", __func__);
		return -1;
	}
	if(size > ldev->dataSize)
		noctr = lsize = ldev->dataSize - (long)*seekp;
	else
		noctr = lsize = size - (long)*seekp;

	oiq = nocsr = 0;
	i = *seekp / ldev->regSize;
	oiq = *seekp % ldev->regSize;
	item = ldev->first;
	j = i;
	if(i > ldev->noOfReg-1)
	{
		i = i / ldev->noOfReg;
		while(i)
		{
			item = item->next;
			i--;
		}
		j = j % ldev->noOfReg;
		i = j;
	}
	while(noctr > 0)
	{
		if(noctr > ldev->regSize)
			noctr = ldev->regSize - oiq;

		nocnr = copy_to_user(ubuff+nocsr, item->data[i]+oiq, noctr);
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
		oiq = 0;
	}

#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return nocsr;
}
