#!/bin/bash

current_time=$(date +"%Y%m%d%H")

files=$(find ~/metrics -name "metrics_$current_time*") 

awk -F "," ' 
BEGIN {
    countField = 0
    title = "Type"
    mini = "minimum"
    maxi = "maximum"
    averg = "average"
} 
{
    if(NR == 1) {
        title = title "," $0
        countField = NF
    }
    else if(NR == 2){
        for(i=1;i<=NF;++i) {
            maxs[i] = $i 
            mins[i] = $i
            avg[i] = $i
        }
    }
    else if(NR%2==0 && NR>2){
        for(i=1;i<=NF;++i) {
            if($i + 0 == $i){
                maxs[i] = (maxs[i] < $i) ? $i : maxs[i] 
                mins[i] = (mins[i] > $i) ? $i : mins[i]
                avg[i] += $i
            }
            else{
                maxs[i] = $i 
                mins[i] = $i
                avg[i] = $i
            }
        }
    }
}
END {
    for(i=1;i<=countField; ++i){
        mini = mini "," mins[i]
        maxi = maxi "," maxs[i]
        if($i + 0 == $i) {
            avg[i]/=60
            averg = averg "," avg[i] 
        }
        else averg = averg "," avg[i] 
    }
    print title
    print mini
    print maxi
    print averg 
}' $files > ~/metrics/metrics_agg_$current_time.log

chmod 400 ~/metrics/metrics_agg_$current_time.log
