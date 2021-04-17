#include <iostream>
#include <math.h>
using namespace std;

class CDonThuc
{
private:
    float hs;
    float mu_x;

public:
    // Phương thức khởi tạo
    CDonThuc();
    CDonThuc(float, float);
    CDonThuc(CDonThuc &);
    void KhoiTao();
    void KhoiTao(float, float);
    void KhoiTao(CDonThuc &);
    friend istream &operator>>(istream &, CDonThuc &);
    void Nhap();
    // Phương thức cung cấp thông tin
    float getHs();
    float getMu_x();
    friend ostream &operator<<(ostream &, CDonThuc &);
    void Xuat();
    // Phương thức cập nhập thông tin
    void setHs(float);
    void setMu_x(float);
    CDonThuc &operator=(CDonThuc &);
    // Phương thức kiểm tra
    int isBangKhong();
    int isKhacKhong();
    // Phương thức xử lí
    int operator==(CDonThuc &);
    int operator!=(CDonThuc &);
    CDonThuc &operator*(CDonThuc &);
    CDonThuc &operator*=(CDonThuc &);
    CDonThuc &operator/(CDonThuc &);
    CDonThuc &operator/=(CDonThuc &);
    void DaoHam();
    void NguyenHam();
    float GiaTriTaiX(float);
    ~CDonThuc();
};
// --------------------------
// Phương thức khởi tạo
// --------------------------
// Phương thức thiết lập mặc định
CDonThuc::CDonThuc()
{
    hs = 0;
    mu_x = 0;
}
// Phương thức thiết lập khi biết đầy đủ thông tin
CDonThuc::CDonThuc(float hs, float mu_x)
{
    this->hs = hs;
    this->mu_x = mu_x;
}
// Phương thức thiết lập sao chép
CDonThuc::CDonThuc(CDonThuc &a)
{
    hs = a.hs;
    mu_x = a.mu_x;
}
// Phương thức khỏi tạo mặc định
void CDonThuc::KhoiTao()
{
    hs = 0;
    mu_x = 0;
}
// Phương thức khỏi tạo khi biết đầy đủ thông tin
void CDonThuc::KhoiTao(float hs, float mu_x)
{
    this->hs = hs;
    this->mu_x = mu_x;
}
// Phương thức khỏi tạo sao chép
void CDonThuc::KhoiTao(CDonThuc &a)
{
    hs = a.hs;
    mu_x = a.mu_x;
}
// Toán tử nhập
istream &operator>>(istream &is, CDonThuc &a)
{
    cout << "Nhap he so: ";
    is >> a.hs;
    cout << "Nhap mu cua x";
    is >> a.mu_x;
    return is;
}
// Phương thức nhập
void CDonThuc::Nhap()
{
    cout << "Nhap he so: ";
    cin >> hs;
    cout << "Nhap mu cua x";
    cin >> mu_x;
}
// --------------------------
// Phương thức cung cấp thông tin
// --------------------------
// Phương thức cung cấp hệ số.
float CDonThuc::getHs()
{
    return hs;
}
// Phương thức cung cấp mũ x
float CDonThuc::getMu_x()
{
    return mu_x;
}
// Toán tử xuất
ostream &operator<<(ostream &os, CDonThuc &a)
{
    os << a.hs << "x^" << a.mu_x;
    return os;
}
// Phương thức xuất
void CDonThuc::Xuat()
{
    cout << hs << "x^" << mu_x;
}
// --------------------------
// Phương thức cập nhập thông tin
// --------------------------
// Phương thức cập nhập hệ số
void CDonThuc::setHs(float hs)
{
    this->hs = hs;
}
// Phương thức cập nhập mũ x
void CDonThuc::setMu_x(float mu_x)
{
    this->mu_x = mu_x;
}
// Toán tử =
CDonThuc &CDonThuc::operator=(CDonThuc &a)
{
    hs = a.hs;
    mu_x = a.mu_x;
    return *this;
}
// --------------------------
// Phương thức kiểm tra
// --------------------------
// Kiểm tra bằng không
int CDonThuc::isBangKhong()
{
    return (hs == 0);
}
//Kiểm tra khác không
int CDonThuc::isKhacKhong()
{
    return (hs != 0);
}
// --------------------------
// Phương thức xử lí
// --------------------------

// Phương thức so sánh bằng
int CDonThuc::operator==(CDonThuc &a)
{
    return (hs == a.hs && mu_x == a.mu_x);
}
// Phương thức so sánh khác
int CDonThuc::operator!=(CDonThuc &a)
{
    return (hs != a.hs || mu_x != a.mu_x);
}
// Nhân 2 đa thức
CDonThuc &CDonThuc::operator*(CDonThuc &a)
{
    CDonThuc temp = *this;
    return temp *= a;
}
// Chia 2 đa thức
CDonThuc &CDonThuc::operator/(CDonThuc &a)
{
    CDonThuc temp = *this;
    return *this /= a;
}
// Toán tử *=
CDonThuc &CDonThuc::operator*=(CDonThuc &a)
{
    hs *= a.hs;
    mu_x += a.mu_x;
    return *this;
}
// Toán tử /=
CDonThuc &CDonThuc::operator/=(CDonThuc &a)
{
    hs /= a.hs;
    mu_x -= a.mu_x;
    return *this;
}
// Tính đạo hàm
void CDonThuc::DaoHam()
{
    hs = hs * mu_x;
    mu_x = mu_x - 1;
}
// Tính nguyên hàm
void CDonThuc::NguyenHam()
{
    mu_x = mu_x + 1;
    hs = hs / mu_x;
}
// Tính giá trị tại x
float CDonThuc::GiaTriTaiX(float x)
{
    float temp;
    temp = pow(x, mu_x);
    temp = temp * hs;
    return temp;
}
// Phương thức phá huỷ
CDonThuc::~CDonThuc()
{
    return;
}

int main()
{
    return 0;
}