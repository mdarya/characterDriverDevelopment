#include "headers.h"
#include "declarations.h"

loff_t lseekDevice(struct file *filep, loff_t offset, int origin)
{
	loff_t newpos = 0;
#ifdef PRINT
	printk(KERN_INFO "%s: Begin\n", __func__);
	printk(KERN_INFO "%s: Current File Position:%ld\n", __func__, (long)filep->f_pos);
#endif
	switch(origin)
	{
		case 0: //SEEK_SET
			//if((long)offset < devSize)
			newpos = offset;
			break;
		case 1: //SEEK_CUR
			//if( ((long)offset + (long)filep->f_pos < devSize)&&((long)offset - (long)filep->f_pos >=0) )
			newpos = filep->f_pos + offset;
			break;
		case 2: //SEEK_END
			//if((long)offset + (long)filep->f_pos > devSize)
			newpos = devSize - offset;
			break;
		default:
			printk(KERN_ERR "%s: Invalid Origin\n", __func__);
	}
	if(newpos > devSize)
		newpos = devSize;
	if(newpos < 0)
		newpos = 0;
	filep->f_pos = newpos;

#ifdef PRINT
	printk(KERN_INFO "%s: New File Position:%ld\n", __func__, (long)filep->f_pos);
	printk(KERN_INFO "%s: End\n", __func__);
#endif
	return newpos;
}
