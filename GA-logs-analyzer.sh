#!/bin/bash

# Display ADB logs of GA in a more readable manner.

INIT_AWK='
FS=", "
TYPE_PREFIX="t="
SCREEN_PREFIX="cd="
CATEGORY_PREFIX="ec="
ACTION_PREFIX="ea="
LABEL_PREFIX="el="
SCREEN_TYPE="screenview"'

PRINT_WITH_UUIDS='
type="";
category="";
action="";
label="";
screen="";
for (i = 1; i <= NF; i++) {
	if (index($i, TYPE_PREFIX) == 1) {
		type=substr($i, 3);
	} else if (index($i, CATEGORY_PREFIX) == 1) {
		category=substr($i, 4);
	} else if (index($i, ACTION_PREFIX) == 1) {
		action=substr($i, 4);
	} else if (index($i, LABEL_PREFIX) == 1) {
		label=substr($i, 4);
	} else if (index($i, SCREEN_PREFIX) == 1) {
		screen=substr($i, 4);
	}
}

if (type == SCREEN_TYPE && screen != "") {
	printf("Screenview - %s\n", screen);
} else if (category != "" && action != "" && label != "") {
	printf("Event -  Category= %s, Action= %s, Label= %s\n", category, action, label);
} else {
	#printf("Found nothing %s %s %s %s %s\n%s", type, screen, category, action, label, $0);
}'

PRINT_WITHOUT_UUIDS='
type="";
category="";
action="";
label="";
screen="";
for (i = 1; i <= NF; i++) {
	if (index($i, TYPE_PREFIX) == 1) {
		type=substr($i, 3);
	} else if (index($i, CATEGORY_PREFIX) == 1) {
		category=substr($i, 4);
	} else if (index($i, ACTION_PREFIX) == 1) {
		action=substr($i, 4);
	} else if (index($i, LABEL_PREFIX) == 1) {
		firstPipe=index($i, "|");
		lastUuid=index($i, "|UId:")
		label=substr($i, firstPipe + 1, lastUuid - firstPipe - 1)
	} else if (index($i, SCREEN_PREFIX) == 1) {
		screen=substr($i, 4);
	}
}

if (type == SCREEN_TYPE && screen != "") {
	printf("Screenview - %s\n", screen);
} else if (category != "" && action != "") {
	printf("Event -  Category= %s, Action= %s, Label= %s\n", category, action, label);
} else {
	#printf("Found nothing %s %s %s %s %s\n%s", type, screen, category, action, label, $0);
}'

if [[ $# -eq 0 ]]; then
	adb logcat | grep --line-buffered GAv4 | awk "BEGIN { $INIT_AWK } { $PRINT_WITH_UUIDS }"
elif [[ $# -eq 1 && $1 == "--no-uuid" ]]; then
	adb logcat | grep --line-buffered GAv4 | awk "BEGIN { $INIT_AWK } { $PRINT_WITHOUT_UUIDS }"
else
	echo "Usage: Run without any arguments or --no-uuid to remove UUIDs from event labels"
fi
