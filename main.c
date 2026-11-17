
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUK 50
#define MAX_NAMA 50

char namaProduk[MAX_PRODUK][MAX_NAMA];
int hargaProduk[MAX_PRODUK];
int stokProduk[MAX_PRODUK];
int terjualProduk[MAX_PRODUK];

int jumlahData = 0;

// Membersihkan input
void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Mengubah string menjadi huruf kecil
void hurufKecil(char teks[]) {
    for (int i = 0; teks[i] != '\0'; i++) {
        teks[i] = (char)tolower((unsigned char)teks[i]);
    }
}

// Data awal produk
void inisialisasiData() {
    strcpy(namaProduk[0], "Point Coffe");
    hargaProduk[0] = 18000;
    stokProduk[0] = 30;
    terjualProduk[0] = 5;

    strcpy(namaProduk[1], "Roti Aroma");
    hargaProduk[1] = 10000;
    stokProduk[1] = 4;
    terjualProduk[1] = 12;

    strcpy(namaProduk[2], "Es Orange");
    hargaProduk[2] = 5000;
    stokProduk[2] = 44;
    terjualProduk[2] = 20;

    strcpy(namaProduk[3], "Seafood Tumpah");
    hargaProduk[3] = 125000;
    stokProduk[3] = 4;
    terjualProduk[3] = 8;

    strcpy(namaProduk[4], "Daging Wagyu A5");
    hargaProduk[4] = 1500000;
    stokProduk[4] = 49;
    terjualProduk[4] = 15;

    jumlahData = 5;
}

// Menampilkan daftar produk
void lihatProduk() {
    printf("\n========== DAFTAR PRODUK ==========\n");

    if (jumlahData == 0) {
        printf("Belum ada produk.\n");
        return;
    }

    printf("%-5s %-25s %-15s %-10s %-10s\n",
           "No", "Nama Produk", "Harga", "Stok", "Terjual");

    for (int i = 0; i < jumlahData; i++) {
        printf("%-5d %-25s Rp%-13d %-10d %-10d\n",
               i + 1, namaProduk[i], hargaProduk[i],
               stokProduk[i], terjualProduk[i]);
    }
}

// Menambah produk
void tambahProduk() {
    if (jumlahData >= MAX_PRODUK) {
        printf("Kapasitas produk sudah penuh!\n");
        return;
    }

    printf("\n========== TAMBAH PRODUK ==========\n");

    bersihkanBuffer();

    printf("Nama produk : ");
    fgets(namaProduk[jumlahData], MAX_NAMA, stdin);
    namaProduk[jumlahData][strcspn(namaProduk[jumlahData], "\n")] = '\0';

    if (strlen(namaProduk[jumlahData]) == 0) {
        printf("Nama produk tidak boleh kosong!\n");
        return;
    }

    printf("Harga       : ");
    if (scanf("%d", &hargaProduk[jumlahData]) != 1 ||
        hargaProduk[jumlahData] < 0) {
        printf("Harga tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    printf("Stok        : ");
    if (scanf("%d", &stokProduk[jumlahData]) != 1 ||
        stokProduk[jumlahData] < 0) {
        printf("Stok tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    terjualProduk[jumlahData] = 0;
    jumlahData++;

    printf("Produk berhasil ditambahkan!\n");
}

// Mengubah produk
void ubahProduk() {
    int nomor, harga, stok;

    lihatProduk();

    if (jumlahData == 0) return;

    printf("\nNomor produk yang ingin diubah: ");

    if (scanf("%d", &nomor) != 1 ||
        nomor < 1 || nomor > jumlahData) {
        printf("Nomor produk tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    int idx = nomor - 1;

    printf("Harga baru: ");
    if (scanf("%d", &harga) != 1 || harga < 0) {
        printf("Harga tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    printf("Stok baru: ");
    if (scanf("%d", &stok) != 1 || stok < 0) {
        printf("Stok tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    hargaProduk[idx] = harga;
    stokProduk[idx] = stok;

    printf("Produk berhasil diperbarui!\n");
}

// Transaksi penjualan
void transaksiPenjualan() {
    int nomor, qty;
    int jumlahItem;
    int itemBeli[50], qtyBeli[50];
    int valid = 0;
    long total = 0;

    lihatProduk();

    if (jumlahData == 0) return;

    printf("\n========== TRANSAKSI PENJUALAN ==========\n");
    printf("Jumlah jenis produk yang dibeli: ");

    if (scanf("%d", &jumlahItem) != 1 ||
        jumlahItem <= 0 || jumlahItem > 50) {
        printf("Jumlah tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    for (int i = 0; i < jumlahItem; i++) {
        printf("\nItem ke-%d\n", i + 1);

        printf("Nomor produk: ");
        if (scanf("%d", &nomor) != 1 ||
            nomor < 1 || nomor > jumlahData) {
            printf("Nomor produk tidak valid!\n");
            bersihkanBuffer();
            continue;
        }

        printf("Jumlah beli: ");
        if (scanf("%d", &qty) != 1 || qty <= 0) {
            printf("Jumlah pembelian tidak valid!\n");
            bersihkanBuffer();
            continue;
        }

        int idx = nomor - 1;
        int sudahDipesan = 0;

        for (int j = 0; j < valid; j++) {
            if (itemBeli[j] == idx) {
                sudahDipesan = 1;
                break;
            }
        }

        int totalQty = qty;

        if (sudahDipesan) {
            for (int j = 0; j < valid; j++) {
                if (itemBeli[j] == idx) {
                    totalQty += qtyBeli[j];
                    break;
                }
            }
        }

        if (totalQty > stokProduk[idx]) {
            printf("Stok produk tidak mencukupi!\n");
            continue;
        }

        if (sudahDipesan) {
            for (int j = 0; j < valid; j++) {
                if (itemBeli[j] == idx) {
                    qtyBeli[j] += qty;
                    break;
                }
            }
        } else {
            itemBeli[valid] = idx;
            qtyBeli[valid] = qty;
            valid++;
        }
    }

    if (valid == 0) {
        printf("\nTidak ada transaksi yang berhasil.\n");
        return;
    }

    printf("\n========== STRUK PEMBAYARAN ==========\n");

    for (int i = 0; i < valid; i++) {
        int idx = itemBeli[i];
        int qty = qtyBeli[i];

        long subtotal = (long)hargaProduk[idx] * qty;
        total += subtotal;

        printf("%-20s x %d = Rp%ld\n",
               namaProduk[idx], qty, subtotal);

        stokProduk[idx] -= qty;
        terjualProduk[idx] += qty;
    }

    printf("--------------------------------------\n");
    printf("Total pembayaran: Rp%ld\n", total);
    printf("Transaksi berhasil!\n");
}

// Menambah stok
void tambahStok() {
    int nomor, tambahan;

    lihatProduk();

    if (jumlahData == 0) return;

    printf("\nNomor produk: ");

    if (scanf("%d", &nomor) != 1 ||
        nomor < 1 || nomor > jumlahData) {
        printf("Nomor tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    printf("Jumlah tambahan stok: ");

    if (scanf("%d", &tambahan) != 1 || tambahan <= 0) {
        printf("Jumlah stok tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    stokProduk[nomor - 1] += tambahan;

    printf("Stok berhasil ditambahkan!\n");
}

// Mencari produk
void cariProduk() {
    char cari[MAX_NAMA];
    char nama[MAX_NAMA];
    int ketemu = 0;

    bersihkanBuffer();

    printf("\nMasukkan nama produk: ");
    fgets(cari, MAX_NAMA, stdin);
    cari[strcspn(cari, "\n")] = '\0';

    hurufKecil(cari);

    printf("\n========== HASIL PENCARIAN ==========\n");

    for (int i = 0; i < jumlahData; i++) {
        strcpy(nama, namaProduk[i]);
        hurufKecil(nama);

        if (strstr(nama, cari) != NULL) {
            printf("%d. %s | Harga: Rp%d | Stok: %d\n",
                   i + 1, namaProduk[i],
                   hargaProduk[i], stokProduk[i]);
            ketemu = 1;
        }
    }

    if (!ketemu) {
        printf("Produk tidak ditemukan!\n");
    }
}

// Mengurutkan produk
void urutkanProduk() {
    int pilihan;

    printf("\n========== URUTKAN PRODUK ==========\n");
    printf("1. Harga termurah\n");
    printf("2. Penjualan terbanyak\n");
    printf("Pilih: ");

    if (scanf("%d", &pilihan) != 1 ||
        (pilihan != 1 && pilihan != 2)) {
        printf("Pilihan tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {

            int tukar = 0;

            if (pilihan == 1 &&
                hargaProduk[j] > hargaProduk[j + 1]) {
                tukar = 1;
            }

            if (pilihan == 2 &&
                terjualProduk[j] < terjualProduk[j + 1]) {
                tukar = 1;
            }

            if (tukar) {
                char tempNama[MAX_NAMA];
                strcpy(tempNama, namaProduk[j]);
                strcpy(namaProduk[j], namaProduk[j + 1]);
                strcpy(namaProduk[j + 1], tempNama);

                int temp;

                temp = hargaProduk[j];
                hargaProduk[j] = hargaProduk[j + 1];
                hargaProduk[j + 1] = temp;

                temp = stokProduk[j];
                stokProduk[j] = stokProduk[j + 1];
                stokProduk[j + 1] = temp;

                temp = terjualProduk[j];
                terjualProduk[j] = terjualProduk[j + 1];
                terjualProduk[j + 1] = temp;
            }
        }
    }

    printf("Produk berhasil diurutkan!\n");
    lihatProduk();
}

// Laporan penjualan
void laporanPenjualan() {
    long totalUnit = 0;
    long totalPendapatan = 0;
    int terlaris = -1;

    printf("\n========== LAPORAN PENJUALAN ==========\n");

    if (jumlahData == 0) {
        printf("Belum ada produk.\n");
        return;
    }

    for (int i = 0; i < jumlahData; i++) {
        long subtotal = (long)terjualProduk[i] * hargaProduk[i];

        totalUnit += terjualProduk[i];
        totalPendapatan += subtotal;

        printf("%s | Terjual: %d | Pendapatan: Rp%ld\n",
               namaProduk[i], terjualProduk[i], subtotal);

        if (terlaris == -1 ||
            terjualProduk[i] > terjualProduk[terlaris]) {
            terlaris = i;
        }
    }

    printf("---------------------------------------\n");
    printf("Total unit terjual: %ld\n", totalUnit);
    printf("Total pendapatan: Rp%ld\n", totalPendapatan);

    if (terlaris != -1 && terjualProduk[terlaris] > 0) {
        printf("Produk terlaris: %s (%d unit)\n",
               namaProduk[terlaris],
               terjualProduk[terlaris]);
    } else {
        printf("Belum ada produk terjual.\n");
    }
}

// Mengecek stok menipis
void cekStokMenipis() {
    int ada = 0;

    printf("\n========== STOK MENIPIS ==========\n");

    for (int i = 0; i < jumlahData; i++) {
        if (stokProduk[i] < 5) {
            printf("%s | Sisa stok: %d\n",
                   namaProduk[i], stokProduk[i]);
            ada = 1;
        }
    }

    if (!ada) {
        printf("Semua stok produk masih mencukupi.\n");
    }
}

// Program utama
int main() {
    int pilihan;

    inisialisasiData();

    do {
        printf("\n========================================\n");
        printf(" SISTEM MONITORING STOK DAN PENJUALAN\n");
        printf("========================================\n");
        printf("1. Lihat Daftar Produk\n");
        printf("2. Tambah Produk\n");
        printf("3. Ubah Produk\n");
        printf("4. Transaksi Penjualan\n");
        printf("5. Tambah Stok\n");
        printf("6. Cari Produk\n");
        printf("7. Urutkan Produk\n");
        printf("8. Laporan Penjualan\n");
        printf("9. Cek Stok Menipis\n");
        printf("0. Keluar\n");
        printf("----------------------------------------\n");
        printf("Pilih menu: ");

        if (scanf("%d", &pilihan) != 1) {
            printf("Input harus berupa angka!\n");
            bersihkanBuffer();
            continue;
        }

        switch (pilihan) {
            case 1:
                lihatProduk();
                break;

            case 2:
                tambahProduk();
                break;

            case 3:
                ubahProduk();
                break;

            case 4:
                transaksiPenjualan();
                break;

            case 5:
                tambahStok();
                break;

            case 6:
                cariProduk();
                break;

            case 7:
                urutkanProduk();
                break;

            case 8:
                laporanPenjualan();
                break;

            case 9:
                cekStokMenipis();
                break;

            case 0:
                printf("Terima kasih telah menggunakan program!\n");
                break;

            default:
                printf("Pilihan menu tidak tersedia!\n");
        }

    } while (pilihan != 0);

    return 0;
}
