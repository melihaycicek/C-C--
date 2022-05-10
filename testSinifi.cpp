#include<iostream>
#include<fstream>   //dosya işleme için kitaplığı içe aktarma
#include<string>
using namespace std;
string kullaniciAdi;
int tm;

void valid(string str) //kayıtları tutmak için methot oluşturma   
{
  string yonlendirici,kullanıcı;
  ifstream file;
  yonlendirici = str+".txt";
  file.open(yonlendirici.c_str());
  if(!file.is_open() && file.fail())
  {
    //file.close();
    return;
  }
  else
  {
    tm++;
    if(tm==3)
    {
      cout<<"\nBu kullanıcı adı zaten var\nLutfen tekrar deneyin.";
      //file.close();
      return;
    }
    cout<<"\nBu kullanıcı adı zaten var!\nBir kullanıcı adı oluşturun:";
    cin>>kullaniciAdi;
    //file.close();
    valid(kullaniciAdi);
  }
}
int main()
{
  int secim,i,exit=0;
  string ans,psd,name,fname,bio,usern,pw,line,nusn;
  ofstream fileo;
  ifstream filei;
  cout<<"----------------------------------------------Giris sitemine hosgeldiniz!------------------------------------------------------\n";
  while(exit==0)
  {
    cout<<"\nBir secim yapin:\n1. Kayit olun/Giris yap(Secim icin 1 e basiniz)\n2. Kaydol/Kayit islemi(Secim icin 2 e basiniz)\n\n cikmak icin herhangi bir tusa basin ve  \n";
    cin>>secim;
    if(secim==1) 
    {
      cout<<"Kullanici adinizi giriniz:";
      cin>>kullaniciAdi;
      cout<<"\nŞifrenizi girin:";
      cin>>psd;
      fname=kullaniciAdi+".txt";
      filei.open(fname.c_str());
      if(!filei.is_open() && filei.fail())
      {
        cout<<"\nYou are not registered, please register before logging in.\n";
        filei.close();
        continue;
      }
      getline(filei,usern);
      getline(filei,line);
      getline(filei,pw);
      if(kullaniciAdi==usern && psd==pw)
      {
        cout<<"\nYou are successfully logged in:)\nYOUR PROFILE SAYS:\n";
        cout<<"User-name:"<<usern<<endl;
        cout<<"Name:"<<line<<endl;
        getline(filei,line);
        cout<<"Bio:"<<line<<endl;
        filei.close();
      }
      else{
        cout<<"\nWrong username or password!\nPlease try Again.\n";
      }
      cout<<endl;
    }
    else if(secim==2)
    {
      cout<<"\nEnter your name:";
      cin.ignore();
      getline(cin,name);
      cout<<"\nCreate a username:";
      cin>>kullaniciAdi;
      tm=0;
      valid(kullaniciAdi);
      if(tm>=3)
      {
        continue;
      }
      cout<<"\nCreate a password:";
      cin>>psd;
      fname=kullaniciAdi+".txt";
      //cout<<fname;
      fileo.open(fname.c_str());
      fileo<<kullaniciAdi<<endl<<name<<endl<<psd<<endl;
      cout<<"\nYou are successfully registered:)";
      cout<<"\nAdd to your bio and press enter when you are done:";
      cin.ignore();
      getline(cin,bio);
      fileo<<bio<<endl;
      cout<<"\nYour bio is saved as: "<<bio;
      fileo.close();
    }
    else
    {
      exit=1;
    }
  }
  cout<<"\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
} 