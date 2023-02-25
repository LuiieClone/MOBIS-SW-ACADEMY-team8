#!/usr/bin/bash

if [ $# -ne 1 ]
then
	echo "Usage: $0 file_name"
else
	scp -P 2222 $1 pi@192.168.10.1:/home/pi
fi
