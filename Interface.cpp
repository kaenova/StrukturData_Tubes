#include "ADT.h"

void clearscreen(){
    system("CLS");
    cout<<"Tugas Besar Data Berobat"<<endl;
    cout<<"oleh 1.Kaenova Mahendra Auditama (1301190324)"<<endl;
    cout<<"     2.M Adi Ikfini (1301194160)"<<endl;
    cout<<"     IF-43-02"<<endl;
    cout<<"======================================================="<<endl;
}

void Validnama(namaLengkap &nama){
    string awal, akhir, B;
    cout<<"Nama awal    : ";
    cin>>awal;
    cout<<"Nama akhir   : ";
    cin>>akhir;
    nama[0] = awal;
    nama[1] = akhir;
}

void inisialisasi(listDokter &D, listPasien &P, listRelasi &R){
    createListP(P);
    createListD(D);
    createListR(R);
}

void enter_to_continue(){
    cout<<endl;
    cout << "Press Enter to Continue";
    getch();
}

void Menu(listDokter &D, listPasien &P, listRelasi &R){
menu_awal:
    clearscreen();

    //var
    int pilihan;
    cout<<"MENU :"<<endl;
    cout<<"1. Tambah Dokter"<<endl;
    cout<<"2. Tambah Pasien"<<endl;
    cout<<"3. Hapus Dokter"<<endl;
    cout<<"4. Hapus Pasien"<<endl;
    cout<<"5. Tambah Relasi Pasien"<<endl;
    cout<<"6. Tampilkan Semua Pasien"<<endl;
    cout<<"7. Tampilkan Semua Dokter"<<endl;
    cout<<"8. Tampilkan Pasien yang Ditangani Dokter Tertentu"<<endl;
    cout<<"9. Tampilkan Dokter yang berelasi dengan Pasien Tertentu"<<endl;
    cout<<"10. Tampilkan Dokter Sibuk dan Tidak Sibuk"<<endl;
    cout<<endl;
    cout<<"15. EXIT"<<endl;
    cout<<endl;
    cout<<"Masukkan pilihan : ";
    cin>>pilihan;
    clearscreen();

    if (pilihan >= 1 && pilihan <=10){
        if (pilihan == 1){
            insertDokter(D);
        } else if (pilihan == 2){
            insertPasien(P, R, D);
        } else if (pilihan == 3){
            deleteDokter(D, R);
        } else if (pilihan == 4){
            deletePasien(P, R);
        } else if (pilihan == 5){
            tambahDokterPasien(R, P, D);
        } else if (pilihan == 6){
            tampilSemuaPasien(P, R);
        } else if (pilihan == 7){
            showD(D);
        } else if (pilihan == 8){
            showPD(R,D);
        } else if (pilihan == 9){
            tampilRelasiPasien(P, R);
        } else if (pilihan == 10){
            sorting(D);
        }
        enter_to_continue();
    } else if (pilihan == 15){
        goto exit;
    } else {
        cout<<endl;
        cout<<"Pilihan tidak tersedia"<<endl;
        Sleep(1000);
    }
    goto menu_awal;

exit:; //ini rada aneh labelnya
    cout<<"Terimakasih telah memakai"<<endl;

}
