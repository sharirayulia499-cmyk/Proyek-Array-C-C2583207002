# Proyek-Array-C-C2583207002

# SISTEM MONITORING STOK DAN PENJUALAN KANTIN KAMPUS
Identitas Mahasiswa
- Nama: Sharira Yulia Suhendra
- NIM: C2583207002
- Kelas: PTI3A
- Mata Kuliah: Algoritma dan Pemrograman Lanjutan
Deskripsi Proyek
Program ini merupakan aplikasi berbasis terminal yang dibuat menggunakan bahasa pemrograman C untuk membantu menyatukan persediaan produk dan mencatat transaksi penjualan kantin kampus. Data produk disimpan sementara di dalam array selama program berjalan, sehingga program tidak menggunakan database maupun penyimpanan file.
Fitur Program
1. Lihat Daftar Produk: Menampilkan nomor, nama, harga satuan, sisa stok, dan jumlah terjual seluruh produk.
2. Tambah Produk: Menambahkan data produk baru ke dalam array (kapasitas maksimal 50 produk).
3. Ubah Produk: Memperbarui harga dan jumlah stok produk yang sudah terdaftar.
4. Transaksi Penjualan: Memproses pembelian beberapa jenis produk dalam satu transaksi, menghitung subtotal & total pembayaran, serta mengurangi stok dan menambah jumlah terjual secara otomatis.
5. Tambah Stok: Menambahkan jumlah stok pada produk tertentu.
6. Cari Produk: Mencari data produk berdasarkan kata kunci nama produk.
7. Urutkan Produk: Mengurutkan daftar produk berdasarkan harga termurah (ascending) dan jumlah terjual terbanyak (descending).
8. Laporan Penjualan: Menghitung dan menampilkan jumlah terjual per produk, total unit terjual, total pendapatan kantin, serta produk paling laris.
9. Cek Stok Menipis: Menampilkan peringatan daftar produk yang memiliki sisa stok kurang dari 5 unit.
# Penerapan Array
Program menggunakan beberapa array untuk menyimpan data produk:
- namaProduk [MAX_PRODUK][MAX_NAMA] : array dua dimensi untuk menyimpan nama produk. Kapasitas maksimal adalah 50 produk, dengan ruang nama maksimal 49 karakter ditambah karakter akhir string.
- hargaProduk [MAX_PRODUK] : array satu dimensi untuk menyimpan harga setiap produk.
- stokProduk [MAX_PRODUK] : array satu dimensi untuk menyimpan jumlah stok setiap produk.
- terjualProduk [MAX_PRODUK] : array satu dimensi untuk menyimpan jumlah unit yang telah terjual.
- jumlahData : variabel untuk menyimpan jumlah produk yang sedang terdaftar.
Indeks yang sama pada setiap array menunjukkan data dari produk yang sama. Contohnya, indeks ke-0 pada namaProduk , hargaProduk , stokProduk , dan terjualProduk merupakan informasi untuk produk pertama. Program menyediakan 5 data awal dan dapat menampung maksimal 50 produk.


# Cara Menjalankan Program
Menggunakan GCC
1. Pastikan GCC sudah terpasang.
2. Buka terminal pada folder proyek.
3. Kompilasi program dengan perintah:   
  ``` gcc main.c -o kantin```
5. Jalankan program:
   - Windows: kantin.exe
   - Linux/macOS: ./kantin
Menggunakan IDE
Buka file main.c melalui IDE C seperti Code: :Blocks atau Dev-C++, lalu lakukan proses Build/Compile dan Run.
Dokumentasi Pengujian
Pengujian berikut didokumentasikan berdasarkan hasil program yang dijalankan. Tangkapan layar menampilkan proses dan keluaran aktual.

# 1. Mengisi produk
Program dijalankan dengan memilih menu 2. Produk bernama nasi goreng ditambahkan dengan harga Rp15.000 dan stok 24. Program menampilkan pesan bahwa produk berhasil ditambahkan.

<img width="908" height="457" alt="1" src="https://github.com/user-attachments/assets/bc6b8677-7aca-4b1d-91de-59057afd62ff" />

# 2. Transaksi beberapa jenis produk
Program dijalankan dengan memilih menu 4 dan memasukkan 3 jenis produk. Point Coffe sebanyak 5 unit berhasil diproses. Pembelian Seafood Tumpah sebanyak 5 unit ditolak karena stok yang tersedia hanya 4. Daging Wagyu A5 sebanyak 5 unit berhasil diproses.

<img width="765" height="847" alt="2" src="https://github.com/user-attachments/assets/f3084d04-9ab3-4374-8c77-fa3e31871e06" />
<img width="750" height="141" alt="3" src="https://github.com/user-attachments/assets/59ade762-7a09-4c13-ab82-6289598a8989" />

Struk menampilkan subtotal Point Coffe sebesar Rp90.000 dan Daging Wagyu A5 sebesar Rp7.500.000, sehingga total pembayaran menjadi Rp7.590.000.

# 4. pasang stok
Menu 5 digunakan untuk menambah stok Point Coffe sebanyak 30 unit. Sebelum penambahan, stok Point Coffe sebanyak 25 unit. Program yang menampilkan pesan bahwa stok berhasil ditambahkan.

<img width="728" height="568" alt="4" src="https://github.com/user-attachments/assets/7ba8fbc9-ffb8-4283-a950-a61850402aa1" />

# 5. Menguji stok yang tidak mencukupi
Pada menu transaksi, dilakukan percobaan pembelian 6 unit Roti Aroma, sedangkan stok yang tersedia hanya 4 unit. Program menampilkan pesan “Stok produk tidak mencukupi!” dan transaksi tidak diproses.

<img width="678" height="693" alt="5" src="https://github.com/user-attachments/assets/57f69f3a-a2bf-4ef0-ba48-08e3f5ced50f" />

# 6. Menampilkan laporan penjualan
Menu 8 menampilkan jumlah penjualan dan pendapatan setiap produk. Berdasarkan hasil pengujian, total unit terjual adalah 70 unit, total pendapatan Rp31.410.000, dan produk terlaris adalah Es Orange sebanyak 20 unit.

<img width="738" height="567" alt="6" src="https://github.com/user-attachments/assets/4c1ed0b3-8cb9-42b4-86af-976be6884b74" />

# 7. Mengurutkan produk
Menu 7 digunakan untuk menguji dua jenis pengurutan. Pilihan pertama mengurutkan produk berdasarkan harga termurah.

<img width="670" height="625" alt="7" src="https://github.com/user-attachments/assets/0973810d-5694-4528-bef8-8cc4e30dc24d" />

Pilihan kedua mengurutkan produk berdasarkan jumlah penjualan terbanyak.

<img width="685" height="626" alt="8" src="https://github.com/user-attachments/assets/b2dd7b31-6c4b-49c6-8321-53380f4bb87a" />

# 7. Mencari produk dan memeriksa menipisnya persediaan
Menu 6 digunakan untuk mencari produk dengan kata kunci “roti aroma” . Program berhasil menampilkan produk Roti Aroma, harga Rp10.000, dan stok 4. dan seafood tumpah, harga Rp125.000, dan stock 4 

<img width="488" height="442" alt="9" src="https://github.com/user-attachments/assets/637e6e3f-45bd-448f-b55d-2005423f1d4a" />

<img width="488" height="417" alt="10" src="https://github.com/user-attachments/assets/1d0df554-9d5e-4bf6-91ff-c2a35e9733a4" />




