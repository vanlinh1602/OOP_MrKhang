#include <iostream>
#include <cmath>
using namespace std;
//Phần khai báo
class CSoPhuc
{
private:
    float thuc;
    float ao;
public:
    // Nhóm phương thức khởi tạo
    void KhoiTao();
    void KhoiTao(const CSoPhuc&);
    void KhoiTao(float, float);
    CSoPhuc();
    CSoPhuc(float, float);
    CSoPhuc(const CSoPhuc&);
    void Nhap();
    friend istream& operator >> (istream&, CSoPhuc&);
    // Nhóm phương thức cung cấp thông tin
    void Xuat();
    friend ostream& operator << (ostream&, CSoPhuc&);
    float GetThuc();
    float GetAo();
    // Nhóm phương thức cập nhật thông tin
    CSoPhuc& operator = (const CSoPhuc&);
    void SetThuc(float);
    void SetAo(float);
    // Nhóm phương thức kiểm tra
    int isBangKhong();
    int isTrung(const CSoPhuc&);
    int isKhongTrung(const CSoPhuc&);
    int ktSoThuc();
    int ktThuanAo();
    // Nhóm phương thức xử lý
    float ModunSoPhuc();
    int operator == (CSoPhuc&);
    int operator != (CSoPhuc&);
    int operator > (CSoPhuc&);
    int operator >= (CSoPhuc&);
    int operator < (CSoPhuc&);
    int operator <= (CSoPhuc&);
    CSoPhuc operator+(CSoPhuc);
    CSoPhuc operator-(CSoPhuc);
    CSoPhuc operator*(CSoPhuc);
    CSoPhuc operator/(CSoPhuc);
    ~CSoPhuc();
};

int main()
{
    return 0;
}

//Nhóm các phương thức khởi tạo
void CSoPhuc::KhoiTao()
{
    thuc = 0;
    ao = 0;
}
void CSoPhuc::KhoiTao(float tt, float aa)
{
    thuc = tt;
    ao = aa;
}
void CSoPhuc::KhoiTao(const CSoPhuc& P)
{
    thuc = P.thuc;
    ao = P.ao;
}
CSoPhuc::CSoPhuc()
{
    thuc = 0;
    ao = 0;
}
CSoPhuc::CSoPhuc(float tt, float aa)
{
    thuc = tt;
    ao = aa;
}
CSoPhuc::CSoPhuc(const CSoPhuc& P)
{
    thuc = P.thuc;
    ao = P.ao;
}
void CSoPhuc::Nhap()
{
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
}
istream& operator >> (istream& is, CSoPhuc& P)
{
    cout << "Nhap phan thuc: ";
    is >> P.thuc;
    cout << "Nhap phan ao: ";
    is >> P.ao;
    return is;
}

//Nhóm các phương thức cung cấp thông tin
void CSoPhuc::Xuat()
{
    if (ao != 0)
    {
        if (thuc != 0)
        {
            if (ao < 0)
            {
                cout << thuc << ao << "i";
            }
            else
            {
                cout << thuc << "+" << ao << "i";
            }
        }
        else
        {
            cout << ao << "i";
        }
    }
    else
    {
        cout << thuc;
    }
}
ostream& operator << (ostream& os, CSoPhuc& P)
{
    if (P.ao != 0)
    {
        if (P.thuc != 0)
        {
            if (P.ao < 0)
            {
                os << P.thuc << P.ao << "i";
            }
            else
            {
                os << P.thuc << "+" << P.ao << "i";
            }
        }
        else
        {
            os << P.ao << "i";
        }
    }
    else
    {
        os << P.thuc;
    }
    return os;
}
float CSoPhuc::GetThuc()
{
    return thuc;
}
float CSoPhuc::GetAo()
{
    return ao;
}

//Nhóm các phương thức cập nhật thông tin
CSoPhuc& CSoPhuc::operator = (const CSoPhuc& P)
{
    thuc = P.thuc;
    ao = P.ao;
    return *this;
}
void CSoPhuc::SetThuc(float tt)
{
    thuc = tt;
}
void CSoPhuc::SetAo(float aa)
{
    ao = aa;
}

//Phương thức kiểm tra
int CSoPhuc::isBangKhong()
{
    if (thuc == 0 && ao == 0)
        return 1;
    return 0;
}
int CSoPhuc::isTrung(const CSoPhuc& P)
{
    if (thuc == P.thuc && ao == P.ao)
        return 1;
    return 0;
}
int CSoPhuc::isKhongTrung(const CSoPhuc& P)
{
    if (!(thuc == P.thuc && ao == P.ao))
        return 1;
    return 0;
}
int CSoPhuc::ktSoThuc()
{
    if (ao == 0)
        return 1;
    return 0;
}
int CSoPhuc::ktThuanAo()
{
    if (thuc == 0)
        return 1;
    return 0;
}
//Nhóm phương thức xử lý
float CSoPhuc::ModunSoPhuc()
{
    float Modulus = sqrt((thuc * thuc) + (ao * ao));
    return Modulus;
}
int CSoPhuc::operator==(CSoPhuc& P)
{
    if (ModunSoPhuc() == P.ModunSoPhuc())
        return 1;
    return 0;
}
int CSoPhuc::operator!=(CSoPhuc& P)
{
    if (ModunSoPhuc() != P.ModunSoPhuc())
        return 1;
    return 0;
}
int CSoPhuc::operator>(CSoPhuc& P)
{
    if (ModunSoPhuc() > P.ModunSoPhuc())
        return 1;
    return 0;
}
int CSoPhuc::operator>=(CSoPhuc& P)
{
    if (ModunSoPhuc() >= P.ModunSoPhuc())
        return 1;
    return 0;
}
int CSoPhuc::operator<(CSoPhuc& P)
{
    if (ModunSoPhuc() < P.ModunSoPhuc())
        return 1;
    return 0;
}
int CSoPhuc::operator<=(CSoPhuc& P)
{
    if (ModunSoPhuc() <= P.ModunSoPhuc())
        return 1;
    return 0;
}
CSoPhuc CSoPhuc::operator+(CSoPhuc P)
{
    CSoPhuc temp;
    temp.thuc = thuc + P.thuc;
    temp.ao = ao + P.ao;
    return temp;
}
CSoPhuc CSoPhuc::operator-(CSoPhuc P)
{
    CSoPhuc temp;
    temp.thuc = thuc - P.thuc;
    temp.ao = ao - P.ao;
    return temp;
}
CSoPhuc CSoPhuc::operator*(CSoPhuc P)
{
    CSoPhuc temp;
    temp.thuc = (thuc * P.thuc) - (ao * P.ao);
    temp.ao = (thuc * P.ao) + (ao * P.thuc);
    return temp;
}
CSoPhuc CSoPhuc::operator/(CSoPhuc P)
{
    CSoPhuc temp;
    temp.thuc = ((thuc * P.thuc) + (ao * P.ao)) / ((P.thuc * P.thuc) + (P.ao * P.ao));
    temp.ao = ((P.thuc * ao) - (thuc * P.ao)) / ((P.thuc * P.thuc) + (P.ao * P.ao));
    return temp;
}
CSoPhuc::~CSoPhuc()
{
    return;
}
