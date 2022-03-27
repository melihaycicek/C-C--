#include <iostream>

#include<cstring>
using namespace std;

class Ogrenci {
    public:
    int ogrenciNo;
    char ogrenciAd[30];
    char ogrenciSoyad[30];
    
    void deger_ata(int no, char ad[], char soyad[]){
      ogrenciNo = no;
     strcpy(ogrenciAd, ad);
     strcpy(ogrenciSoyad, soyad);
     
    }
    void goster(){
        cout<<"Ogrenci Bilgisi:" << ogrenciNo << " " << ogrenciAd<< " " << ogrenciSoyad <<endl;
        
    }
    
};
int main(){
   Ogrenci ogrenciNesnesi1;
   Ogrenci ogrenciNesnesi2;
   Ogrenci ogrenciNesnesi3;
   ogrenciNesnesi3.deger_ata(361,"Melih","Aycicek");
    ogrenciNesnesi2.deger_ata(669,"Onuralp","Asık");
   ogrenciNesnesi1.deger_ata(504,"Abdullah","Uzun");
   ogrenciNesnesi1.goster();
   ogrenciNesnesi2.goster();
   ogrenciNesnesi3.goster();
    return 0;

}