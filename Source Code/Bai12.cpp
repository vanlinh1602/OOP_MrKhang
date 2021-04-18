#include <iostream>
using namespace std;

class CDiem
{
private:
    float x;
    float y;
    float z;

public:
    CDiem()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    CDiem(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void KhoiTao()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    void KhoiTao(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    float getZ()
    {
        return z;
    }
    CDiem &operator=(const CDiem &a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
        return *this;
    }
    friend istream &operator>>(istream &is, CDiem &a)
    {
        cout << "Nhap X: ";
        is >> a.x;
        cout << "Nhap Y: ";
        is >> a.y;
        cout << "Nhap Z: ";
        is >> a.z;
        return is;
    }
    friend ostream &operator<<(ostream &os, CDiem &a)
    {
        os << "(" << a.x << ", " << a.y << ", " << a.z << ")";
        return os;
    }
};

class CHinhCau
{
private:
    CDiem i;
    float r;

public:
    // Phương thức khởi tạo.
    CHinhCau();
    CHinhCau(CDiem, float);
    CHinhCau(const CHinhCau &);
    void KhoiTao();
    void KhoiTao(CDiem, float);
    void KhoiTao(const CHinhCau &);
    friend istream &operator>>(istream &, CHinhCau &);
    void Nhap();
    // Phương thức cung cấp thông tin
    CDiem getI();
    float getR();
    friend ostream &operator<<(ostream &, CHinhCau &);
    void Xuat();
    // Phương thức cập nhập thông tin
    void setI(CDiem);
    void setR(float);
    CHinhCau &operator=(const CHinhCau &);
    // Phương thức kiểm tra
    int TrungGoc();
    int CatOxy();
    int CatOxz();
    int CatOyz();
    // Phương thức xử lí
    int operator==(CHinhCau);
    int operator!=(CHinhCau);
    int operator>(CHinhCau);
    int operator>=(CHinhCau);
    int operator<(CHinhCau);
    int operator<=(CHinhCau);
    float KhoangCachOxy();
    float KhoangCachOxz();
    float KhoangCachOyz();
    ~CHinhCau();
};

// Phương thức khởi tạo.
// Phương thức thiết lập mắc định
CHinhCau::CHinhCau()
{
    i.KhoiTao();
    r = 0;
}
// Phương thức thiết lập khi biết đầy đủ thông tin
CHinhCau::CHinhCau(CDiem a, float x)
{
    i = a;
    r = x;
}
// Phương thức thiết lập sao chép
CHinhCau::CHinhCau(const CHinhCau &a)
{
    i = a.i;
    r = a.r;
}
// Phương thức khởi tạo mắc định
void CHinhCau::KhoiTao()
{
    i.KhoiTao();
    r = 0;
}
// Phương thức khởi tạo khi biết đầy đủ thông tin
void CHinhCau::KhoiTao(CDiem a, float x)
{
    i = a;
    r = x;
}
// Phương thức khởi tạo sao chép
void CHinhCau::KhoiTao(const CHinhCau &a)
{
    i = a.i;
    r = a.r;
}
// Toán tử nhập
istream &operator>>(istream &is, CHinhCau &a)
{
    cout << "Nhap tam I: \n";
    is >> a.i;
    cout << "Nhap ban kinh r:";
    is >> a.r;
    return is;
}
// Phương thức nhập
void CHinhCau::Nhap()
{
    cout << "Nhap tam I: \n";
    cin >> i;
    cout << "Nhap ban kinh r:";
    cin >> r;
}
// Phương thức cung cấp thông tin
// Phương thức cung cấp tâm I
CDiem CHinhCau::getI()
{
    return i;
}
// Phương thức cung cấp bán kính
float CHinhCau::getR()
{
    return r;
}
// Toán tử xuất
ostream &operator<<(ostream &os, CHinhCau &a)
{
    os << "Tam la: " << a.i << endl;
    os << "Ban kinh: " << a.r << endl;
    return os;
}
// Phương thức xuất
void CHinhCau::Xuat()
{
    cout << "Tam la: " << i << endl;
    cout << "Ban kinh: " << r << endl;
}
// Phương thức cập nhập thông tin
// Phương thức cập nhập tâm
void CHinhCau::setI(CDiem a)
{
    i = a;
}
// Phương thức cập nhập bán kính
void CHinhCau::setR(float a)
{
    r = a;
}
// Toán tử bằng
CHinhCau &CHinhCau::operator=(const CHinhCau &a)
{
    this->i = a.i;
    this->r = a.r;
    return *this;
}
// Phương thức kiểm tra
// Kiểm tra Tâm có trùng gốc không
int CHinhCau::TrungGoc()
{
    return (i.getX() == 0 && i.getY() == 0 && i.getZ() == 0);
}
// Kiểm tra có cắt Oxy
int CHinhCau::CatOxy()
{
    float temp = abs(i.getZ());
    return (temp <= r);
}
// Kiểm tra có cắt Oxz
int CHinhCau::CatOxz()
{
    float temp = abs(i.getY());
    return (temp <= r);
}
// Kiểm tra có cắt Oyz
int CHinhCau::CatOyz()
{
    float temp = abs(i.getX());
    return (temp <= r);
}
// Phương thức xử lí
// Toán tử so sánh bằng
int CHinhCau::operator==(CHinhCau a)
{
    return (r == a.r);
}
// Toán tử so sánh khác
int CHinhCau::operator!=(CHinhCau a)
{
    return (r != a.r);
}
// Toán tử so sánh lớn hơn
int CHinhCau::operator>(CHinhCau a)
{
    return (r > a.r);
}
// Toán tử so sánh lớn hơn bằng
int CHinhCau::operator>=(CHinhCau a)
{
    return (r >= a.r);
}
// Toán tử so sánh bé hớn
int CHinhCau::operator<(CHinhCau a)
{
    return (r < a.r);
}
// Toán tử so sánh bé hớn bằng
int CHinhCau::operator<=(CHinhCau a)
{
    return (r <= a.r);
}
// Khoảng cách từ tâm tới Oxy
float CHinhCau::KhoangCachOxy()
{
    return abs(i.getZ());
}
// Khoảng cách từ tâm tới Oxz
float CHinhCau::KhoangCachOxz()
{
    return abs(i.getY());
}
// Khoảng cách từ tâm tới Oyz
float CHinhCau::KhoangCachOyz()
{
    return abs(i.getX());
}
// Phương thức phá huỷ
CHinhCau::~CHinhCau()
{
    return;
}

int main()
{
    return 0;
}