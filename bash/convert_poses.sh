#!/bin/bash
# since Bash v4
FILES=/home/marek/poses/*
count=0
for f in $FILES
do
((count++))
if ((count < 10));
then
mv $f /home/marek/poses/scan00$count.pose
elif ((count > 9 && count < 100));
then
mv $f /home/marek/poses/scan0$count.pose
else
mv $f /home/marek/poses/scan$count.pose
fi
printf "poses:"'%d' "$count" 
done
