#include "ADT.h"

//Circular List

void createListP(listPasien &L){
/*  I.S : list pasien belum terbentuk
    F.s : list pasien terdeklarasi / terbentuk */

    first(L) = NULL;
    last(L) = NULL;
}

void insertPasien(listPasien &L, listRelasi &R, listDokter D){
/*  I.S : list pasien, list relasi, list dokter kosong ataupun terisi
    F.s : list pasien tertambah 1 elemen pasien, list relasi bertambah (opsional) */
    addressP P = new elmPasien;
    P->info.jumDokter = 0;
    next(P) = NULL;
    //Data Pasien
    Validnama(info(P).nama);
    cout<<"Masukkan Umur : ";
    cin>>P->info.umur;
    cout<<"Masukkan Berat : ";
    cin>>P->info.berat;

    //Data Dokter Pasien (Membuat Relasi)
    if (first(D) != NULL){
        int temp; //untuk menyimpan codeid dokter
        cout<<"Dokter yang tersedia"<<endl;
        showD(D);
        cout<<"Dokter apa saja yang anda ingikan (masukkan ID, masukkan -1 jika tidak ingin atau sudah selesai memasukkan) :"<<endl;
        cin>>temp;
        while ((temp != -1) && (P->info.jumDokter < 5) && cekAda(R, temp, P)){
            addressD Q = findIDD(D, temp);
            insertRelasi(R, Q, P);
            Q->info.jumpasien = Q->info.jumpasien + 1;
            P->info.jumDokter = P->info.jumDokter + 1;
            cin>>temp;
        }
    }

    //insert Last
    if (first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
        last(L) = P;
    } else {
        next(P) = first(L);
        next(last(L)) = P;
        last(L) = P;
    }

}

void deletePasien(listPasien &L, listRelasi &R){
/*  I.S : list pasien dan list relasi kosong ataupun terisi
    F.s : Didalam list Pasien terhapus 1 elemen pasien, dan semua relasi dalam list relasi terhapus */
    namaLengkap temp;
    cout<<"Masukkan nama pasien yang ingin dihapus :"<<endl;
    Validnama(temp);

    addressP P = first(L);
    bool ketemu = false;
    //Mencari Pasien
    do {
        if (P->info.nama[0] == temp[0] && P->info.nama[1] == temp[1]){
            ketemu = true;
        } else {
            P = next(P);
        }

    } while (P != first(L) && !(ketemu));

    if (P == NULL){
        cout<<"Maaf nama pasien tidak ditemukan"<<endl;
    } else  {
        cout<<P->info.nama[1]<<endl;
        //Menghapus relasi
        deleteRelasi(R, NULL, P, NULL);
        //Menghapus elemen pasien
        if (P == next(P)){
            first(L) = NULL;
            last(L) = NULL;
            next(P) =NULL;
            delete P;
            cout<<"Pasien berhasil dihapus (kode 1)"<<endl;
        } else {
            addressP T = first(L);
            do {
                T = next(T);
            } while (next(T) != P);

            if (P == first(L)){ //Kalau elemennya di first(L)
                first(L) = next(P);
                next(T) = first(L);
                next(P) = NULL;
                last(L) = T;
                cout<<"Pasien berhasil dihapus (Kode 2)"<<endl;
            } else {
                next(T) = next(P);
                if (P == last(L)){
                    last(L) = T;
                }
                next(P) = NULL;
                cout<<"Pasien berhasil dihapus (Kode 3)"<<endl;
            }
            delete P;
        }
    }
}

void tambahDokterPasien(listRelasi &R, listPasien &L, listDokter D){
/*  I.S : listRelasi, listPasien, dan listDokter ada atau mungkin kosong
    F.s : Didalam list relasi, tertambah relasi yang pasienkan inginkan */
    namaLengkap temp;
    cout<<"Nama pasien : "<<endl;
    Validnama(temp);

    addressP P = first(L);
    bool ketemu = false;
    //Mencari Pasien
    do {
        if (P->info.nama[1] == temp[1] && P->info.nama[0] == temp[0]){
            ketemu = true;
        } else {
            P = next(P);
        }
    } while (P != first(L) && !(ketemu));

    if (ketemu == false){
        cout<<"Maaf nama pasien tidak ditemukan"<<endl;
    } else {
        int dokter; //untuk menyimpan codeid dokter
        cout<<"Dokter yang tersedia"<<endl;
        showD(D);
        cout<<"Dokter apa saja yang anda ingikan (masukkan ID, masukkan -1 jika tidak ingin atau sudah selesai memasukkan) :"<<endl;
        cin>>dokter;
        while (dokter != -1 && P->info.jumDokter < 5){
            addressD Q = findIDD(D, dokter);
            insertRelasi(R, Q, P);
            Q->info.jumpasien = Q->info.jumpasien + 1;
            P->info.jumDokter = P->info.jumDokter + 1;
            cin>>dokter;
        }
    }
}

void tampilRelasiPasien(listPasien L, listRelasi R){
/*  I.S : listRelasi, listPasien ada atau mungkin kosong
    F.s : Menampilkan semua relasi yang dimiliki oleh pasien */
    namaLengkap temp;
    cout<<"Nama pasien : "<<endl;
    Validnama(temp);

    addressP P = first(L);
    bool ketemu = false;
    //Mencari Pasien
    do {
        if (P->info.nama[1] == temp[1] && P->info.nama[0] == temp[0]){
            ketemu = true;
        } else {
            P = next(P);
        }
    } while (P != first(L) && !(ketemu));
    clearscreen();
    if (ketemu == false){
        cout<<"Maaf nama pasien tidak ditemukan"<<endl;
    } else {
        cout<<"Pasien ditemukan"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Nama Pasien : "<<P->info.nama[0]<<" "<<P->info.nama[1]<<endl;
        cout<<"Umur Pasien : "<<P->info.umur<<endl;
        cout<<"Berat Pasien : "<<P->info.berat<<endl;
        cout<<"Banyak relasi dokter : "<<P->info.jumDokter<<endl;


        if (first(R) == NULL || P->info.jumDokter == 0){
            cout<<"Tidak ada dokter yang berelasi dengan pasien"<<endl;
        } else {
            addressR Q = first(R);
            cout<<"Relasi dokter : "<<endl;
            while (Q != NULL){
                if (Q->info.Pasien == P){
                    cout<<(Q->info.dokter->info.nama[0])<<" "<<(Q->info.dokter->info.nama[1])<<" Spesialis "<<(Q->info.dokter->info.specialist)<<" Dengan ID "<<(Q->info.dokter->info.Codeid)<<endl;
                }
                Q = next(Q);
            }
        }
    }
}

void hapusRelasiPasien(listPasien L, listRelasi &R){
/*  I.S : listRelasi, listPasien ada atau mungkin kosong
    F.s : Terhapus satu elemen relasi pada listRelasi */
    namaLengkap temp;
    cout<<"Nama pasien : ";
    Validnama(temp);

    addressP P = first(L);
    bool ketemu = false;
    //Mencari Pasien
    do {
        if (P->info.nama == temp){
            ketemu = true;
        } else {
            P = next(P);
        }
    } while (P != first(L) && !(ketemu));

    if (P == NULL){
        cout<<"Maaf nama pasien tidak ditemukan"<<endl;
    } else {
        cout<<"Pasien ditemukan"<<endl;
        cout<<endl;
        cout<<"Nama Pasien : "<<P->info.nama[0]<<" "<<P->info.nama[1]<<endl;
        cout<<"Umur Pasien : "<<P->info.umur<<endl;
        cout<<"Berat Pasien : "<<P->info.berat<<endl;
        cout<<"Banyak relasi dokter : "<<P->info.jumDokter<<endl;


        if (first(R) == NULL || P->info.jumDokter == 0){
            cout<<"Tidak ada dokter yang berelasi dengan pasien"<<endl;
        } else {
            addressR Q = first(R);
            cout<<"Relasi dokter : "<<endl;
            while (Q != NULL){
                if (Q->info.Pasien == P){
                    cout<<"Codeid Dokter: "<<(Q->info.dokter->info.Codeid)<<" | Nama: "<<(Q->info.dokter->info.nama)<<" | Specialist: "<<(Q->info.dokter->info.nama)<<endl;
                }
                Q = next(Q);
            }
            int dokter;
            cout<<"Masukkan ID dokter yang ingin dihapus : ";
            cin>>dokter;

            //Menghapus 1 Relasi
            addressR S = first(R);
            ketemu = false;
            while (S != NULL && !(ketemu)){
                if ((S->info.dokter->info.Codeid == dokter) && (S->info.Pasien == P)){
                    ketemu = true;
                } else {
                    S = next(S);
                }
            }
            if (ketemu == false){
                cout<<"Maaf dokter tidak ditemukan harap coba lagi"<<endl;
            } else {
                deleteRelasi(R, NULL, NULL, S);
                P->info.jumDokter = P->info.jumDokter - 1;
            }
        }
    }
}

void tampilSemuaPasien(listPasien L, listRelasi R){
/*  I.S : listRelasi, listPasien ada atau mungkin kosong
    F.s : Menampilkan semua informasi semua pasien */
    if (first(L) == NULL){
        cout<<"List Kosong (Pasien)"<<endl;
    } else {
        //Var
        int counter = 0;
        addressR Q;
        addressP P = first(L);
        do {
            cout<<"Pasien "<<counter + 1<<endl;
            cout<<"Nama     : "<<P->info.nama[0]<<" "<<P->info.nama[1]<<endl;
            cout<<"Umur     : "<<P->info.umur<<endl;
            cout<<"Berat    : "<<P->info.berat<<endl;
            cout<<"Jumlah Dokter yang terhubung : "<<P->info.jumDokter<<endl;
            cout<<"Dokter yang terhubung :"<<endl;
            Q = first(R);
            if (Q == NULL){
                cout<<"List Relasi Kosong"<<endl;
            } else {
                while (Q != NULL){
                    if (Q->info.Pasien == P){
                        cout<<"Dokter : "<<Q->info.dokter->info.nama[0]<<Q->info.dokter->info.nama[1]<<" | Spesialis : "<<Q->info.dokter->info.specialist<<endl;
                    }
                    Q = next(Q);
                }
            }
            cout<<endl;
            counter = counter + 1;
            P = next(P);
        } while (P != first(L));
    }
}

void tampilSatuPasien(listPasien L ,listRelasi R){
/*  I.S : listRelasi, listPasien ada atau mungkin kosong
    F.s : Menampilkan semua informasi satu pasien */
    if (first(L) == NULL){
        cout<<"List Kosong (Pasien)"<<endl;
    } else {
        namaLengkap temp;
        cout<<"Masukkan nama Pasien : ";
        Validnama(temp);
        //Var
        addressP P;
        addressR Q;
        bool ketemu = false;
        P = first(L);
        do {
            if (P->info.nama[1] == temp[1] && P->info.nama[0] == temp[0]){
                ketemu = true;
            } else {
                P = next(P);
            }
        } while (P != NULL && !(ketemu));
        if (ketemu){
            cout<<"Pasien "<<endl;
            cout<<"Nama     : "<<P->info.nama[0]<<" "<<P->info.nama[1]<<endl;
            cout<<"Umur     : "<<P->info.umur<<endl;
            cout<<"Berat    : "<<P->info.berat<<endl;
            cout<<"Jumlah Dokter yang terhubung : "<<P->info.jumDokter<<endl;
            cout<<"Dokter yang terhubung :"<<endl;
            Q = first(R);
            if (Q == NULL){
                cout<<"List Relasi Kosong"<<endl;
            } else {
                while (Q != NULL){
                    if (Q->info.Pasien == P){
                        cout<<"Dokter : "<<Q->info.dokter->info.nama[0]<<Q->info.dokter->info.nama[1]<<" | Spesialis : "<<Q->info.dokter->info.specialist<<endl;
                    }
                    Q = next(Q);
                }
            }
        } else {
            cout<<"Maaf pasien tidak ditemukan"<<endl;
        }
    }
}
