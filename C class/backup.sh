#!/usr/bin/bash

[ -d /tmp/backup ] || mkdir /tmp/backup
tar -cvzf /tmp/backup/$(date +%Y%m%d%H%m).tar.gz dir2 myprocess test test2
