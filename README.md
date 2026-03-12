# DP-Week2-5224600045-Naufal Dwi Kurnia

# Task 2 - Domino Classic Core Loop

## Core Loop
Core loop pada game domino klasik yang saya buat dimulai dari menentukan pemain yang sedang mendapat giliran. Setelah itu, sistem akan mengecek kartu di tangan pemain untuk melihat apakah ada kartu yang bisa dimainkan sesuai dengan ujung domino yang terbuka di board. Jika ada kartu yang cocok, pemain akan memainkan salah satu kartu tersebut. Jika tidak ada, pemain akan melakukan pass.

Setelah pemain memilih aksi, sistem akan memvalidasi apakah kartu yang dimainkan memang sesuai aturan. Jika valid, kartu akan diletakkan ke board dan dihapus dari tangan pemain. Setelah itu, sistem akan mengecek apakah permainan sudah selesai, misalnya karena salah satu pemain sudah kehabisan kartu. Jika belum selesai, giliran akan berpindah ke pemain berikutnya dan proses yang sama akan diulang lagi.

## Invariant Structure
Bagian yang invariant dari program ini adalah alur utama permainan. Urutan seperti menentukan giliran pemain, mengecek kemungkinan langkah, memvalidasi aksi, memperbarui board, mengecek kondisi akhir, lalu memindahkan giliran ke pemain berikutnya harus selalu tetap. Urutan ini merupakan inti dari permainan domino klasik. Kalau urutannya diubah, maka permainan tidak akan berjalan dengan benar karena state permainan bisa menjadi tidak konsisten.

## Mutable Parts
Ada beberapa bagian dari program yang menurut saya termasuk mutable, yaitu bagian yang bisa diubah tanpa merusak struktur utama permainan.

1. Strategi memilih kartu
   Saat ini pemain memainkan kartu pertama yang valid. Strategi ini bisa diubah menjadi strategi acak atau strategi yang lebih pintar.

2. Kondisi akhir permainan
   Saat ini permainan selesai ketika salah satu pemain kehabisan kartu. Aturan ini bisa dikembangkan lagi, misalnya menambahkan kondisi blocked game.

3. Batas ronde maksimum
   Program saat ini memakai batas ronde tertentu agar loop tidak berjalan terus-menerus. Nilai ini bisa diubah tanpa memengaruhi core loop utama.

## Reflection
Dalam program ini, saya menempatkan struktur invariant pada class `GameSession` karena class tersebut bertugas mengatur jalannya permainan dari awal sampai akhir. `GameSession` tidak berisi semua detail aturan, tetapi lebih berfungsi sebagai pengatur alur permainan. Setiap giliran selalu mengikuti urutan yang sama, yaitu memilih pemain aktif, mengecek kartu yang bisa dimainkan, memvalidasi langkah, memperbarui board, mengecek kondisi akhir, lalu memindahkan giliran ke pemain berikutnya. Menurut saya, bagian inilah yang menjadi inti dari permainan domino klasik, sehingga harus tetap dijaga dan tidak boleh berubah.

Sementara itu, bagian mutable adalah bagian yang masih bisa diganti atau dikembangkan tanpa harus mengubah struktur utama program. Contohnya adalah strategi pemain dalam memilih kartu, kondisi akhir permainan, dan batas ronde maksimum. Pada versi sekarang, pemain menggunakan strategi paling sederhana, yaitu memainkan kartu pertama yang valid. Namun strategi tersebut bisa saja diganti menjadi lebih kompleks, misalnya memilih kartu terbaik atau menggunakan strategi acak. Hal yang sama juga berlaku untuk aturan akhir permainan. Saat ini permainan hanya berhenti ketika ada pemain yang kehabisan kartu, tetapi ke depannya aturan itu bisa diperluas dengan blocked game atau sistem perhitungan skor.

Kalau saya menambahkan fitur baru, perubahan seharusnya lebih banyak terjadi pada class pendukung seperti `MoveValidator`, `Player`, atau strategi permainan, bukan pada `GameSession`. Dengan cara ini, `GameSession` tetap menjadi pengatur utama yang menjaga core loop permainan. Menurut saya, desain seperti ini membuat program lebih rapi, lebih mudah dipahami, dan lebih mudah dikembangkan jika nanti ada perubahan aturan atau penambahan fitur.