#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include "conio.h"
#include "stdlib.h"

using namespace std;

//List Relasi -> Double List            (Bareng)
//List Parent (Dokter) -> Single List   (Adi Ikfini)
//List Child (Pasien) -> Circullar List (Kaenova Mahendra)

#define next(P)     P->next
#define info(P)     P->info
#define prev(P)     P->prev
#define first(L)    L.first
#define last(L)     L.last

//Address
typedef struct elmPasien *addressP;
typedef struct elmDokter *addressD;
typedef struct elmRelasi *addressR;
typedef string namaLengkap[2];


//Dokter
struct Dokter {
    int Codeid, jumpasien;
    namaLengkap nama;
    string specialist;
};

typedef Dokter infotypeD;

struct elmDokter {
    infotypeD info;
    addressD next;
};

struct listDokter{
    addressD first;
    addressD last;
};


//Pasien
struct Pasien {
    int jumDokter, umur, berat;
    namaLengkap nama;
};

typedef Pasien infotypeP;

struct elmPasien {
    infotypeP info;
    addressP next;
};

struct listPasien {
    addressP first, last;
};


//Relasi
struct Relasi {
    addressD dokter;
    addressP Pasien;
};

typedef Relasi infotypeR;

struct elmRelasi {
    infotypeR info;
    addressR next;
    addressR prev;
};

struct listRelasi {
    addressR first;
    addressR last;
};


//body dokter
void createListD (listDokter &L);
/*  I.S : listDokter Belum terbentuk
    F.s : Terbentuknya sebuah listDokter */
void insertDokter (listDokter &L);
/*  I.S : Teridefinisi sebuah listDokter yang mungkin kosong atau sudah berisi Element
    F.s : Element dalam listDokter Terurut berdasarkan Codeid Dokter */
void deleteDokter (listDokter &L, listRelasi &R);
/*  I.S : Terdefinisi listDokter dan listRelasi yang mungkin kosong atau berisi
    F.s : Menghapus satu Element Dokter dan
          menghapus relasi pasien terhadap dokter yang bersangkutan*/
void showD (listDokter L);
/*  I.S : Terdefinisi listDokter
    F.s : Menampilkan Semua dokter beserta datanya */
addressD findIDD (listDokter L, int id);
/*  I.S : Terdefinisi listDokter yang berisi element dan sebuah id yang ingin dicari
    F.s : Mengembalikan addressD dari hasil pencarian jika ditemukan
          dan mengembalikan NULL jika tidak ditemukan */
void showPterhadapD(listRelasi R, listDokter D);
/*  I.S : Terdefinisi listRelasi dan listDokter yang berisi Element
    F.s : Menampilkan Semua Dokter yang berealasi pasien bersangkuatan */
void showPD(listRelasi R,listDokter D);
/*  I.S : Terdefinisi listRelasi dan listDokter yang berisi Element
    F.s : Menampilkan Semua Dokter yang berealasi pasien bersangkuatan */

//body pasien
void createListP(listPasien &L);
/*  I.S : list pasien belum terbentuk
    F.s : list pasien terdeklarasi / terbentuk */

void insertPasien(listPasien &L, listRelasi &R, listDokter D);
/*  I.S : list pasien, list relasi, list dokter kosong ataupun terisi
    F.s : list pasien tertambah 1 elemen pasien, list relasi bertambah (opsional) */

void deletePasien(listPasien &L, listRelasi &R);
/*  I.S : list pasien dan list relasi kosong ataupun terisi
    F.s : Didalam list Pasien terhapus 1 elemen pasien, dan semua relasi dalam list relasi terhapus */

void tambahDokterPasien(listRelasi &R, listPasien &L, listDokter D);
/*  I.S : listRelasi, listPasien, dan listDokter ada atau mungkin kosong
    F.s : Didalam list relasi, tertambah relasi yang pasienkan inginkan */

void tampilRelasiPasien(listPasien L, listRelasi R);
/*  I.S : listRelasi, listPasien ada atau mungkin kosong
    F.s : Menampilkan semua relasi yang dimiliki oleh pasien */

void hapusRelasiPasien(listPasien L, listRelasi &R);
/*  I.S : listRelasi, listPasien ada atau mungkin kosong
    F.s : Terhapus satu elemen relasi pada listRelasi */

void tampilSemuaPasien(listPasien L, listRelasi R);
/*  I.S : listRelasi, listPasien ada atau mungkin kosong
    F.s : Menampilkan semua informasi semua pasien */

void tampilSatuPasien(listPasien L, listRelasi R);
/*  I.S : listRelasi, listPasien ada atau mungkin kosong
    F.s : Menampilkan semua informasi satu pasien */


//body relasi
void createListR(listRelasi &L);
/*  I.S : list relasi belum terbentuk
    F.s : list relasi terbentuk */
void insertRelasi (listRelasi &L, addressD dokter, addressP pasien);
/*  I.S : list relasi terbentuk mungkin NULL, addressD tidak NULL, dan addressP tidak NULL
    F.S : tertambah satu elemen relasi pada list relasi */
void deleteRelasi (listRelasi &L, addressD D, addressP P, addressR R);
/*  I.S : list relasi terbentuk tidak NULL, addressD tidak mungkin NULL, dan addressP mungkin NULL, addressR mungkin NULL, tetapi addressD, addressP, dan addressR tidak boleh NULL
    F.s : tertambah satu elemen relasi pada list relasi */
void TampilRelasi (listRelasi L);
/*  I.S : Terdefinisi listRelasi
    F.s : menampilkan relasi antara pasien dan dokter yang bersangkutan */
addressR findrelasi (listRelasi L, addressD x);
bool cekAda (listRelasi L, int codeID, addressP X);
/* listRelasi mungkin NULL, mengembalikan boolean jika ada relasi */
void sorting(listDokter &L);
/*  I.S : Terdefinisi listDokter
    F.s : Mengurutkan dokter bedasarkan banyak pasien yang ditangani */


//Interface
void clearscreen();
void enter_to_continue();
void inisialisasi(listDokter &D, listPasien &P, listRelasi &R);
void Menu(listDokter &D, listPasien &P, listRelasi &R);
void Validnama(namaLengkap &nama);


/*
Note :
1. Kalau misalkan ingin menambahkan relasi, harus di cek apakah dokter spesialis nya ada atau tidak (v)
2. Jika segala delete(pasien atau dokter), Relasi harus diupdate lalu dihitung ulang jumDokter pada pasien (v)
3. Jika delete (pasien atau dokter), pertama kali yang harus di cek adalah list relasi yang bersangkutan dengan yang di delete. (v)
4. Counter pasien terhadap dokter hanya di update ketika menghapus dokter (deleteDokter). (Jangan LUPA) (v)
5. Validasi harus dibuat
6. Automasi ID dokter

ChangeLog (Kaenova) :
1. Membuat semua prosedur pasien
2. tolong ID dokter dibuat intefer saja agar mudah.
3. Jangan lupa tipe-tipe list nya agar tidak salah membuat insertfirst dkk.
4. Nyelesaiin deleteRelasi
5. Menambahkan parameter addressR &R pada prosedur deleteRelasi
6. Membuat procedure tampilPasien dan simpleInsertPasien untuk di test
7. Menambahkan #include <string> agar inputan spasi bisa kedetek sebagai 1 variabel bisa di cek pada Pasien.cpp line 20
8. Membuat tampilSatuPasien dan tampilSemuaPasien untuk Prosedur pasien
9. Menambahkan I.S dan F.s pada semua Pasien.cpp
10. Menambahkan Dasar algoritma sorting didalam Relasi.cpp
11. Membuat interface
12. Memindahkan valid nama ke interface.cpp
13. Membuat Press enter to continue


ChangeLog (Mahfud) :
1. Membuat semua prosedur dan fingsi Doktor
2. belum memvalidasi inputan user
3. prosedure showDiD di hapus karena akan di ganti mirip dengan prosedur tampilrelasi
4. menambahkan procedure findrelasi terhadap dekter
5. Code id pada strack telah menjadi int
6. menambah procedure Validnama
7. automatis Codeid pada insert dokter
8. mencoba validasi di semua procedure nama


Bug :


*/
#endif // ADT_H_INCLUDED
