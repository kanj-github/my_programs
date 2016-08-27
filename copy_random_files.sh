#!/bin/bash

################################################################################
# Usage:
# To get random files- copy_random_files.sh source [target]
# sync.db will be created in the working directory containing the path of files
# copied from source.
# To delete files at source if it has been deleted from target directory, cd to
# the target directory, make sure sync.db is present there and use command
# copy_random_files.sh sync
################################################################################

function process_file {
	num=$RANDOM
	let "num %= 100"
	if [ $num -lt 20 -a $num -gt 9 ]; then
		# copy file to target directory here
		cp -n "$1" "$targ_dir";
			if [ "$?" -eq 0 ]; then
				let "count += 1";
				echo $PWD/"$1" >> "$db_path"/sync.db
			fi
	fi
}

function process_dir {
	#echo "processing $1";
	cd "$1";
	for i in *; do
		if [ -d "$i" ]; then
			process_dir "$i";
		else
			process_file "$i";
		fi
	done
	cd ..;
}

function sync {
	count=0;
	while read line; do
		fil_name=`basename "$line"`;
		if [ ! -e "$fil_name" ]; then
			# echo "$line has been deleted.";
			rm "$line";
			let "count += 1";
			# mv "$line" /Volumes/Voldemort/del/
		fi
	done < sync.db
	echo "$count files were deleted.";
}

if [ $# -lt 1 ]; then
	echo "Give a source directory as argument jackass.";
	exit 1;
fi

if [ $# -eq 1 -a $1 == "sync" ]; then
	echo "Syncing using sync.db"
	sync;
	exit 0;
fi

if [ $# -eq 2 ]; then
	targ_dir="$2";
else
	targ_dir="$PWD";
fi

count=0;
echo -n "" > sync.db;
db_path=$PWD;

process_dir "$1";

echo "$count files copied to $targ_dir."
