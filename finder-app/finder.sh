#!/bin/bash

filesdir=$1
searchstr=$2

if [[ $# -ne 2 ]]
then
	echo "Usage: finder.sh <directory> <search string>"
	exit 1
fi

if ! [[ -d "$filesdir" ]]
then
	echo "$filesdir is not a directory"
	exit 1
fi

numfiles=$(find "$filesdir" -type f | wc -l)
matchlines=$(find "$filesdir" -type f -exec grep ${searchstr} {} \; | wc -l)

echo "The number of files are $numfiles and the number of matching lines are $matchlines"

