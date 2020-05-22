#include "ADT.h"

void createListR(listRelasi &L){
/*  I.S : list relasi belum terbentuk
    F.s : list relasi terbentuk */
    first(L) = NULL;
    last(L) = NULL;
}

void deleteRelasi (listRelasi &L, addressD D, addressP P, addressR R){
/*  I.S : list relasi terbentuk tidak NULL, addressD tidak mungkin NULL, dan addressP mungkin NULL, addressR mungkin NULL, tetapi addressD, addressP, dan addressR tidak boleh NULL
    F.s : tertambah satu elemen relasi pada list relasi */
    if (first(L) == NULL) {
        cout<<"List relasi kosong (kode 0)"<<endl;
    } else if (R != NULL){
        //Menghapus satu relasi
        if (R == first(L)) {
            first(L) = next(R);
            next(R) = NULL;
            prev(first(L)) = NULL;
        } else {
            addressR T = first(L);
            while  (next(T) != R){
                T = next(T);
            }
            if (R == last(L)){
                prev(R) = NULL;
                next(T) = NULL;
            } else {
                next(T) = next(R);
                prev(next(T)) = T;
            }
        }
        R->info.Pasien->info.jumDokter = R->info.Pasien->info.jumDokter - 1;
        R->info.dokter->info.jumpasien = R->info.dokter->info.jumpasien - 1;
        R->info.Pasien = NULL;
        R->info.dokter = NULL;
        delete R;
        cout<<"Relasi berhasil dihapus (kode 1)"<<endl;
    } else if (D == NULL){
        //Menghapus semua relasi yang berhubungan dengan addressP atau P
        addressR S;
        addressR Q = first(L);
        while (Q != NULL){
            if (L.first->info.Pasien == P){ //Kalau di awal
                if (next(first(L)) == NULL){
                    first(L) = NULL;
                } else {
                    first(L) = next(first(L));
                    prev(first(L)) = NULL;
                }
                next(Q) = NULL;
                Q->info.Pasien->info.jumDokter = Q->info.Pasien->info.jumDokter - 1;
                Q->info.dokter->info.jumpasien = Q->info.dokter->info.jumpasien - 1;
                Q->info.Pasien = NULL;
                Q->info.dokter = NULL;
                delete Q;
                Q = first(L);
            } else if (Q->info.Pasien == P){ //Kalau di tengah dan di akhir
                if (next(Q) == NULL){
                    next(S) = NULL;
                    prev(Q) = NULL;
                    Q->info.Pasien->info.jumDokter = Q->info.Pasien->info.jumDokter - 1;
                    Q->info.dokter->info.jumpasien = Q->info.dokter->info.jumpasien - 1;
                    Q->info.Pasien = NULL;
                    Q->info.dokter = NULL;
                    delete Q;
                    Q = NULL;
                } else {
                    next(S) = next(Q);
                    prev(next(S)) = S;
                    next(Q) = NULL;
                    prev(Q) = NULL;
                    Q->info.Pasien->info.jumDokter = Q->info.Pasien->info.jumDokter - 1;
                    Q->info.dokter->info.jumpasien = Q->info.dokter->info.jumpasien - 1;
                    Q->info.Pasien = NULL;
                    Q->info.dokter = NULL;
                    delete Q;
                    Q = next(S);
                }
            } else {
                S = Q;
                Q = next(Q);
            }
        }
        cout<<"Relasi berhasil dihapus (kode 2)"<<endl;
    } else if (P == NULL){
        //Menghapus semua relasi yang berhubungan dengan addressD atau D
        addressR S;
        addressR Q = first(L);
        while (Q != NULL){
            if (L.first->info.dokter == D){ //Kalau di awal
                if (next(first(L)) == NULL){
                    first(L) = NULL;
                } else {
                    first(L) = next(first(L));
                    prev(first(L)) = NULL;
                }
                next(Q) = NULL;
                next(Q) = NULL;
                prev(Q) = NULL;
                Q->info.Pasien->info.jumDokter = Q->info.Pasien->info.jumDokter - 1;
                delete Q;
                Q = first(L);
            } else if (Q->info.dokter == D){ //Kalau di tengah dan di akhir
                if (next(Q) == NULL){
                    next(S) = NULL;
                    prev(Q) = NULL;
                    Q->info.Pasien->info.jumDokter = Q->info.Pasien->info.jumDokter - 1;
                    delete Q;
                    Q = NULL;
                } else {
                    next(S) = next(Q);
                    prev(next(S)) = S;
                    next(Q) = NULL;
                    prev(Q) = NULL;
                    Q->info.Pasien->info.jumDokter = Q->info.Pasien->info.jumDokter - 1;
                    delete Q;
                    Q = next(S);
                }
            } else {
                S = Q;
                Q = next(Q);
            }
        }
        cout<<"Relasi berhasil dihapus (kode 3)"<<endl;
    }
        //Bisa dipakai untuk void deleteDokter dan deletePasien
}

void insertRelasi (listRelasi &L, addressD dokter, addressP pasien){
/*  I.S : list relasi terbentuk mungkin NULL, addressD tidak NULL, dan addressP tidak NULL
    F.S : tertambah satu elemen relasi pada list relasi */
    addressR P = new elmRelasi;
    P->info.dokter = dokter;
    P->info.Pasien = pasien;
    P->next = NULL;
    P->prev = NULL;

    //Insert Last
    if (last(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
    cout<<"Berhasil Menambahkan Relasi Pasien "<<P->info.Pasien->info.nama[0]<<" "<<P->info.Pasien->info.nama[1]<<" dengan dokter "<<P->info.dokter->info.nama[0]<<" "<<P->info.dokter->info.nama[1]<<endl;
}

addressR findrelasi (listRelasi L, addressD x){
    if (first(L) != NULL){
        addressR R = first(L);
        while ((next(R) != NULL) && (info(R).dokter != x)){
            R = next(R);
        }
        if (info(R).dokter == x){
            return R;
        }
    }
    return NULL;
}

void TampilRelasi (listRelasi L){
/*  I.S : Terdefinisi listRelasi
    F.s : menampilkan relasi antara pasien dan dokter yang bersangkutan */
    if (first(L) == NULL){
        cout<<"List Kosong (Relasi)"<<endl;
    } else {
        addressR Q = first(L);
        addressD D;
        addressP P;
        int i = 0;
        while (Q != NULL){
            D = info(Q).dokter;
            P = info(Q).Pasien;
            cout<<i+1<<". Pasien "<<info(P).nama[0]<<" "<<info(P).nama[1]<<" Terhubung dengan "<<"Nama Dokter :"<<info(D).nama[0]<<" "<<info(D).nama[1]<<endl;
            Q = next(Q);
            i++;
        }
    }
}

bool cekAda (listRelasi L, int codeID, addressP X){
/* listRelasi mungkin NULL, mengembalikan boolean jika ada relasi */
    if (first(L) != NULL){
        addressR R = first(L);
        while ((R) != NULL){
            if (codeID == R->info.dokter->info.Codeid && R->info.Pasien == X){
                return false;
            }
            R = next(R);
        }
    }
    return true;
}




void sorting(listDokter &L){
/*  I.S : Terdefinisi listDokter
    F.s : Mengurutkan dokter bedasarkan banyak pasien yang ditangani */
    addressD P, Q, maxim, sebelum_maxim, sebelum_P;

    if (next(first(L)) != NULL || first(L) != NULL){ //Kalau tidak ada list ataupun cuman 1 elemen
        P = first(L);
        while (next(P) != NULL){
            Q = next(P);
            maxim = P;
            while (Q != NULL){
                if (maxim->info.jumpasien < Q->info.jumpasien){
                    maxim = Q;
                }
                Q = next(Q);
            }
            if (next(first(L) != maxim) && P != maxim){
                sebelum_maxim = first(L);
                while (next(sebelum_maxim) != maxim){
                    sebelum_maxim = next(sebelum_maxim);
                }
            }

            if (P != first(L)){
                sebelum_P = first(L);
                while (next(sebelum_P) != P){
                    sebelum_P = next(sebelum_P);
                }
            }
            if (maxim != P){ //Artinya ada nilai yang lebih besar di bandingkan P
                if (maxim == next(P)){ // Hanya tukar tempat saja
                    if (next(maxim) == NULL){
                        next(P) = NULL;
                    } else {
                        next(P) = next(maxim);
                    }
                    next(maxim) = P;
                    if (P == first(L)){
                        first(L) = maxim;
                    } else {
                        next(sebelum_P) = maxim;
                    }

                } else {
                    if (P != first(L)){
                        next(sebelum_P) = next(P);
                    } else {
                        first(L) = next(P);
                    }
                    if (next(maxim) != NULL){
                        next(sebelum_maxim) = next(maxim);
                    } else {
                        next(sebelum_maxim) = NULL;
                    }

                    if (next(P) != first(L)){
                        next(maxim) = next(sebelum_P);
                        next(sebelum_P) = maxim;
                    } else {
                        next(maxim) = first(L);
                        first(L) = maxim;
                    }
                    next(P) = next(sebelum_maxim);
                    next(sebelum_maxim) = P;
                }
                P = maxim;
            }
            P = next(P);
        }
    }
    showD(L);
}

