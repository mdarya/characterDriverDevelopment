#! /bin/bash
echo

insertDriver()
{
        echo
        if (insmod ./modules/mycdd.ko)
        then
                echo "Driver loaded successfully..."
        else
                echo "Driver insertion failed !!!"
        fi
}

