choice=0
while true
do
	echo "\n\n------------MENU--------------"
	echo "\nASSIGNMENT - 1"
	echo "1. ASS1_01"
	echo "2. ASS1_02"
	echo "3. ASS1_03"
	echo "4. ASS1_04"
	echo "5. ASS1_05"
	
	echo "\nASSIGNMENT - 2"
	echo "6. ASS2_01"
	echo "7. ASS2_02"
	echo "8. ASS2_03"
	echo "9. ASS2_04"
	echo "10. ASS2_05"
	
	echo "\nASSIGNMENT - 3"
	echo "11. ASS3_01"
	echo "12. ASS3_02"
	echo "13. ASS3_03"
	echo "14. ASS3_04"
	echo "15. ASS3_05"
	echo "16. ASS3_06"
	
	echo "\n17. Exit from menu!"
	echo "\n-------------------------------"
	echo "\nEnter your choice: "
	read choice
	case $choice in		
		1) sh ass1_01.sh ;;
		2) sh ass1_02.sh ;; 
		3) sh ass1_03.sh ;;
		4) sh ass1_04.sh ;;
		5) sh ass1_05.sh ;;
		6) sh ass2_01.sh ;;
		7) sh ass2_02.sh ;;
		8) sh ass2_03.sh ;;
		9) sh ass2_04.sh ;;
		10) sh ass2_05.sh abc;;
		11) sh ass3_01.sh ;;
		12) sh ass3_02.sh ;;
		13) sh ass3_03.sh ;;
		14) sh ass3_04.sh ;;
		15) sh ass3_05.sh ;;
		16) sh ass3_06.sh ;;
		17) echo "Quitting... "
			exit ;;
		*) echo "Invalid option" ;;
	esac
done
	
