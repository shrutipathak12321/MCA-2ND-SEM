while [ true ]
do
    echo "\n0-> exit"
    echo "1-> Assignment 1"
    echo "2-> Assignment 2"
    echo "3-> Assignment 3"

    
    
    echo "\nEnter your choice : "
    read choice
    echo "You Choose $choice"
    case $choice in 
    
        1) cd /home/user1/Desktop/SHRUTI_21/ASS1
        echo "You are in Assignment 1"
            echo -n "Enter program number to execute: "
            read num
            name=ass1_0$num.sh
            chmod +x $name
            sh $name
            ;;
         
        2) cd /home/user1/Desktop/SHRUTI_21/ASS2
                echo "You are in Assignment 2"
            echo -n "Enter program number to execute: "
            read num
            name=ass2_0$num.sh
            chmod +x $name
            sh $name
            ;;
        3) cd /home/user1/Desktop/SHRUTI_21/ASS3
                echo "You are in Assignment 3"
            echo -n "Enter program number to execute: "
            read num
            name=ass3_0$num.sh
            chmod +x $name
            sh $name
            ;;
 
        0) echo "Quitting...."
        exit 0 ;;
        *) echo "Invalid Choice....";;
     esac
done
