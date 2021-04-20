#include <iostream>
using namespace std;

class CPhanSo
{
private:
    float tu;
    float mau;

public:
    // Phương thức thiết lập
    CPhanSo();
    CPhanSo(float, float);
    CPhanSo(const CPhanSo &);
    void KhoiTao();
    void KhoiTao(float, float);
    void KhoiTao(const CPhanSo &);
    friend istream &operator>>(istream &, CPhanSo &);
    void Nhap();
    // Phương thức cung cấp thông tin
    float getTu();
    float getMau();
    friend ostream &operator<<(ostream &, CPhanSo &);
    void Xuat();
    // Phương thức cập nhập thông tin
    void setTu(float);
    void setMau(float);
    CPhanSo &operator=(const CPhanSo &);
    // Phương thức kiểm tra
    int isPhanSo();
    int BangKhong();
    int PSDuong();
    int PSAm();
    // Phương thức xử lí
    int operator==(CPhanSo);
    int operator!=(CPhanSo);
    int operator>(CPhanSo);
    int operator>=(CPhanSo);
    int operator<(CPhanSo);
    int operator<=(CPhanSo);
    CPhanSo operator+(const CPhanSo &);
    CPhanSo operator-(const CPhanSo &);
    CPhanSo operator*(const CPhanSo &);
    CPhanSo operator/(const CPhanSo &);
    CPhanSo operator+=(const CPhanSo &);
    CPhanSo operator-=(const CPhanSo &);
    CPhanSo operator*=(const CPhanSo &);
    CPhanSo operator/=(const CPhanSo &);
    ~CPhanSo();
};
// Phương thức thiết lập
CPhanSo::CPhanSo()
{
    tu = 0;
    mau = 1;
}

CPhanSo::CPhanSo(float tu, float mau)
{
    this->tu = tu;
    this->mau = mau;
}

CPhanSo::CPhanSo(const CPhanSo &a)
{
    tu = a.tu;
    mau = a.mau;
}

void CPhanSo::KhoiTao()
{
    tu = 0;
    mau = 1;
}

void CPhanSo::KhoiTao(float tu, float mau)
{
    this->tu = tu;
    this->mau = mau;
}

void CPhanSo::KhoiTao(const CPhanSo &a)
{
    tu = a.tu;
    mau = a.mau;
}

istream &operator>>(istream &is, CPhanSo &a)
{
    cout << "Nhap tu: ";
    is >> a.tu;
    cout << "Nhap mau: ";
    is >> a.mau;
    return is;
}
// Phương thức cung cấp thông tin
float CPhanSo::getTu()
{
    return tu;
}

float CPhanSo::getMau()
{
    return mau;
}

ostream &operator<<(ostream &os, CPhanSo &a)
{
    os << "Tu: " << a.tu << endl;
    os << "Mau: " << a.mau << endl;
    return os;
}

void CPhanSo::Xuat()
{
    cout << "Tu: " << tu << endl;
    cout << "Mau: " << mau << endl;
}
// Phương thức cập nhập thông tin
void CPhanSo::setTu(float tu)
{
    this->tu = tu;
}
void CPhanSo::setMau(float mau)
{
    this->mau = mau;
}
CPhanSo &CPhanSo::operator=(const CPhanSo &a)
{
    tu = a.tu;
    mau = a.mau;
    return *this;
}
// Phương thức kiểm tra
int CPhanSo::isPhanSo()
{
    return (mau != 0);
}

int CPhanSo::BangKhong()
{
    return (tu == 0 && mau != 0);
}

int CPhanSo::PSDuong()
{
    return (tu * mau > 0);
}

int CPhanSo::PSAm()
{
    return (tu * mau < 0);
}
// Phương thức xử lí
int CPhanSo::operator==(CPhanSo a)
{
    return (a.tu == tu && a.mau == mau);
}

int CPhanSo::operator!=(CPhanSo a)
{
    return (a.tu != tu || a.mau != mau);
}

int CPhanSo::operator>(CPhanSo a)
{
    float temp = tu / mau;
    float temp1 = a.tu / a.mau;
    if (temp - temp1 > 0)
        return 1;
    return 0;
}

int CPhanSo::operator>=(CPhanSo a)
{
    float temp = tu / mau;
    float temp1 = a.tu / a.mau;
    if (temp - temp1 >= 0)
        return 1;
    return 0;
}

int CPhanSo::operator<(CPhanSo a)
{
    float temp = tu / mau;
    float temp1 = a.tu / a.mau;
    if (temp - temp1 < 0)
        return 1;
    return 0;
}

int CPhanSo::operator<=(CPhanSo a)
{
    float temp = tu / mau;
    float temp1 = a.tu / a.mau;
    if (temp - temp1 <= 0)
        return 1;
    return 0;
}

CPhanSo CPhanSo::operator+(const CPhanSo &a){
    CPhanSo temp;
    temp.tu = tu*a.mau + a.tu*mau;
    temp.mau = mau*a.mau;
    return temp;
}

CPhanSo CPhanSo::operator-(const CPhanSo &a){
    CPhanSo temp;
    temp.tu = tu*a.mau - a.tu*mau;
    temp.mau = mau*a.mau;
    return temp;
}

CPhanSo CPhanSo::operator*(const CPhanSo &a){
    CPhanSo temp;
    temp.tu = tu* a.tu;
    temp.mau = mau*a.mau;
    return temp;
}

CPhanSo CPhanSo::operator/(const CPhanSo &a){
    CPhanSo temp;
    temp.tu = tu* a.mau;
    temp.mau = mau*a.tu;
    return temp;
}

CPhanSo CPhanSo::operator+=(const CPhanSo &a){
    tu = tu*a.mau + a.tu*mau;
    mau = mau*a.mau;
    return *this;
}

CPhanSo CPhanSo::operator-=(const CPhanSo &a){
    tu = tu*a.mau - a.tu*mau;
    mau = mau*a.mau;
    return *this;
}

CPhanSo CPhanSo::operator*=(const CPhanSo &a){
    tu = tu* a.tu;
    mau = mau*a.mau;
    return *this;
}

CPhanSo CPhanSo::operator/=(const CPhanSo &a){
    tu = tu* a.mau;
    mau = mau*a.tu;
    return *this;
}

CPhanSo::~CPhanSo(){
    return;
}

int main(){
    
    return 0;
}