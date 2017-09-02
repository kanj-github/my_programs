#!/bin/sh

function process_dir {
	cd "$1";
	dir_count=0;
	file_count=0;
	for i in *; do
		if [ -d "$i" ]; then
			process_dir "$i";
			dir_count=`expr $dir_count + 1`;
		else
			file_count=`expr $file_count + 1`;
		fi
	done
	if [ $dir_count -eq 0 -a $file_count -lt 3 ]; then
		# explode this directory
		echo -n "Exploding "$1" in ";
		dirname `pwd`;
		echo;
		#mv -iv ./* ../;
		cd ..;
		#rm -r "$1"; #may still contain hidden files
	else
		cd ..;
	fi
}

if [ $# -lt 1 ]; then
	echo "Give a directory as argument jackass.";
	exit 1;
fi

process_dir "$1"
