#!/usr/bin/bash

ADDRLIST="127.0.0.1 192.168.10.128 192.168.80.2 192.168.80.100"
for ipaddr in $ADDRLIST
do
    ping -c 1 $ipaddr >/dev/null 2>&1
    if [ $? -eq 0 ]
    then
        echo "$ipaddr, Success!"
    else
        echo "$ipaddr, Fail..."
    fi
done
