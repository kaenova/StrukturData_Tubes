#include "ADT.h"

/*Address
typedef struct elmPasien *addressP;
typedef struct elmDokter *addressD;
typedef struct elmRelasi *addressR;


//Dokter
struct Dokter {
    int Codeid;
    string nama;
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
*/


void createListD (listDokter &L){
/*  I.S : listDokter Belum terbentuk
    F.s : Terbentuknya sebuah listDokter */
    first(L) = NULL;
    last(L) = NULL;
}

void insertDokter (listDokter &L){
/*  I.S : Teridefinisi sebuah listDokter yang mungkin kosong atau sudah berisi Element
    F.s : Element dalam listDokter Terurut berdasarkan Codeid Dokter */
        addressD D = new elmDokter;
        next(D) = NULL;
        cout<<"Codeid :";
        if (first(L) == NULL){
            info(D).Codeid = 1;
        }else{
            addressD a;
            a = last(L);
            info(D).Codeid = info(a).Codeid + 1;
        }
        cout<<info(D).Codeid<<endl;
        Validnama(info(D).nama);
        cout<<"Specialist : ";
        cin>>info(D).specialist;
        D->info.jumpasien = 0;
        if (first(L) == NULL){
             first(L) = D;
             last(L) = D;
        }else{
            //ascending
            if (info(D).Codeid < info(first(L)).Codeid){
                //insert first
                next(D) = first(L);
                first(L) = D;
            }else if (info(D).Codeid > info(last(L)).Codeid){
                //insert last
                next(last(L)) = D;
                last(L) = D;
            }else{
                //insert after modivikasi
                addressD Q = first(L);
                addressD p;
                p = Q;
                while ((next(Q) != NULL) && (info(Q).Codeid < info(D).Codeid)){
                    p = Q;
                    Q = next(Q);
                }
                next(D) = next(p);
                next(p) = D;
            }

        }
}

addressD findIDD (listDokter L, int id){
/*  I.S : Terdefinisi listDokter yang berisi element dan sebuah id yang ingin dicari
    F.s : Mengembalikan addressD dari hasil pencarian jika ditemukan
          dan mengembalikan NULL jika tidak ditemukan */
    if (first(L) != NULL){
        addressD hasil = first(L);
        while ((next(hasil) != NULL) && (info(hasil).Codeid != id)) {
            hasil = next(hasil);
        }
        if (info(hasil).Codeid == id) {
            return hasil;
        }
    }

    return NULL;
}

void deleteDokter (listDokter &L, listRelasi &R){
/*  I.S : Terdefinisi listDokter dan listRelasi yang mungkin kosong atau berisi
    F.s : Menghapus satu Element Dokter dan
          menghapus relasi pasien terhadap dokter yang bersangkutan*/
    int id;
    cout<<"Masukan ID : ";
    cin>>id;
    cout<<endl;
    if (first(L) != NULL){ //delete after modivikasi
        addressD M = findIDD(L,id);
        deleteRelasi(R, M, NULL, NULL);
        if (M == NULL){
            cout<<"tidak ketemu"<<endl;
        }else if ((first(L) == last(L)) && (first(L) == M)){ // 1 elm
            first(L) = NULL;
            last(L) = NULL;
            delete M;
        }else{ //banyak elm
            if (first(L) == M){ //klo ketemu di awal
                first(L) = next(first(L));
                next(M) = NULL;
                delete M;
            }else if (last(L) == M){ //klo ketemu di akhir
                addressD Z = first(L);
                while (next(Z) != last(L)){
                    Z = next(Z);
                }
                last(L) = Z;
                next(Z) = NULL;
                delete M;
            }else{
                addressD O = first(L);
                while (next(O) != M){
                    O = next(O);
                }
                next(O) = next(M);
                next(M) = NULL;
                delete M;
            }
        }
    }else{
        cout<<"Empty"<<endl;
    }
}

void showD (listDokter L){
/*  I.S : Terdefinisi listDokter
    F.s : Menampilkan Semua dokter beserta datanya */
    if (first(L) == NULL){
        cout<<"List Kosong (Dokter)"<<endl;
    } else {
        addressD K = first(L);
        while (K != NULL){
            cout<<"Codeid Dokter :"<<info(K).Codeid<<" | "<<"Nama Dokter :"<<info(K).nama[0]<<" "<<info(K).nama[1]<<" | "<<"Specialist :"<<info(K).specialist<<" | "<<"Jumlah pasien :"<<info(K).jumpasien<<endl;
            K = next(K);
        }
    }
}

void showPterhadapD(listRelasi R, listDokter D){
/*  I.S : Terdefinisi listRelasi dan listDokter yang berisi Element
    F.s : Menampilkan Semua Dokter yang berealasi pasien bersangkuatan */
    if (first(D) == NULL){
        cout<<"List Kosong (Dokter)"<<endl;
    }else{
        addressP P;
        addressD K = first(D);
        while (K != NULL){
            cout<<"Codeid Dokter :"<<info(K).Codeid<<" | "<<"Nama Dokter :"<<info(K).nama[0]<<" "<<info(K).nama[1]<<" | "<<"Specialist :"<<info(K).specialist<<endl;
            cout<<"terkait dengan pasien: "<<endl;
            addressR L = first(R);
            int i = 0;
            while (L != NULL){
                if (K == info(L).dokter){
                    P = info(L).Pasien;
                    cout<<i+1<<"."<<info(P).nama[0]<<" "<<info(P).nama[1]<<endl;
                    i++;
                }
                L = next(L);
                }
            cout<<endl;
            K = next(K);
        }
    }
}

void showPD(listRelasi R, listDokter D){
/*  I.S : Terdefinisi listRelasi dan listDokter yang berisi Element
    F.s : Menampilkan Semua Dokter yang berealasi pasien bersangkuatan */
    if (first(D) == NULL){
        cout<<"List Kosong (Dokter)"<<endl;
    }else{
        addressP P;
        int X;
        cout<<"Masukkan ID Dokter : ";
        cin>>X;
        addressD K = findIDD(D, X);
        if (K != NULL){
            cout<<"Codeid Dokter :"<<info(K).Codeid<<" | "<<"Nama Dokter :"<<info(K).nama[0]<<" "<<info(K).nama[1]<<" | "<<"Specialist :"<<info(K).specialist<<endl;
            cout<<"terkait dengan pasien: "<<endl;
            addressR L = first(R);
            int i = 0;
            while (L != NULL){
                if (K == info(L).dokter){
                    P = info(L).Pasien;
                    cout<<i+1<<"."<<info(P).nama[0]<<" "<<info(P).nama[1]<<endl;
                    i++;
                }
                L = next(L);
            }
        } else {
            cout<<"Dokter tidak ditemukan";
        }
        cout<<endl;
    }
}

