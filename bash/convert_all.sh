#!/bin/bash
# since Bash v4
FILES=/home/marek/throttled_copy/*
count=0
for f in $FILES
do
((count++))
if ((count < 10));
then
mv $f /home/marek/throttled_copy/scan00$count
printf '%d' "$count"
/home/marek/repos/vlp_pcl/src/build/pcd_write_test /home/marek/throttled_copy/scan00$count
rm /home/marek/throttled_copy/scan00$count
elif ((count > 9 && count < 100));
then
mv $f /home/marek/throttled_copy/scan0$count
printf '%d' "$count"
/home/marek/repos/vlp_pcl/src/build/pcd_write_test /home/marek/throttled_copy/scan0$count
rm /home/marek/throttled_copy/scan0$count
else
mv $f /home/marek/throttled_copy/scan$count
printf '%d' "$count"
/home/marek/repos/vlp_pcl/src/build/pcd_write_test /home/marek/throttled_copy/scan$count
rm /home/marek/throttled_copy/scan$count
fi
done

