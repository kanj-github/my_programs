if [ $# -eq 1 ]; then
	echo Unmacing $1
	find $1 \( -name "\._*" -o -name ".DS_store" \) -delete
	cd $1
	if [ -d .Spotlight-V100 ]; then
		rm -fr .Spotlight-V100
	fi
	if [ -d .Trashes ]; then
		rm -fr .Trashes
	fi
	if [ -d .fseventsd ]; then
		rm -fr .fseventsd
	fi
	cd -
fi
