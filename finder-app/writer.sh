#!/bin/bash

writefile=$1
writestr=$2

if [[ $# -ne 2 ]]
then
	echo "Usage: writefile.sh <full path to file> <string to write into file>"
	exit 1
fi

path=$(dirname ${writefile})
mkdir -p ${path}
echo ${writestr} > ${writefile}

