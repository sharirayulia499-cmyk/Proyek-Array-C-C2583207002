# Proyek-Array-C-C2583207002

SISTEM MONITORING STOK DAN PENJUALAN KANTIN KAMPUS
Identitas Mahasiswa
- Nama: Sharira Yulia Suhendra
- NIM: C2583207002
- Kelas: PTI3A
- Mata Kuliah: Algoritma dan Pemrograman Lanjutan
Deskripsi Proyek
Program ini merupakan aplikasi berbasis terminal yang dibuat menggunakan bahasa pemrograman C untuk membantu menyatukan persediaan produk dan mencatat transaksi penjualan kantin kampus. Data produk disimpan sementara di dalam array selama program berjalan, sehingga program tidak menggunakan database maupun penyimpanan file.
Fitur Program
1. Melihat daftar produk beserta harga, stok, dan jumlah terjual.
2. Produk baru.
3. Mengubah harga dan stok produk.
4. Melakukan transaksi pembelian beberapa jenis produk sekaligus.
5. Mengosongkan stok produk.
6. Mencari produk berdasarkan nama atau kata kunci.
7. Mengurutkan produk berdasarkan harga termurah atau jumlah penjualan terbanyak.
8. Menampilkan laporan penjualan, total unit terjual, total pendapatan, dan produk terlaris.
9. Menampilkan produk dengan stok kurang dari 5.
10. Memvalidasi beberapa masukan, seperti nomor menu/produk, harga, stok, dan jumlah pembelian.
Penerapan Array
Program menggunakan beberapa array untuk menyimpan data produk:
- namaProduk[MAX_PRODUK][MAX_NAMA] : array dua dimensi untuk menyimpan nama produk. Kapasitas maksimal adalah 50 produk, dengan ruang nama maksimal 49 karakter ditambah karakter akhir string.
- hargaProduk[MAX_PRODUK] : array satu dimensi untuk menyimpan harga setiap produk.
- stokProduk[MAX_PRODUK] : array satu dimensi untuk menyimpan jumlah stok setiap produk.
- terjualProduk[MAX_PRODUK] : array satu dimensi untuk menyimpan jumlah unit yang telah terjual.
- jumlahData : variabel untuk menyimpan jumlah produk yang sedang terdaftar.
Indeks yang sama pada setiap array menunjukkan data dari produk yang sama. Contohnya, indeks ke-0 pada namaProduk , hargaProduk , stokProduk , dan terjualProduk merupakan informasi untuk produk pertama. Program menyediakan 5 data awal dan dapat menampung maksimal 50 produk.


Cara Menjalankan Program
Menggunakan GCC
1. Pastikan GCC sudah terpasang.
2. Buka terminal pada folder proyek.
3. Kompilasi program dengan perintah:
   gcc main.c -o kantin
4. Jalankan program:
   - Windows: kantin.exe
   - Linux/macOS: ./kantin
Menggunakan IDE
Buka file main.c melalui IDE C seperti Code: :Blocks atau Dev-C++, lalu lakukan proses Build/Compile dan Run.
Dokumentasi Pengujian
Pengujian berikut didokumentasikan berdasarkan hasil program yang dijalankan. Tangkapan layar menampilkan proses dan keluaran aktual.

1. Mengisi produk
Program dijalankan dengan memilih menu 2. Produk bernama nasi goreng ditambahkan dengan harga Rp15.000 dan stok 24. Program menampilkan pesan bahwa produk berhasil ditambahkan.
<img width="908" height="457" alt="1" src="https://github.com/user-attachments/assets/bc6b8677-7aca-4b1d-91de-59057afd62ff" />
