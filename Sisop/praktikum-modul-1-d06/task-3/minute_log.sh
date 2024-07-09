#!/bin/bash

current_date=$(date +"%Y%m%d%H%M%S")

free -m | awk -v disk="$(du -sh ~/)" ' 
BEGIN {
    title = ""
    value = ""
}
{
    if(NR==1) {
        split($0, column, " ")
    }
    else{
        split($0, record, " ")
        gsub(/:/,"",record[1])
        for(i in column) {
            if(record[1]=="Swap" && i>3) continue
            else{
                if(title == "") {
                    title = record[1] "_" column[i]
                }
                else {
                    title = title "," record[1] "_" column[i]
                }
            }
        }
        for(i in record) {
            if(i!=1) {
                if(value == "") {
                    value = record[i]
                }
                else {
                    value = value "," record[i]
                }
            }
        }
    }    
}
END{
    title = title ",Path,Path_size"
    split(disk, disks, " ")
    value = value "," disks[2] "," disks[1]
    print title
    print value
}' > ~/metrics/metrics_$current_date.log

chmod 400 ~/metrics/metrics_$current_date.log