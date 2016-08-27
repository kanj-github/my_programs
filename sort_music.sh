#!/bin/bash

folders=("one" "another one")

for i in ./
#for i in 1 2 3 4
do
	echo "loop $i"
	id3ed -i "$i" | grep artist
	read choice
	if [[ $choice =~ [0-4] ]]; then
		if [ $choice -lt ${#folders[@]} ]; then
			echo found
			echo ${folders[choice]}
		else
			echo "$choice is invalid"
		fi
	else
		echo $choice
		folders[${#folders[@]}]="$choice"
	fi
done
