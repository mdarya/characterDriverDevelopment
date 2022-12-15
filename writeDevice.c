#include "headers.h"
#include "declarations.h"

ssize_t writeDevice(struct file *filep, const char __user *ubuff, size_t size, loff_t *seekp)
{
	int noi, noq, i, l, noctw, nocnw, nocsw;
	size_t lsize;
	Dev *ldev;
	Qset *last;
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif
	ldev = (Dev*)filep->private_data;
	if(!ldev)
	{
		printk(KERN_ERR "%s: Device not opened for writing.\n", __func__);
		return -1;
	}

	if(size > ldev->devSize)
		lsize = ldev->devSize;
	else
		lsize = size;

	noi = size / (ldev->regSize * noOfReg);
	if(size % (ldev->regSize * noOfReg))
		noi++;
	
	last = ldev->first = (Qset*)kmalloc(sizeof(Qset), GFP_KERNEL);
	if(!ldev->first)
	{
		printk(KERN_ERR "%s: ERROR: kmalloc failure\n", __func__);
		return -1;
	}
	memset(ldev->first, '\0', sizeof(Qset));

	for(i = 1; i < noi; i++)
	{
		last->next = (Qset*)kmalloc(sizeof(Qset), GFP_KERNEL);
		if(!last->next)
		{
			printk(KERN_ERR "%s: ERROR: kmalloc failure\n", __func__);
			return -1;
		}
		memset(last->next, '\0', sizeof(Qset));
		last = last->next;
	}
	last = ldev->first;
	
	for(i = 0; i < noi; i++)
	{
		last->data = kmalloc(sizeof(char*)*ldev->noOfReg, GFP_KERNEL);
		if(!last->data)
		{
			printk(KERN_ERR "%s: ERROR: kmalloc failure\n", __func__);
			return -1;
		}
		memset(last->data, '\0', sizeof(char*)*ldev->noOfReg);
		last = last->next;
	}
	last = ldev->first;

	noq = lsize / ldev->regSize;
	if(lsize % ldev->regSize)
		noq++;

	for(i = l = 0; l < noq; l++)
	{
		last->data[i] = kmalloc(sizeof(char)*regSize, GFP_KERNEL);
		if(!last->data[i])
		{
			printk(KERN_ERR "%s: ERROR: kmalloc failure\n", __func__);
			return -1;
		}
		if(i == noOfReg-1)
		{
			last = last->next;
			i = 0;
		}
		else
			i++;
	}
	last = ldev->first;
	nocnw = nocsw = i = 0;
	noctw = lsize;
	while(noctw > 0)
	{
		if( noctw >= ldev->regSize )
			noctw = ldev->regSize;
		
		nocnw = copy_from_user(last->data[i], ubuff+nocsw, noctw);
		if( nocnw > 0)
		{
			printk(KERN_INFO "%s: Partial Write. nocnw:%d\n", __func__, nocnw);
		}
		nocsw = nocsw + (noctw - nocnw);
		noctw = lsize - nocsw;
		if(i == ldev->noOfReg-1)
		{
			last = last->next;
			i = 0;
		}
		else
			i++;
	}
	ldev->dataSize = nocsw;
#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return nocsw;
}
