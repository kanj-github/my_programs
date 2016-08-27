#!/bin/bash

str[0]=string
str[1]=dead

var=str

function crap {
	echo $1 then $2
}

eval 'crap ${'$var'[1]} test'
