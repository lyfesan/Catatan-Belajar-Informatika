[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/nyzv0V02)
<div align=center>

|    NRP     |      Name      |
| :--------: | :------------: |
| 5025221168 | Rayhan Maulana Akbar |
| 5025221193 | Alief Gilang Permana Putra |
| 5025221203 | Muhammad Choirun Ni'am |

# Praktikum Modul 1 _(Module 1 Lab Work)_

</div>

### Daftar Soal _(Task List)_

- [Task 1 - Tim Kawal Bubu _(Bubu's Monitoring Team)_](/task-1/)

- [Task 2 - Gabut Yuan _(Yuan's Boredom)_](/task-2/)

- [Task 3 - Magang Bubu _(Bubu's Internship)_](/task-3/)

- [Task 4 - LDR Isabel _(Isabel Sad Relationship)_](/task-4/)

### Laporan Resmi Praktikum Modul 1 _(Module 1 Lab Work Report)_

#### 1. Pembahasan Task 1 - Tim Kawal Bubu
a. Pada soal ini kita diminta untuk menampilkan nama mahasiswa yang memiliki judul proposal lebih dari 20 kata. Hal tersebut dapat dilakukan dengan mengetikkan perintah :
   
```sh awk -F '\t' '{ { title=$5; if (split(title, words, " ") > 20) {gsub("_"," ", $2); print $2" "$3 } } }' DataPKM.tsv   ```

` awk ` digunakan untuk dapat memilih sebagian teks yang ada di dataPKM.tsv, `-F '\t' ` memiliki arti bahwa kita akan membaca data dengan ekstensi '.tsv', sehingga kita menggunakan '\t' sebagai penanda bahwa data pada file dataPKM.tsv dipisahkan dengan tab. `title = $5` berguna untuk mengambil data judul yang terletak di kolom 5, kemudian argumen `if (split(title, words, " ") > 20) ` digunakan untuk menghitung kata yang tersedia (dengan cara membagi berdasarkan spasi) dan mengecek apakah lebih dari 20, dan apabila terpenuhi maka dijalankan argumen selanjutnya : `{gsub("_", " ", $2) `. gsub digunakan untuk mengganti argumen awal (dalam kasus ini adalah "_") ke argumen kedua ( dalam kasus ini adalah " ") pada kolom kedua. kemudian akan diprint kolom kedua dan ketiga yakni Nama pengusul dan jurusan yang ditempuh. Didapatkan hasil :

   <img width="479" alt="image" src="https://github.com/sisop-its-s24/praktikum-modul-1-d06/assets/115228631/2f5f8483-d470-42dd-9a96-ed69139a4e00">


b. Pada soal ini kita diminta untuk menampilkan skema dengan jumlah terbanyak, dengan menggunakan command berikut  :
   
```sh awk -F '\t' '{if (NR>1) count[$7]++} END {for (skema in count) print skema, count[skema]}' DataPKM.tsv | sort -k2 -nr | head -n 1 | awk '{print $1}' ```
   
` if (NR>1) count[$7]++ ` digunakan untuk membatasi penghitungan di number of row > 1 (karena baris 1 hanya berisi judul tabel), kemudian kita akan menghitung column ke-7, sehingga nanti didapatkan jumlah untuk tiap-tiap skema. ` for (skema in count) print skema, count[skema] ` digunakan untuk mengeluarkan masing-masing skema beserta jumlahnya. Karena yang diminta adalah hanya mengeluarkan nama skema tanpa jumlahnya maka kita buat kondisi di command selanjutnya. ` sort -k2 -nr ` digunakan untuk mengurutkan kolom ke 2 (karena kolom pertama adalah nama skema, kolom kedua adalah jumlah skema, pengurutan numerik hanya berdasarkan kolom 2) Kemudian `-nr` digunakan untuk mengurutkan numerik secara _reverse_ sehingga akan didapatkan hasil yang terbesar. ` head -n 1 ` digunakan untuk memunculkan 1 nilai terbesar, kemudian diprint hasilnya dengan command : ` print $1 `. Didapatkan hasil : 

<img width="389" alt="image" src="https://github.com/sisop-its-s24/praktikum-modul-1-d06/assets/115228631/494dce55-6ea8-4028-ae7c-36a5bc5f3e62">


c. Pada soal ini kita diminta untuk menampilkan mahasiswa yang memiliki 2 proposal dan menampilkan data dosen pembimbingnya, dengan melakukan command :

```sh awk -F '\t' 'NR>1 {nama_skema[$2][$6]++} END {for (nama in nama_skema) {if (length(nama_skema[nama]) > 1) {for (pendamping in nama_skema[nama]) print pendamping}}} ' DataPKM.tsv ```

` nama_skema[$2][$6]++ ` digunakan untuk menghitung kolom mahasiswa dan kolom dosen pendamping untuk menentukan apakah ada mahasiswa yang memiliki proposal dobel, berarti nama mahasiswa akan keluar lebih dari sekali. ` for (nama in nama_skema) {if (length(nama_skema[nama]) > 1) ` dari nama_skema tadi kita buat sebuah variabel nama, untuk menentukan panjangnya maka kita buat kondisi jika panjang dari nama_skema[nama] lebih dari 1 maka kita akan menampilkan nama pendampingnya dengan command : ` for (pendamping in nama_skema[nama]) print pendamping ` sehingga didapatkan hasil sebagai berikut :

<img width="376" alt="image" src="https://github.com/sisop-its-s24/praktikum-modul-1-d06/assets/115228631/73d220b8-cc5f-4f95-979d-640f0e00b514">

**Kendala : Di soal ini bisa dibilang mudah karena kita tinggal memanfaatkan command-command yang sudah dijelaskan di modul 1.**


#### 2. Pembahasan Task 2 - Gabut Yuan
Pada soal ini kita diberikan file csv yang terdapat pada ``resources/data-pkm.csv``. Kita diminta untuk membuat program untuk melakukan tugas tertentu menggunakan file csv tersebut

a. Pada soal ini, kita diminta untuk membuat script pada ```yu_login.sh``` untuk melakukan login berdasarkan data pada file csv yang diberikan. Untuk membaca input username dan password, kita menggunakan perintah berikut :

```sh
read -p "Enter username : " username
read -p "Enter password : " password
```
Perintah ini menggunakan ``read`` untuk membaca input dari user dengan *option* ``-p`` untuk mengeluarkan output prompt sebelum membaca input user yang kemudian input user akan dimasukkan ke dalam variabel bernama ``username`` dan ``password``. Kemudian, untuk mempermudah penulisan log nantinya, kita akan membuat variabel untuk menyimpan isi pesan berikut :

```sh
MESSAGE_SUCCESS="LOGIN: SUCCESS $username is logged in"
MESSAGE_FAIL="LOGIN: ERROR Failed login attempt on $username"
```

Variabel pesan ini menggunakan variabel ``username`` yang telah dibuat sebelumnya. Variabel ini akan digunakan pada perintah selanjutnya yang menjadi perintah inti pada subsoal ini.

Untuk mencocokkan ``username`` dan ``password`` dengan data yang terdapat pada csv, kita menggunakan ``awk`` untuk melakukan manipulasi data.

```sh
awk -F "," -v username="$username" -v password="$password" -v current_date="$(date +"%y/%m/%d %H:%M:%S")" -v msg_success="$MESSAGE_SUCCESS" -v msg_fail="$MESSAGE_FAIL" `
```

Pada perintah di atas kita menggunakan ``awk`` dengan *option* ``-F`` untuk mendefinisikan *field separator* antara konten serta ``-v`` untuk melakukan *variable assignment* di dalam perintah ``awk`` dengan menggunakan variabel yang terdapat pada *shell*. Pada kasus ini kita menggunakan ``username``, ``password``, ``msg_success``, ``msg_fail`` sebagai nama variabel serta satu tambahan variabel ``current`` date untuk mendefinisikan tanggal hari ini sesuai dengan format yang diminta menggunakan perintah ``date``.

```sh
BEGIN { 
    FPAT="([^,]*)|(\"[^\"]+\")" 
    flag_login=0 
}
```

Pada *block* ``BEGIN`` dalam perintah ``awk``, kita mendefinisikan ulang variabel bawaan ``FPAT`` yang digunakan untuk mendefinisikan apa yang dimaksud dengan *field* yang akan diproses oleh ``awk``. Merujuk pada halaman web manual [gawk](https://www.gnu.org/software/gawk/manual/html_node/Splitting-By-Content.html), definisi dari data *field* pada file csv adalah "semua yang bukan koma" atau "sebuah *double quote*, semua yang bukan *double quote*, dan sebuah *double quote* penutup." (Terdapat definisi yang lebih kompleks, akan tetapi untuk soal ini definisi di atas sudah mencukupi.) Kita dapat menggunakan *regular expression* ``([^,]*)|(\"[^\"]+\")`` untuk merepresentasikan definisi di atas pada variabel ``FPAT``. Variabel ``flag_login`` digunakan sebagai penanda apakah user dapat login atau tidak yang akan dijelaskan pada *block loop* ``awk`` selanjutnya.

```sh
{
    split($2, name, "_")
    match($6, /\(([^)]+)\)/, arr)
    pass = $4 arr[1]
    if(name[1] == username && password == pass) {
        flag_log=1
        exit
    }
} 
```

Pada *block loop* ini, kita menggunakan split untuk mendapatkan username dari kata pertama pada field kedua. Kemudian kita juga menggunakan match dengan *pattern regex* ``\(([^)]+)\)`` untuk mencari nomor dosen di dalam kurung pada field nama dan NIDN dosen. Selanjutnya kita membuat variabel baru bernama ``pass`` untuk menyimpan password dengan format nama fakultas + NIDN. Lalu kita cocokkan dengan username dan password dari input. Apabila cocok maka kita mengubah nilai ``flag_log`` menjadi 1 dan exit untuk kemudian dilanjutkan ke *block* ``END``

```sh
END {
    if(flag_log==0) {
        print current_date " " msg_fail
    }
    else {
        print current_date " " msg_success
    }
}' resources/data-pkm.csv >> "log.txt"
```

Pada *block* ``END`` ini kita mengecek apakah nilai ``flag_log`` 1 atau 0. Apabila 0, maka login gagal dan akan diprint nilai gagal pada log.txt serta login berhasil jika nilai adalah 1 menggunakan redirection ``>>``

b. Pada soal ini kita diminta untuk memasukkan data baru pada file csv dan hasilnya akan di log pada ``log.txt``. Berikut adalah kodenya :

```sh
clear 

echo "Pendaftaran Proposal PKM"
read -p "Masukkan nama pengusul : " nama_pengusul
read -p "Masukkan asal departemen anda : " asal_departemen
read -p "Masukkan fakultas anda : " fakultas
read -p "Masukkan judul proposal : " judul_proposal
read -p "Masukkan nama dosen pendamping : " dosen_pendamping
read -p "Masukkan NIDN dosen pendamping : " nidn
read -p "Masukkan skema PKM : " skema_pkm
```

Pada bagian pertama kita akan membersihkan isi layar terlebih dahulu, kemudian kita akan input semua data yang diperlukan menggunakan ``read``.

```sh
awk -F "," -v nama_pengusul="$nama_pengusul" -v asal_departemen="$asal_departemen" -v fakultas="$fakultas" -v judul_proposal="$judul_proposal" -v dosen_pendamping="$dosen_pendamping" -v nidn="$nidn" -v skema_pkm="$skema_pkm" -v current_date="$(date +"%y/%m/%d %H:%M:%S")" '
```

Kemudian kita menggunakan ``awk`` seperti pada subsoal a dengan field separator ``,`` dan *variable assignment* dari semua input yang dibaca ditambah dengan tanggal hari ini sesuai dengan format yang diberikan.

```sh
BEGIN { 
    FPAT="([^,]*)|(\"[^\"]+\")" 
    flag_match=0
    gsub(/ /,"_",nama_pengusul)
    split(nama_pengusul, new_user, "_") 
    new_password = fakultas nidn
    csv_input_data = nama_pengusul "," asal_departemen " ," fakultas "," judul_proposal "," dosen_pendamping " (" nidn ") ," skema_pkm
}
```

Pada *block* ``BEGIN``, kita mendefinisikan ``FPAT`` seperti pada subsoal a serta membuat variabel ``flag_match`` untuk mencari apakah terdapat nilai yang sama pada file csv, lalu kita menggabungkan nama pengusul dari input dengan *separator* ``_`` menggunakan ``gsub`` dan menggunakan ``split`` untuk memisahkan ``nama_pengusul`` menjadi tiap kata untuk mencari kata pertama sebagai ``username``. Lalu kita membuat variabel ``new_password`` sebagai password baru untuk calon user baru kita. Terakhir kita akan memformat semua data menjadi sesuai dengan data pada di csv agar dapat langsung dimasukkan ke dalam file csv tersebut.

```sh
{
    split($2, name, "_")
    match($6, /\(([^)]+)\)/, arr)
    username = name[1]
    password = $4 arr[1]
    if(new_user[1] == username && password == new_password) {
        flag_match=1
        exit
    }
}
```

Pada *block loop* ini kita mencari nilai yang sama pada file csv seperti pada subsoal a. Apabila terdapat ``username`` dan ``password`` yang sama, maka kita mengubah nilai ``flag_match`` menjadi 1 kemudian ``exit`` block ini untuk menuju *block* selanjutnya

```sh
END {
    if(flag_match == 0) {
        print current_date " REGISTER: SUCCESS " new_user[1] " is registered. Proposal " NR " is added" >> "log.txt"
        print NR "," csv_input_data >> "resources/data-pkm.csv"
    }
    else {
        print current_date " REGISTER: ERROR " new_user[1] " is already registered." >> "log.txt"
    }
    
}' resources/data-pkm.csv
```

Pada *block* ``END`` ini kita mengecek nilai ``flag_match``, apabila tidak ada nilai yang sama pada csv atau nilainya sama dengan 0, maka masukkan ``REGISTER SUCCESS`` pada ``log.txt`` serta masukkan data baru pada file ``data-pkm.csv`` dan apabila nilainya sama dengan 1, maka ``REGISTER ERROR`` pada ``log.txt`` serta data baru tidak akan dimasukkan pada ``log.txt``

c. Pada soal ini kita diminta untuk membuat ``users.txt`` dari file ``data-pkm.csv``. Scriptnya sebagai berikut :

```sh
awk -F "," '
BEGIN { FPAT="([^,]*)|(\"[^\"]+\")" }
{
    if(NR>1) {
        split($2, name, "_")
        match($6, /\(([^)]+)\)/, arr)
        username = name[1]
        password = $4 arr[1]
        print username " " password
    }
}' resources/data-pkm.csv > users.txt
```

Seperti soal-soal sebelumnya, kita menggunakan ``awk`` dengan field separator ``,``. Kemudian pada block ``BEGIN`` kita mendefinisikan variabel ``FPAT`` untuk csv. Lalu kita akan membaca setiap line pada file csv tersebut dengan syarat ``NR`` atau jumlah record yang telah dibaca lebih dari satu. Apabila syarat terpenuhi maka seperti kode pada soal-soal sebelumnya, akan dicari ``username`` dan ``password`` kemudian akan di print dengan format ``username password`` ke dalam file ``users.txt`` dengan redirection ``>``. File ``users.txt`` akan diupdate setiap satu jam sehingga pada file ``crontabs`` akan berisi seperti berikut :

```
0 * * * * yu_database.sh
```

#### 3. Pembahasan Task 3 - Magang Bubu

Pada soal ini kita diminta untuk untuk membuat file metrics dari *command* ``free -m`` dan ``du -sh`` serta menyimpannya agar bisa dibaca hanya oleh user yang membuat file tersebut. Kita juga membuat file agregasi untuk tiap jam serta melakukan zip file menggunakan tar untuk menghemat penyimpanan yang akan dieksekusi tiap hari satu kali

#### 4. Pembahasan Task 4 - LDR Isabel
Pada nomor 4, kita diberikan beberapa kondisi untuk melakukan download sebuah gambar dengan menggunakan penjadwalan crontab pada waktu yang berbeda namun setiap task dimasukkan dalam satu file yang sama yakni isabel.sh. Hal ini dapat diselesaikan dengan cara kita membuat setiap task berada dalam lingkup _function_ masing-masing, sehingga dalam isabel.sh dibuat 4 fungsi khusus yang spesifik menjalankan masing-masing task yang diberikan. Fungsi tersebut adalah download_script(), folder2zip(), delete_folderzip(), dan levi_eren(). Di akhir didefinisikan case $1 dalam fungsi tersebut untuk pemanggilan ketika isabel.sh dijalankan dengan command berikut :

   ```sh
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
   ```
   Contoh pemanggilan fungsi : `bash isabel.sh zipping `, maka akan menjalankan file isabel.sh dengan fungsi folder2zip(), sehingga fungsi lain tidak dipanggil dan akan memudahkan saat melakukan penjadwalan.

   a). Pada soal ini diminta untuk mendownload gambar tiap 5 jam sekali dengan ketentuan-ketentuannya, digunakan command berikut :
   ```sh
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
   ```
   Kita akan membuat folder yang digunakan untuk menyimpan foto dengan format penulisan adalah folder_angka, dan angka dimulai dari 1 sampai N, maka kita akan membuat pengecekan apakah folder_N sudah ada atau belum dengan command berikut :
   ```sh
         i=1
               	while [ -d "folder_$i" ]; do
               		(( i++ ))
               	done
               
               	# Membuat folder baru dengan nama "folder_N"
               	foldername="folder_$i"
               	mkdir "$foldername"
               
               	# Mendapatkan jam sekarang
               	hour=$(date +%H)
   ```
   Kemudian kita buat folder dan membuat variabel untuk menyimpan jam sekarang.

   Lalu kita akan menghitung jumlah download (X) yang dilakukan sesuai perintah soal :
   ```sh
         # Menghitung jumlah download yang akan dilakukan (X)
               	if [ $((hour % 2)) -eq 0 ]; then
               		X=5
               	elif [ $(hour) -eq 0 ]; then
               		X=10
               	else
               		X=3
               	fi
   ```

   Terakhir, kita akan melakukan download sesuai jumlah yang didapatkan :
   ```sh
      # Loop untuk melakukan download sebanyak X kali
            	for (( j=1; j<=$X; j++ ))
            	do
            		# Membuat nama file dengan format "foto_NOMOR.FILE"
            		filename="foto_$j.jpg"
            
            		# Melakukan download gambar dari URL yang diinginkan
            		wget -O "$foldername/$filename" https://akcdn.detik.net.id/community/media/visual/2022/04/06/mingyu-seventeen-4_43.jpeg?w=700&q=90
            	done
   ```

   b. Pada soal ini diminta untuk melakukan zip pada folder yang sudah dibuat sebelumnya, dengan code berikut :

   ```sh
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
   ```
   Mirip soal sebelumnya, kita akan menghitung jumlah folder_N yang sudah ada, kemudian dari jumlah tersebut kita melakukan looping untuk meng-_zip_ semua folder yang ditemukan, apabila ternyata ditemukan _file zip _ yang sama maka akan di-_skip_ dan akan dilanjutkan perulangan sampai semua _file_ selesai di-_zip_.

   c. Pada soal ini diminta menghapus semua folder dan zip yang sudah dibuat, dapat dilakukan dengan command ini :
   ```sh
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
   ```

   Kita disini melakukan 2 perulangan yang digunakan untuk menghapus semua folder_N dan semua ayang_zip

   d. Pada soal ini diminta untuk mendownload secara bergantian eren dan levy tiap hari :
   ```sh
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
   ```
   Di soal ini kita akan mengunduh gambar levi dan eren tiap hari selang-seling, maka yang pertama kita lakukan adalah mendapatkan tanggal hari ini, kemudian kita buat pengecekan sederhana untuk melakukan unduhan secara bergantian, dimana ketika tanggal genap maka akan download eren. Kemudian kita siapkan masing-masing _link download_ untuk tiap-tiap gambar, kemudian kita melakukan _download_ seperti biasa.

   Maka secara keseluruhan program adalah sebagai berikut :

   ```sh
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
   ```

   Kemudian setelah kita membuat program maka kita akan membuat penjadwalan untuk masing-masing fungsi menggunakan crontab sebagai berikut :
   ```sh
      #!/bin/bash
      
      # Add cron jobs
      # Make folder script (run every 5 hours)
      0 */5 * * * cd $(pwd) && bash isabel.sh makefolder 
      # Zip script (run every 10 hours)
      0 */10 * * * cd $(pwd) && bash isabel.sh zipping 
      # Delete script (run daily at 02:00 AM)
      0 2 * * * cd $(pwd) && bash isabel.sh delete_folder_zip 
      # Levi and Eren script (run daily)
      0 0 * * * cd $(pwd) && bash isabel.sh levi_eren 
   ```
   Pada crontab tersebut terdapat 4 jadwal untuk memanggil tiap-tiap fungsi pada isabel.sh.
   - Yang pertama berarti jadwal dilakukan tiap 5 jam sekali, dimana akan melakukan cd $(pwd) untuk pindah ke directory yang terdapat isabel.sh sehingga kita tidak perlu menuliskan path global dari isabel.sh. Kemudian kita menjalankan makefolder dari isabel.sh **Penting! Penggunaan bash bisa dihapuskan karena secara otomatis crontab akan berjalan di shell sehingga kita dapat langsung menuliskan isabel.sh makefolder tanpa menyertakan bash**.
   - Yang kedua kita akan menjalankan zipping tiap 10 jam sekali
   - Yang ketiga kita akan menjalankan delete_folder_zip tiap pukul 02:00
   - Yang keempat akan memanggil levi_eren tiap pukul 00:00 atau tiap hari. Penulisan ini dapat digantikan dengan @daily yang akan menjalankan penjadwalan setiap hari.


   **Kendala : Di soal ini sebenarnya agak _tricky_, namun masih mudah dikerjakan sehingga dapat selesai pada durasi waktu yang ditentukan tanpa perlu melakukan revisi. Yang perlu diperhatikan adalah bagaimana menerapkan beberapa script dalam satu file untuk dijalankan dengan jadwal yang berbeda-beda, dan perhatikan penggunaan crontabs harus pada path global, atau dapat dengan menggunakan cd $(pwd) seperti yang kami gunakan.**
   
