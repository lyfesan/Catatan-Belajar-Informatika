# MengOS

Nori adalah seorang mahasiswa yang sedang belajar membuat sistem operasi. Ia ingin membuat sebuah sistem operasi sederhana yang dapat menampilkan dan membaca string dari pengguna. Karena Nori sedang pada fase malas, dia meminta bantuan Anda untuk membuat program tersebut. Bantulah Nori untuk menyelesaikan tugasnya!

### Struktur Direktori

```
task-3/
├── bin/
├── include/
│   ├── kernel.h
│   ├── std_lib.h
│   └── std_type.h
├── src/
│   ├── bootloader.asm
│   ├── kernel.asm
│   ├── kernel.c
│   └── std_lib.c
├── bochsrc.txt
└── makefile
```

- [`bin/`](./bin/) : menyimpan file hasil kompilasi
- [`include/`](./include/) : berisi kode file header
- [`src/`](./src/) : berisi kode sumber
- [`bochsrc.txt`](./bochsrc.txt) : konfigurasi Bochs
- [`makefile`](./makefile) : file konfigurasi make

### Kernel

#### [`kernel.asm`](./src/kernel.asm)

```asm
global _putInMemory
global _interrupt

; void putInMemory(int segment, int address, char character)
_putInMemory:
	push bp
	mov bp,sp
	push ds
	mov ax,[bp+4]
	mov si,[bp+6]
	mov cl,[bp+8]
	mov ds,ax
	mov [si],cl
	pop ds
	pop bp
	ret

; int interrupt(int number, int AX, int BX, int CX, int DX)
_interrupt:
	push bp
	mov bp,sp
	mov ax,[bp+4]
	push ds
	mov bx,cs
	mov ds,bx
	mov si,intr
	mov [si+1],al
	pop ds
	mov ax,[bp+6]
	mov bx,[bp+8]
	mov cx,[bp+10]
	mov dx,[bp+12]

intr:	int 0x00

	mov ah,0
	pop bp
	ret
```

- `_putInMemory` : fungsi untuk menulis karakter ke memori (penjelasan ada di modul)

- `_interrupt` : fungsi untuk melakukan interrupt

  - `number` : nomor vektor interrupt
  - `AX`, `BX`, `CX`, `DX` : register yang akan diisi
  - Register `AX` merupakan gabungan dari `AH` dan `AL`
  - Register `BX` merupakan gabungan dari `BH` dan `BL`
  - Register `CX` merupakan gabungan dari `CH` dan `CL`
  - Register `DX` merupakan gabungan dari `DH` dan `DL`
  - Untuk menggabungkan dua regester tipe `H` dan `L` menjadi `X` dapat menggunakan salah satu dari cara berikut.
    ```c
    AX = AH << 8 | AL // cara pertama
    AX = AH * 256 + AL // cara kedua
    ```

#### [`kernel.c`](./src/kernel.c)

```c
#include "kernel.h"
#include "std_lib.h"

int main() {
  char buf[128];
  clearScreen();
  printString("Welcome to MengOS\n");

  while (true) {
    printString("$ ");
    readString(buf);
    printString(buf);
    printString("\n");
  }
}
```

- Kernel akan menunggu input dari pengguna dan menampilkan input tersebut kembali ke layar selama sistem operasi berjalan.

- Dilarang mengubah isi dari fungsi `main`.

### File Header

#### [`std_type.h`](./include/std_type.h)

Header ini berisi definisi tipe data yang akan sering digunakan dalam program.

```c
typedef unsigned char byte;

typedef char bool;
#define true 1
#define false 0
```

- `byte` : tipe data unsigned char, digunakan untuk menyimpan angka dengan rentang 0-255 (`0x00`-`0xFF`)

- `bool` : tipe data boolean, digunakan untuk menyimpan nilai `true` atau `false`

  Tipe data ini dibuat karena tidak ada tipe data boolean di bahasa C.

#### [`std_lib.h`](./include/std_lib.h)

Header ini berisi deklarasi fungsi yang akan sering digunakan dalam program.

```c
int div(int a, int b);
int mod(int a, int b);

void memcpy(byte* src, byte* dst, unsigned int size);
unsigned int strlen(char* str);
bool strcmp(char* str1, char* str2);
void strcpy(char* src, char* dst);
void clear(byte* buf, unsigned int size);
```

- `div` : fungsi pembagian

- `mod` : fungsi modulo

  Fungsi `div` dan `mod` perlu dibuat karena tidak ada operator pembagian dan modulo pada bahasa assembly. Buatlah fungsi tersebut dengan menggunakan operator yang tersedia, seperti `+`, `-`, `*`, `<<`, dan `>>`.

- `memcpy` : fungsi untuk menyalin memori

- `strlen` : fungsi untuk menghitung panjang string

- `strcmp` : fungsi untuk membandingkan dua string

- `strcpy` : fungsi untuk menyalin string

- `clear` : fungsi untuk mengisi memori dengan nol

#### [`kernel.h`](./include/kernel.h)

Header ini berisi deklarasi fungsi yang memiliki implementasi pada `kernel.asm` dan akan diimplementasikan pada `kernel.c`.

```c
extern void putInMemory(int segment, int address, char character);
extern int interrupt(int number, int AX, int BX, int CX, int DX);

void printString(char* str);
void readString(char* buf);
void clearScreen();
```

- `putInMemory` : implementasi fungsi `_putInMemory` pada `kernel.asm`
- `interrupt` : implementasi fungsi `_interrupt` pada `kernel.asm`
- `printString` : fungsi untuk menampilkan string
- `readString` : fungsi untuk membaca string
- `clearScreen` : fungsi untuk membersihkan layar

### Makefile

```makefile
prepare:

bootloader:

stdlib:

kernel:

link:

build: prepare bootloader stdlib kernel link

run:
```

- `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.

- `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.

- `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.

- `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.

- `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.

- `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

- `run` : menjalankan Bochs dengan konfigurasi `bochsrc.txt`.

### Referensi Perintah

#### `dd`

```bash
dd if=<input_file> of=<output_file> bs=<block_size> count=<block_count> seek=<seek_count> conv=<conversion>
```

#### `nasm`

```bash
nasm -f <format> <input_file> -o <output_file>
```

#### `bcc`

```bash
bcc -ansi -c <input_file> -o <output_file>
```

#### `ld86`

```bash
ld86 -o <output_file> -d [file1.o file2.o ...]
```

### Deskripsi Tugas

- a. Implementasikan fungsi `printString` pada `kernel.c` yang akan menampilkan string ke layar.

  Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.

- b. Implementasikan fungsi `readString` pada `kernel.c` yang akan membaca string dari keyboard.

  Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.

- c. Implementasikan fungsi `clearScreen` pada `kernel.c` yang akan membersihkan layar.

  Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.

- d. Lengkapi implementasi fungsi yang terdapat pada [`std_lib.h`](./include/std_lib.h) pada [`std_lib.c`](./src/std_lib.c).

  Fungsi-fungsi di atas dapat digunakan untuk mempermudah implementasi fungsi `printString`, `readString`, dan `clearScreen`.

- e. Buat automasi untuk melakukan kompilasi dengan melengkapi file [`makefile`](./makefile).

  Untuk melakukan kompilasi program, akan digunakan perintah `make build`. Semua hasil kompilasi program akan disimpan pada direktori [`bin/`](./bin). Untuk menjalankan program, akan digunakan perintah `make run`.
