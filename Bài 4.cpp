#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// cấu trúc ngày tháng năm
struct NTN{
    int ngay;
    int thang;
    int nam;
};

// chuyển string sang int
// xử lý cả số âm
int chuyendoi(string a){
    int nhan=1,bdau=0,kq=0;

    // kiểm tra dấu âm
    if (a[0]=='-') nhan=-1,bdau=1;

    // chuyển từng ký tự thành số
    for (int i=bdau;i<a.length();i++){
        kq=(a[i]-'0')+kq*10;
    }
    return kq*nhan;
}

// kiểm tra ngày tháng năm hợp lệ
// trả về true nếu không hợp lệ
bool kiemtra(int a, int b, int c){
    // kiểm tra giá trị dương
    if (a<=0||b<=0||c<=0) return true;

    // kiểm tra theo từng tháng
    switch (b) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: 
        if (a>31) return true; 
        break;

    case 4:
    case 6:
    case 9:
    case 11: 
        if (a>30) return true; 
        break;

    case 2:
        // năm nhuận
        if (c%4==0){
            if (a>29) return true;
            break;
        }
        // năm thường
        if (a>28) return true; 
        break;

    default: 
        return true; // tháng không hợp lệ
    }

    return false; // hợp lệ
}

// tính ngày tiếp theo
NTN NgayTiepTheo(NTN a){
    // tăng ngày lên 1
    a.ngay=a.ngay+1;

    // xử lý tràn ngày theo từng tháng
    switch (a.thang) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10: 
        if (a.ngay>31){
            a.ngay=1; 
            a.thang=a.thang+1;
        } 
        break;

    case 12: 
        if (a.ngay>31){
            a.ngay=1; 
            a.thang=1; 
            a.nam=a.nam+1; // sang năm mới
        } 
        break;

    case 4:
    case 6:
    case 9:
    case 11: 
        if (a.ngay>30){
            a.ngay=1; 
            a.thang=a.thang+1;
        } 
        break;

    case 2:
        // năm nhuận
        if (a.nam%4==0){
            if (a.ngay>29){
                a.ngay=1; 
                a.thang=a.thang+1;
            }
            break;
        }
        // năm thường
        if (a.ngay>28){
            a.ngay=1; 
            a.thang=a.thang+1;
        } 
        break;
    }

    return a;
}

// nhập ngày tháng năm có kiểm tra hợp lệ
void Nhap(NTN &a){
    string in1,in2,in3;
    int tem1, tem2, tem3;

    cout<<"Nhap ngay thang nam: ";
    cin>>in1>>in2>>in3;

    // chuyển sang số
    tem1=chuyendoi(in1);
    tem2=chuyendoi(in2);
    tem3=chuyendoi(in3);
    
    // lặp đến khi nhập hợp lệ
    while (kiemtra(tem1,tem2,tem3)){
        cout<<"Ngay khong hop le.\nVui long nhap lai: ";
        cin>>in1>>in2>>in3;

        tem1=chuyendoi(in1);
        tem2=chuyendoi(in2);
        tem3=chuyendoi(in3);
    }
    
    // gán vào struct
    a.ngay=tem1;
    a.thang=tem2;
    a.nam=tem3;
}

int main(){
    NTN a;

    // nhập dữ liệu
    Nhap(a);

    // tính ngày tiếp theo
    NTN acong1=NgayTiepTheo(a);

    // in kết quả
    cout<<"Ngay tiep theo la: "
        <<acong1.ngay<<'/'
        <<acong1.thang<<'/'
        <<acong1.nam;

    return 0;
}
