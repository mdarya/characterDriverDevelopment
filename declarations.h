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

extern dev_t dev_id;
extern unsigned int majorNo;
extern unsigned int minorNo;
extern unsigned int nod;

typedef struct dev
{
	int regSize;
	int noOfReg;
	int devSize;
	int dataSize;
	struct cdev c_dev;
}Dev;

extern Dev *mydev;

