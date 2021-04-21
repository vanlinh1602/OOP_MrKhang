#include <iostream>
#include <cmath>
using namespace std;
//Phần khai báo
class CHonSo
{
private:
    int nguyen;
    int tu;
    int mau;
public:
    // Nhóm phương thức khởi tạo
    void KhoiTao();
    void KhoiTao(const CHonSo&);
    void KhoiTao(int, int, int);
    CHonSo();
    CHonSo(const CHonSo&);
    CHonSo(int, int, int);
    void Nhap();
    friend istream& operator >> (istream&, CHonSo&);
    // Nhóm phương thức cung cấp thông tin
    void Xuat();
    friend ostream& operator << (ostream&, CHonSo&);
    int GetNguyen();
    int GetTu();
    int GetMau();
    // Nhóm phương thức cập nhật thông tin
    CHonSo& operator = (const CHonSo&);
    void SetNguyen(int);
    void SetTu(int);
    void SetMau(int);
    // Nhóm phương thức kiểm tra
    int isHonSo();
    // Nhóm phương thức xử lý
    int operator == (const CHonSo&);
    int operator != (const CHonSo&);
    int operator > (const CHonSo&);
    int operator >= (const CHonSo&);
    int operator < (const CHonSo&);
    int operator <= (const CHonSo&);
    CHonSo operator+(CHonSo);
    CHonSo operator-(CHonSo);
    CHonSo operator*(CHonSo);
    CHonSo operator/(CHonSo);
    ~CHonSo();
};

int main()
{
    return 0;
}

//Nhóm các phương thức khởi tạo
void CHonSo::KhoiTao()
{
    nguyen = 0;
    tu = 0;
    mau = 1;
}
void CHonSo::KhoiTao(int nn, int tt, int mm)
{
    nguyen = nn;
    tu = tt;
    mau = mm;
}
void CHonSo::KhoiTao(const CHonSo& P)
{
    nguyen = P.nguyen;
    tu = P.tu;
    mau = P.mau;
}
CHonSo::CHonSo()
{
    nguyen = 0;
    tu = 0;
    mau = 1;
}
CHonSo::CHonSo(int nn, int tt, int mm)
{
    nguyen = nn;
    tu = tt;
    mau = mm;
}
CHonSo::CHonSo(const CHonSo& P)
{
    nguyen = P.nguyen;
    tu = P.tu;
    mau = P.mau;
}
void CHonSo::Nhap()
{
    cout << "Nhap phan nguyen: ";
    cin >> nguyen;
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}
istream& operator >> (istream& is, CHonSo& P)
{
    cout << "Nhap phan nguyen: ";
    is >> P.nguyen;
    cout << "Nhap tu: ";
    is >> P.tu;
    cout << "Nhap mau: ";
    is >> P.mau;
    return is;
}

//Nhóm các phương thức cung cấp thông tin
void CHonSo::Xuat()
{
    cout << nguyen << "+(" << tu << "/" << mau << ")";
}
ostream& operator << (ostream& os, CHonSo& P)
{
    os << P.nguyen << "+(" << P.tu << "/" << P.mau << ")";
    return os;
}
int CHonSo::GetNguyen()
{
    return nguyen;
}
int CHonSo::GetTu()
{
    return tu;
}
int CHonSo::GetMau()
{
    return mau;
}

//Nhóm các phương thức cập nhật thông tin
CHonSo& CHonSo::operator = (const CHonSo& P)
{
    nguyen = P.nguyen;
    tu = P.tu;
    mau = P.mau;
    return *this;
}
void CHonSo::SetNguyen(int nn)
{
    nguyen = nn;
}
void CHonSo::SetTu(int tt)
{
    tu = tt;
}
void CHonSo::SetMau(int mm)
{
    mau = mm;
}

//Phương thức kiểm tra
int CHonSo::isHonSo()
{
    if (mau != 0)
        return 1;
    return 0;
}
//Nhóm phương thức xử lý
int CHonSo::operator==(const CHonSo& P)
{
    float a = (float)(((nguyen * mau) + tu) / mau);
    float b = (float)(((P.nguyen * P.mau) + P.tu) / P.mau);
    if (a == b)
        return 1;
    return 0;
}
int CHonSo::operator!=(const CHonSo& P)
{
    float a = (float)(((nguyen * mau) + tu) / mau);
    float b = (float)(((P.nguyen * P.mau) + P.tu) / P.mau);
    if (a != b)
        return 1;
    return 0;
}
int CHonSo::operator>(const CHonSo& P)
{
    float a = (float)(((nguyen * mau) + tu) / mau);
    float b = (float)(((P.nguyen * P.mau) + P.tu) / P.mau);
    if (a > b)
        return 1;
    return 0;
}
int CHonSo::operator>=(const CHonSo& P)
{
    float a = (float)(((nguyen * mau) + tu) / mau);
    float b = (float)(((P.nguyen * P.mau) + P.tu) / P.mau);
    if (a >= b)
        return 1;
    return 0;
}
int CHonSo::operator<(const CHonSo& P)
{
    float a = (float)(((nguyen * mau) + tu) / mau);
    float b = (float)(((P.nguyen * P.mau) + P.tu) / P.mau);
    if (a < b)
        return 1;
    return 0;
}
int CHonSo::operator<=(const CHonSo& P)
{
    float a = (float)(((nguyen * mau) + tu) / mau);
    float b = (float)(((P.nguyen * P.mau) + P.tu) / P.mau);
    if (a <= b)
        return 1;
    return 0;
}
CHonSo CHonSo::operator+(CHonSo P)
{
    CHonSo temp;
    temp.nguyen = nguyen + P.nguyen;
    temp.tu = tu * P.mau + mau * P.tu;
    temp.mau = mau * P.mau;
    return temp;
}
CHonSo CHonSo::operator-(CHonSo P)
{
    CHonSo temp;
    temp.nguyen = nguyen - P.nguyen;
    temp.tu = tu * P.mau - mau * P.tu;
    temp.mau = mau * P.mau;
    return temp;
}
CHonSo CHonSo::operator*(CHonSo P)
{
    CHonSo temp;
    temp.tu = ((nguyen * mau) + tu) * ((P.nguyen * P.mau) + P.tu);
    temp.mau = mau * P.mau;
    temp.nguyen = 0;
    return temp;
}
CHonSo CHonSo::operator/(CHonSo P)
{
    CHonSo temp;
    temp.tu = ((nguyen * mau) + tu) * P.mau;
    temp.mau = mau * ((P.nguyen * P.mau) + P.tu);
    temp.nguyen = 0;
    return temp;
}
CHonSo::~CHonSo()
{
    return;
}