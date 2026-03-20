#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Phanso{
    int tuso;
    int mauso;
};

int ucln(int a, int b)
{
    if (b == 0) return a;
    return ucln(b, a % b);
}

int strtoint(string a){
    int nhan=1,bdau=0,kq=0;
    if (a[0]=='-') nhan=-1,bdau=1;
    for (int i=bdau;i<a.length();i++){
        kq=(a[i]-'0')+kq*10;
    }
    return kq*nhan;
}

//input: 
bool cekint(string a){
    int bdau=0;
    if (a[0]=='-'){
        if (a.length()==1) return true;
        bdau=1;
    }
    for (int i=bdau;i<a.length();i++){
        if (a[i]<'0'||a[i]>'9') return true;
    }
    return false;
}

void rutgon(Phanso a){
    int i=ucln(a.tuso,a.mauso);
    a.tuso=a.tuso/i;
    a.mauso=a.mauso/i;
    if (a.mauso<0){
        if (a.tuso>0){
            a.mauso=a.mauso*-1;
            a.tuso=a.tuso*-1;
        }
    }
    if (a.tuso==0||a.mauso==1) cout<<a.tuso<<"\n";
    else cout<<a.tuso<<'/'<<a.mauso<<"\n";
}

int bcnn(int a, int b){
    return abs(a*b)/ucln(a,b);
}

void quydongsosanh(Phanso &a1, Phanso &a2){
    int bc=bcnn(a1.mauso,a2.mauso);
    a1.tuso=a1.tuso*bc/a1.mauso;
    a2.tuso=a2.tuso*bc/a2.mauso;
    a1.mauso=bc;
    a2.mauso=bc;
    if (a1.tuso==a2.tuso) cout<<"2 phan so bang nhau.\n";
    else if (a1.tuso>a2.tuso) {cout<<"Phan so lon hon: ";rutgon(a1);}
    else {cout<<"Phan so lon hon: ";rutgon(a2);}
    return;
}

void tong(Phanso a1, Phanso a2){
    Phanso a;
    a.tuso=a1.tuso+a2.tuso;
    a.mauso=a1.mauso;
    cout<<"Tong cua 2 phan so: ";
    rutgon(a);
    return;
}

void hieu(Phanso a1, Phanso a2){
    Phanso a;
    a.tuso=a1.tuso-a2.tuso;
    a.mauso=a1.mauso;
    cout<<"Hieu cua 2 phan so: ";
    rutgon(a);
    return;
}

void tich(Phanso a1, Phanso a2){
    Phanso a;
    a.tuso=a1.tuso*a2.tuso;
    a.mauso=a1.mauso*a2.mauso;
    cout<<"Tich cua 2 phan so: ";
    rutgon(a);
    return;
}

void thuong(Phanso a1, Phanso a2){
    Phanso a;
    a.tuso=a1.tuso*a2.mauso;
    a.mauso=a1.mauso*a2.tuso;
    cout<<"Thuong cua 2 phan so: ";
    rutgon (a);
    return;
}

int main()
{
    Phanso a1,a2;
    string t1, m1,t2,m2;
    do{
    cout<<"Nhap phan so 1: ";
    cin>>t1>>m1;
    if (cekint(t1)||cekint(m1)||strtoint(m1)==0){
        cout<<"Yeu cau nhap lai"<<'\n';
        continue;
    }
    break;
    } while (true);
    a1.tuso=strtoint(t1);
    a1.mauso=strtoint(m1);
    cout<<"Phan so sau khi rut gon: ";
    rutgon(a1);
    cout<<'\n';
    
    do{
    cout<<"Nhap phan so 2: ";
    cin>>t2>>m2;
    if (cekint(t2)||cekint(m2)||strtoint(m2)==0){
        cout<<"Yeu cau nhap lai"<<'\n';
        continue;
    }
    break;
    } while (true);
    a2.tuso=strtoint(t2);
    a2.mauso=strtoint(m2);
    cout<<'\n';
    
    quydongsosanh(a1,a2);
    cout<<'\n';
    
    tong(a1,a2);
    hieu(a1,a2);
    tich(a1,a2);
    thuong(a1,a2);
    return 0;
}
