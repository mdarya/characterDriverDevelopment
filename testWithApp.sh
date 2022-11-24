#! /bin/bash

unlink mydevfile

testWithApp()
{
        echo
	#mknod mydevfile c $majorno 0
	mknod mydevfile c $1 0
	ls -al
	read
	./app
}
