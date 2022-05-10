#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;


class kitap{
    private:
char *yazar, *kitapAdi, *yayimlayan; //ARAMA İŞLEMİNİ KOLAYLAMAK İÇİN CHAR 
float *fiyat; 
int *stok;
public:
kitap(){  //COnstructor = Yapıcı Methodum.
yazar = new char[20];
kitapAdi = new char[20];
yayimlayan = new char[20]; //Nesne oluıştururken new i kullandık..
fiyat = new float;
stok = new int;
}
void veriBesleme();
void veriDuzenle();
void veriGoster();
int ara(char[], char[]);
void kitapSatinAl();
};

void kitap::veriBesleme() { 
cin.ignore();/*Giriş arabelliğini arındırmak için kullandık.
Istenmeyen arabelleği temizlemek için */
cout<<"\n Yazar Adini Giriniz ="; cin.getline(yazar, 20); //Karekterlerimizin tamamını alabilsin diye getline kullandık.
cout<<"\n Kitap Adini Giriniz ="; cin.getline(kitapAdi, 20); 
cout<<"\n Yayimlayanin Adini Giriniz="; cin.getline(yayimlayan, 20);
cout<<"\n Fiyat Giriniz ="; cin>>*fiyat;
cout<<"\n Stok Giriniz ="; cin>>*stok;
}

void kitap::veriDuzenle() { 
cin.ignore();
cout<<"\n Yazar Adini Giriniz; "; cin.getline(yazar, 20);  /*getline() işlevi, girdi 
akışından karakterleri çıkarır ve sınırlayıcı karakterle 
karşılaşılıncaya kadar onu dize nesnesine ekler.*/
cout<<"\n Kitap Adini Giriniz; "; cin.getline(kitapAdi, 20);
cout<<"\n Yayimlayanin Adini Giriniz; "; cin.getline(yayimlayan, 20);
cout<<"\n Fiyat Giriniz; "; cin>>*fiyat;
cout<<"\n Stok Giriniz; "; cin>>*stok;
}

void kitap::veriGoster() { 
cin.ignore();
cout<<"\n Yazar Adi;"<<yazar; 
cout<<"\n Kitap Adi; "<<kitapAdi;
cout<<"\n Yayimlayanin Adi "<<yayimlayan; 
cout<<"\n Fiyat ; "<<fiyat;
cout<<"\n Stok "<<stok; 
}
int kitap::ara(char baslikAl[20], char yazarAl[20]){
if(strcmp(baslikAl, kitapAdi)==0 && strcmp(yazarAl, yazar)==0) 
/*Kitap arama işleminde Char karakter yapısı kullanıldığı için eğer girilen 
Char karekter toplamı arama kısmında aranılana eşitse return1 ile aramayı gerçekleştirecek. 
Diğer türü else bloğunda ara sınıfına tekrar dönecek.*/
return 1;
else return 0;

}
void kitap::kitapSatinAl() {
int sayisi;
cout<<"\n Satin Alinacak Kitap Sayisini Giriniz:" ;
cin>>sayisi;
if(sayisi<=*stok){//0" a eşit oluncaya kadar.. asdasd
    *stok=*stok-sayisi;//Stok sayisini güncelledik.
    cout<<"\nKitaplar basariyla satin alindi";
    cout<<"\nMiktar: TL"<<(fiyat);
    cout<<"\nMiktar: TL"<<(sayisi);
    
}
else 
cout<<"\n Kitap stokta bulunamadı !!";

}




int main() {
    kitap *K[20];
    int i=0, r, t, secim;  //t ve i koşullarda kulllanmak için kullandığımız belirteçler. t ye atamayı for döngüsünde yaotık aşağıda
    char baslikSatinAlim[20], yazarSatinAlim[20];
    while(1) {
        cout<<"\n\n\n\nMENU"
        <<"\n1. Yeni Kitap Girisi"
        <<"\n2. Kitap Satin Al"
        <<"\n3. Kitap Ara"
        <<"\n4. Kitabin Ayrintiarini Duzenle"
        <<"\n5. Cikis"
        <<"\n\nSeciminizi Giriniz = ";
        cin>>secim;

    switch(secim){

        case 1: K[i] = new kitap; //i=0 için düşünelim case uraya düşütüğünde bu kadar kitabı bellekte newleyip yer oluşturacak.
            K[i]->veriBesleme();//veriBesleme Sınıfına erişimi için kullandık. K'nın i'inci nesnesini veriBesleme sınıfından doldurma işlemi
            i++; break; //Tek tek tekrar girebilmek için

        case 2: cin.ignore();
            cout<<"\nKitap Adini Giriniz ="; cin.getline(baslikSatinAlim, 20);
            cout<<"\nYazarin Adini  Giriniz ="; cin.getline(yazarSatinAlim, 20);  //Yazar karakterini girmek için yazarSatinAlim i çalıştıracak
            for(t=0;t<i;t++) {
                if(K[t]->ara(baslikSatinAlim,yazarSatinAlim)){ 
                    K[t]->kitapSatinAl();
                    break;
                }

            }
            if(t==i)
                cout<<"\nKitap Stokta yok";
             break;

        case 3: cin.ignore();
            cout<<"\nKitap Adini girin ="; cin.getline(baslikSatinAlim, 20);
            cout<<"\nYazar Adini girin ="; cin.getline(yazarSatinAlim, 20);
               for(t=0;t<i;t++){ if(K[t]->ara(baslikSatinAlim,yazarSatinAlim)){ 
                 cout<<"\nKitap basariyla bulundu";
                    K[t]->veriGoster();
                    break;
                }

            }
                if(t==i)
                cout<<"\nKitap Stokta yok";
             break;



        case 4: cin.ignore();
            cout<<"\nKitap Adini girin ="; cin.getline(baslikSatinAlim, 20);
            cout<<"\nKitap Adini girin ="; cin.getline(yazarSatinAlim, 20);

             for(t=0;t<i;t++) {
                if(K[t]->ara(baslikSatinAlim,yazarSatinAlim)){ 
                    cout<<"\nKitap basariyla bulundu.. Duzenleyebilirsiniz...";
                    K[t]->veriDuzenle();
                    break;
                }

            }
             if(t==i){
                cout<<"\nKitap Stokta yok";
            } break;

        case 5: exit(0);
        default: cout<<"\nGecersiz Secim Girdiniz";
            
        }
    } 
return 0;

}