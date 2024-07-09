

# Fu53enC0d3D==

Keamanan digital adalah suatu aspek penting dalam dunia digital, salah satu topik yang sangat menarik adalah keamanan dari suatu file. Cara cara untuk mengamankan isi dari suatu file salah satunya dapat menggunakan encode pada isi file tersebut. Encode adalah sebuah proses yang dilakukan untuk mengamankan data dan informasi dan membuatnya menjadi tidak bisa dibaca dengan mudah jika tidak ada pengetahuan khusus. Adapun salah satu encode paling terkenal adalah encode Base64.

Tugas kalian adalah merancang suatu sistem keamanan pada file file user menggunakan FUSE pada file [fuse.c](./fuse.c), dengan penjabaran tugas sebagai berikut:

- a. Clone [direktori target](https://github.com/hqlco/target.git) dan buatlah 4 user pada linux dengan username sesuai isi folder pada direktori target (password dibebaskan).

  | User | Folder |
  | ---- | ------ |
  | andi | andi   |
  | budi | budi   |
  | cony | cony   |
  | deni | deni   |

  Tabel kepemilikan folder

- b. Ketika folder mount point dari fuse yang kalian buat diakses, akan langsung menuju ke dalam target folder yang telah di clone (tidak dimulai dari root)

  ![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/1383686d-9ba2-4493-9297-3cdfdb7dcdac)

- c. Buatlah agar tiap user tidak dapat menambah, mengubah, maupun menghapus folder maupun file dalam folder yang bukan miliknya.

- d. Buatlah agar user dapat menambah, mengubah, maupun menghapus folder maupun file dalam folder miliknya.

  command yang relevan untuk poin c and d:
  
  - mkdir
  - rmdir
  - touch
  - rm
  - cp
  - mv
  - etc.

- e. Semua isi file akan ter-encode jika diakses oleh selain user pemilik folder tersebut (menggunakan encoding Base64).

- f. Sebaliknya, file akan ter-decode ketika diakses oleh user pemilik folder tersebut.

Contoh:

![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/932c2acd-2f85-4abf-9fc9-9c38737d1605)

Note:

- Nama folder mounting dibebaskan
- Agar fuse dapat diakses oleh semua user, perlu ditambahkan argumen “-o allow_other” ketika melakukan mount
