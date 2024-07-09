#Soal 1C

awk -F '\t' 'NR>1 {nama_skema[$2][$6]++} END {for (nama in nama_skema) {if (length(nama_skema[nama]) > 1) {for (pendamping in nama_skema[nama]) print pendamping}}} ' DataPKM.tsv
