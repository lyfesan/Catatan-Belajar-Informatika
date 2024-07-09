#!/bin/bash

# Mencari nomor folder yang belum digunakan

cd $(pwd)
download_script(){
	i=1
	while [ -d "folder_$i" ]; do
		(( i++ ))
	done

	# Membuat folder baru dengan nama "folder_N"
	foldername="folder_$i"
	mkdir "$foldername"

	# Mendapatkan jam sekarang
	hour=$(date +%H)

	# Menghitung jumlah download yang akan dilakukan (X)
	if [ $((hour % 2)) -eq 0 ]; then
		X=5
	elif [ $(hour) -eq 0 ]; then
		X=10
	else
		X=3
	fi

	# Loop untuk melakukan download sebanyak X kali
	for (( j=1; j<=$X; j++ ))
	do
		# Membuat nama file dengan format "foto_NOMOR.FILE"
		filename="foto_$j.jpg"

		# Melakukan download gambar dari URL yang diinginkan
		wget -O "$foldername/$filename" https://akcdn.detik.net.id/community/media/visual/2022/04/06/mingyu-seventeen-4_43.jpeg?w=700&q=90
	done
}


folder2zip() {
	numfolder=$(ls -d folder_* 2>/dev/null | wc -l)

	for (( i=1; i<=$numfolder; i++ ))
	do
		foldername="folder_$i"
		zipname="ayang_$i.zip"

		if [ -f "$zipname" ]; then
			echo "File $zipname has already written, skip!".
		else
			zip -r $zipname folder_$i
		fi
	done
}


# Menghapus folder
delete_folderzip() {
	for folder in folder_*; do
		if [ -d "$folder" ]; then
			rm -r "$folder"
		fi
	done

	# Menghapus file zip
	for zipfile in ayang_*.zip; do
		if [ -f "$zipfile" ]; then
			rm "$zipfile"
		fi
	done
}

levi_eren() {

	# Mendapatkan tanggal hari ini dalam format YYYYMMDD
	today=$(date +%Y%m%d)

	# Menentukan siapa yang harus di-download hari ini berdasarkan tanggal
	if [ $((today % 2)) -eq 0 ]; then
		character="levi"
	else
		character="eren"
	fi

	# Link download berdasarkan karakter yang ditentukan
	if [ "$character" == "levi" ]; then
		download_link="https://i.pinimg.com/originals/5a/59/d1/5a59d12ab51d0633bc0521f804ac799b.jpg"
	else
		download_link="https://i.pinimg.com/564x/ef/34/96/ef349658df76f93c52780ed014f31f39.jpg"
	fi

	# Nama file yang di-download sesuai dengan format yang diminta
	filename="${character}_${today}.jpg"

	# Mendownload gambar dengan wget
	wget -O "$filename" "$download_link"
}

case $1 in
     "makefolder")
        download_script
        ;;
     "zipping")
        folder2zip
        ;;
     "delete_folder_zip")
        delete_folderzip
        ;;
     "levi_eren")
        levi_eren
        ;;
esac
