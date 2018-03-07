#!/bin/bash

# Display ADB logs of GA in a more readable manner.

INIT_AWK='
FS=", "
TYPE_PREFIX="t="
SCREEN_PREFIX="cd="
CATEGORY_PREFIX="ec="
ACTION_PREFIX="ea="
LABEL_PREFIX="el="
AFTER_LABEL_PREFIX=", sr="
SCREEN_TYPE="screenview"'

COMMON_LOGIC_PART_1='
type="";
category="";
action="";
label="";
screen="";
lastUuid=0;
for (i = 1; i <= NF; i++) {
	if (index($i, TYPE_PREFIX) == 1) {
		type=substr($i, 3);
	} else if (index($i, CATEGORY_PREFIX) == 1) {
		category=substr($i, 4);
	} else if (index($i, ACTION_PREFIX) == 1) {
		action=substr($i, 4);
	} else if (index($i, LABEL_PREFIX) == 1) {
		labelStart=index($0, LABEL_PREFIX) + 3;
		labelEnd=index($0, AFTER_LABEL_PREFIX);
		fullLabel=substr($0, labelStart, labelEnd - labelStart);
'

COMMON_LOGIC_PART_2='
	} else if (index($i, SCREEN_PREFIX) == 1) {
		screen=substr($i, 4);
	}
}

if (type == SCREEN_TYPE && screen != "") {
	printf("Screenview - \033[34m%s\033[0m\n", screen);
} else if (category != "" && action != "") {
	printf("Event -  Category= \033[1m\033[30m%s\033[0m, Action= \033[1m\033[30m%s\033[0m,\033[32m Label=\033[0m %s\n", category, action, label);
} else {
	#printf("Found nothing %s %s %s %s %s\n%s", type, screen, category, action, label, $0);
}'

LABEL_LOGIC_WITH_UUID='
		label=fullLabel;
'

LABEL_LOGIC_WITHOUT_UUID='
		firstPipe=index(fullLabel, "|");
		lastUuid=index(fullLabel, "|UId:")
		label=substr(fullLabel, firstPipe + 1, lastUuid - firstPipe - 1)
'

PRINT_WITH_UUIDS=$COMMON_LOGIC_PART_1$LABEL_LOGIC_WITH_UUID$COMMON_LOGIC_PART_2
PRINT_WITHOUT_UUIDS=$COMMON_LOGIC_PART_1$LABEL_LOGIC_WITHOUT_UUID$COMMON_LOGIC_PART_2

if [[ $# -eq 0 ]]; then
	adb logcat -s GAv4 | awk "BEGIN { $INIT_AWK } { $PRINT_WITH_UUIDS }"
elif [[ $# -eq 1 && $1 == "--no-uuid" ]]; then
	adb logcat -s GAv4 | awk "BEGIN { $INIT_AWK } { $PRINT_WITHOUT_UUIDS }"
else
	echo "Usage: Run without any arguments or --no-uuid to remove UUIDs from event labels"
fi
