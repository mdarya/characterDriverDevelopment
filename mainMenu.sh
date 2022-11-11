#! /bin/bash
echo

mainMenu()
{
        echo "__MAIN MENU__"
        echo "1: Build Driver"
        echo "2: Insert Driver"
        echo "3: Look Into Driver"
        echo "4: Test with Application"
        echo "5: Remove Driver"
        echo "0: Exit Script"
        read -n1 -p "Please Enter your Choice:"
        case $REPLY in
                1)
                        buildDriver
                        ;;
                2)
                        insertDriver
                        ;;
                3)
                        lookIntoDriver
                        ;;
                4)
                        testWithApp
                        ;;
                5)
                        removeDriver
                        ;;
                0)
                        exit 0;
                        ;;
        esac
}

