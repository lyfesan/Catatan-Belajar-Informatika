#!/bin/bash

clear 

echo "Pendaftaran Proposal PKM"
read -p "Masukkan nama pengusul : " nama_pengusul
read -p "Masukkan asal departemen anda : " asal_departemen
read -p "Masukkan fakultas anda : " fakultas
read -p "Masukkan judul proposal : " judul_proposal
read -p "Masukkan nama dosen pendamping : " dosen_pendamping
read -p "Masukkan NIDN dosen pendamping : " nidn
read -p "Masukkan skema PKM : " skema_pkm

awk -F "," -v nama_pengusul="$nama_pengusul" -v asal_departemen="$asal_departemen" -v fakultas="$fakultas" -v judul_proposal="$judul_proposal" -v dosen_pendamping="$dosen_pendamping" -v nidn="$nidn" -v skema_pkm="$skema_pkm" -v current_date="$(date +"%y/%m/%d %H:%M:%S")" '
BEGIN { 
    FPAT="([^,]*)|(\"[^\"]+\")" 
    flag_match=0
    gsub(/ /,"_",nama_pengusul)
    split(nama_pengusul, new_user, "_") 
    new_password = fakultas nidn
    csv_input_data = nama_pengusul "," asal_departemen " ," fakultas "," judul_proposal "," dosen_pendamping " (" nidn ") ," skema_pkm
}
{
    split($2, name, "_")
    match($6, /\(([^)]+)\)/, arr)
    username = name[1]
    password = $4 arr[1]
    if(new_user[1] == username && password == new_password) {
        flag_match=1
        #print username " " password
        #print new_user[1] " " new_password
        exit
    }
}
END {
    if(flag_match == 0) {
        print current_date " REGISTER: SUCCESS " new_user[1] " is registered. Proposal " NR " is added" >> "log.txt"
        print NR "," csv_input_data >> "resources/data-pkm.csv"
    }
    else {
        print current_date " REGISTER: ERROR " new_user[1] " is already registered." >> "log.txt"
    }
    
}' resources/data-pkm.csv