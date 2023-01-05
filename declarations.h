#ifndef PRINT
#define PRINT
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef DEVNAME
#define DEVNAME "ARYA_DRIVER"
#endif

#ifndef NOD
#define NOD 1
#endif

#ifndef REGSIZE
#define REGSIZE 2
#endif

#ifndef REGCOUNT
#define REGCOUNT 8
#endif

#ifndef DEVSIZE
#define DEVSIZE 256
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif

extern dev_t dev_id, devno;
extern unsigned int majorNo, minorNo, nod;
extern int regSize, noOfReg, devSize, dataSize;

typedef struct qset
{
	struct qset *next;
	void **data;
}Qset;
typedef struct dev
{
	int regSize;
	int noOfReg;
	int devSize;
	int dataSize;
	struct cdev c_dev;
	struct qset *first;
}Dev;
extern Dev *mydev;

int openDevice(struct inode *, struct file *);
int releaseDevice(struct inode *, struct file *);
ssize_t writeDevice(struct file *, const char __user *, size_t, loff_t *);
ssize_t readDevice(struct file *, char __user *, size_t, loff_t *);
int trimDevice(Dev *);
loff_t lseekDevice(struct file *, loff_t, int);

