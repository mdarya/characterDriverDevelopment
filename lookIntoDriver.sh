#! /bin/bash

lookIntoDriver()
{
        lsmod | grep "mycdd"
        read
        dmesg
        read
        cat /proc/devices
        read
        cat /proc/modules
        read
}

