#!/bin/bash

for i in *.mp3; do
	str=${i/"-arctic_monkeys-"/" "}
	str=${str//"_"/" "}
	str=${str~}
	str=${str/%Mp3/mp3}
	echo "Renaming "$i" to "$str
	mv -v $i "$str"
done
