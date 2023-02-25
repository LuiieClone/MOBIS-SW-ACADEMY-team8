#!/usr/bin/bash

echo "User Name to track:"
read username

while true
do
	w | grep ^$username | grep -v sshd | grep -v bash
	sleep 5
done
