#! /bin/bash

buildApp()
{
        echo
        if ( make -C ./application )
        then
                echo "Application build successfully..."
		mv ./application/app .
		rm -rf ./application/*.o
        else
                echo "Application build failed !!!"
		read
        fi
}

