# **Tugas Besar IF2111 Algoritma dan Struktur Data**

## Deskripsi Program
PURRMART adalah aplikasi simulasi e-commerce berbasis CLI (command-line interface) yang dikembangkan sebagai tugas besar mata kuliah Algoritma dan Struktur Data STI. Aplikasi ini dirancang dalam konteks misi rahasia OWCA (Organization Without a Cool Acronym) untuk menghentikan rencana jahat Dr. Asep Spakbor yang ingin menghancurkan tiga wilayah negara bagian dengan mesin "Oppenheimer-inator".

Fitur utama PURRMART meliputi:
- Menampilkan dan mengelola barang di toko
- Meminta dan menyuplai barang baru
- Menyimpan dan membeli barang dalam keranjang
- Menampilkan riwayat pembelian
- Membuat dan menghapus wishlist
- Sistem kerja untuk menghasilkan uang

## Anggota Kelompok
- Ahmad Evander Ruizhi Xavier	/ 18223064
- Nazwan Siddqi Muttaqin	/ 18223066
- Keane Putra Lim	/ 18223056
- Sebastian Albern Nugroho	/ 18223074
- Joan Melkior Silaen	/ 18223102

## Cara Kompilasi dan Menjalankan Program

### Prasyarat
- Pastikan Anda telah menginstal `make`
- Windows: Gunakan MinGW atau Cygwin
- Linux: Biasanya sudah terinstal, jika tidak jalankan `sudo apt-get install make`
- macOS: Instal melalui Xcode Command Line Tools
  
### Metode 1: Kompilasi dengan Makefile
1. Pastikan Anda telah menginstal `make`
2. Berada di direktori utama proyek
3. Jalankan perintah kompilasi:
 ```bash
 make -C bin
 ```
4. Jalankan program:
 ```bash
 ./main
 ```

### Metode 2: Kompilasi menggunakan compiler.txt

#### Untuk Windows:
1. Ubah `compiler.txt` menjadi `compiler.bat`
2. Jalankan file batch:
 ```
 compiler.bat
 ```
3. Jalankan program:
 ```
 ./main
 ```

#### Untuk Linux/macOS:
1. Ubah `compiler.txt` menjadi `compiler.sh`
2. Berikan izin eksekusi:
 ```bash
 chmod +x compiler.sh
 ```
3. Jalankan script shell:
 ```bash
 ./compiler.sh
 ```
4. Jalankan program:
 ```bash
 ./main
 ```

### Catatan Penting
- Pastikan Anda memiliki GCC atau kompiler C yang kompatibel
- Untuk Windows, gunakan MinGW atau Cygwin jika tidak memiliki kompiler bawaan
