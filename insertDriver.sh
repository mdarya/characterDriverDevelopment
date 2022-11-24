#! /bin/bash

insertDriver()
{
        echo
        if ( insmod ./modules/mycdd.ko nod=10 devSize=124 noOfReg=4 regSize=4 )
        then
                echo "Driver loaded successfully..."
        else
                echo "Driver insertion failed !!!"
        fi
}

