#! /bin/bash
echo

removeDriver()
{
        echo
        if (rmmod mycdd)
        then
                echo "Driver Removed Successfully..."
        else
                echo "rmmod error !!!"
        fi
}

