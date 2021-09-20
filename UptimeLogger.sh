#!/bin/sh

echo "running..."
touch uptime-log.txt
while true
do
    current_uptime=$(uptime -p)
    old_uptime=$(cat uptime-log.txt)
    if [ "$current_uptime" != "$old_uptime" ]
    then
        echo $current_uptime > uptime-log.txt
    fi
done
