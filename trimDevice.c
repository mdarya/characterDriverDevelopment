#include "headers.h"
#include "declarations.h"

int trimDevice(Dev *fdev)
{
	Qset *lit, *slit;
	int i, j;
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
#endif
	if(!fdev)
	{
		printk(KERN_INFO "%s: Device not found\n", __func__);
		return 0;
	}
	if(!fdev->first)
	{
		printk(KERN_INFO "%s: Nothing to trim\n", __func__);
		return 0;
	}
	lit = slit = fdev->first;
	j = 0;
	while(fdev->first)
	{
		while(lit->next)
		{
			slit = lit;
			lit = lit->next;	
		}
		if(lit->data)
		{
			for(i = fdev->noOfReg-1; i >= 0; i--)
			{
				if(lit->data[i])
				{
					kfree(lit->data[i]);
					lit->data[i] = NULL;
				}
			}
		}
		kfree(lit->data);
		lit->data = NULL;
		if(slit == lit)
			fdev->first = NULL;
		else
			slit->next = NULL;

		kfree(lit);
		lit = slit = fdev->first;
		printk(KERN_INFO "%s: %dth Item Trimmed\n", __func__, j);
		j++;
	}
#ifdef PRINT
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return 0;
}
