#Soal 1A

awk -F '\t' '{ { title=$5; if (split(title, words, " ") > 20) {gsub("_"," ", $2); print $2" "$3 } } }' DataPKM.tsv   

