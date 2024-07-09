#Soal 1B

awk -F '\t' '{if (NR>1) count[$7]++} END {for (skema in count) print skema, count[skema]}' DataPKM.tsv | sort -k2 -nr | head -n 1 | awk '{print $1}'
