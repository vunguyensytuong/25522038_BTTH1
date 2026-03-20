#include <iostream>
#include <string>
using namespace std;

// cấu trúc lưu thông tin sinh viên
struct sinhvien{
    string hoten;
    double diemtoan;
    double diemvan;
};

// kiểm tra chuỗi tên hợp lệ
// chỉ cho phép chữ cái và khoảng trắng
// trả về true nếu sai
bool checkstring(string a){
    for (int i=0;i<a.size();i++){
        // nếu không phải chữ thường, không phải chữ hoa và không phải khoảng trắng
        if ((a[i]<'a'||a[i]>'z')&&(a[i]>'Z'||a[i]<'A')&&a[i]!=' ') return true;
    }
    return false;
}

// kiểm tra điểm hợp lệ (0 đến 10)
// trả về true nếu sai
bool kiemtradiem(double a){
    if (a>=0&&a<=10) return false;
    return true;
}

// nhập thông tin sinh viên
void Nhap(sinhvien &a){
    cout<<"Nhap ten sinh vien: ";

    // đọc cả dòng (bao gồm khoảng trắng)
    getline(cin,a.hoten);

    // kiểm tra tên hợp lệ
    while (checkstring(a.hoten)){
        cout<<"Nhap sai.\nVui long nhap lai: ";

        // bỏ ký tự xuống dòng còn sót trong buffer
        cin.ignore();

        getline(cin,a.hoten);
    }
    
    // nhập điểm toán
    cout<<"Nhap diem toan: ";
    cin>>a.diemtoan;

    // kiểm tra điểm hợp lệ
    while (kiemtradiem(a.diemtoan)){
        cout<<"Nhap sai.\nVui long nhap lai: ";
        cin>>a.diemtoan;
    }
    
    // nhập điểm văn
    cout<<"Nhap diem van: ";
    cin>>a.diemvan;

    // kiểm tra điểm hợp lệ
    while (kiemtradiem(a.diemvan)){
        cout<<"Nhap sai.\nVui long nhap lai: ";
        cin>>a.diemvan;
    }

    return;
}

// tính điểm trung bình
float diemtb(sinhvien a){
    float dtb=(a.diemtoan+a.diemvan)/2;
    return dtb;
}

int main()
{
    sinhvien a;

    // nhập dữ liệu
    Nhap(a);

    // in điểm trung bình
    cout<<"\n\nDiem trung binh cua sinh vien nay: "<<diemtb(a);

    return 0;
}
