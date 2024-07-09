#!/bin/bash

prev_day_date=$(date -d "-1 day" +"%Y%m%d")

#current_time=$(date +"%Y%m%d")
#files=$(find ~/metrics -name "metrics_agg_$current_time*")
#tar -czvf ~/metrics/metrics_agg_$current_time.tar.gz $files

files=$(find ~/metrics -name "metrics_agg_$prev_day_date*")

tar -czvf ~/metrics/metrics_agg_$prev_day_date.tar.gz $files

chmod 400 /metrics/metrics_agg_$prev_day_date.tar.gz