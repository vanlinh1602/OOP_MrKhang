#include <iostream>
#include <math.h>
using namespace std;

class CDiem
{
private:
    float x;
    float y;

public:
    CDiem()
    {
        x = 0;
        y = 0;
    }
    CDiem(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    void KhoiTao(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    CDiem &operator=(const CDiem &a)
    {
        this->x = a.x;
        this->y = a.y;
        return *this;
    }
    float KhoangCach(CDiem a)
    {
        return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
    }
    friend istream &operator>>(istream &is, CDiem &a)
    {
        cout << "Nhap x: ";
        is >> a.x;
        cout << "Nhap y: ";
        is >> a.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, CDiem &a)
    {
        os << "( " << a.x << ", " << a.y << " )";
        return os;
    }
};

class CTamGiac
{
private:
    CDiem a;
    CDiem b;
    CDiem c;

public:
    // Phương thức khởi tạo
    CTamGiac();
    CTamGiac(CDiem, CDiem, CDiem);
    CTamGiac(CTamGiac &);
    void KhoiTao();
    void KhoiTao(CDiem, CDiem, CDiem);
    void KhoiTao(CTamGiac &);
    friend istream &operator>>(istream &, CTamGiac &);
    void nhap();
    //Phương thức cung cấp thông tin
    CDiem getA();
    CDiem getB();
    CDiem getC();
    friend ostream &operator<<(ostream &, CTamGiac &);
    void xuat();
    // Phương thức cập nhập thông tin
    CTamGiac &operator=(const CTamGiac &);
    void SetA(CDiem &);
    void SetB(CDiem &);
    void SetC(CDiem &);
    // Phương thức kiểm tra thông tin
    int isCan();
    int isDeu();
    int isVuong();
    // Phương thức xử lí
    int operator==(CTamGiac);
    int operator!=(CTamGiac);
    float ChuVi();
    float DienTich();
};
// Phương thức khởi tạo
// Thiết lập mặc định
CTamGiac::CTamGiac()
{
    a.KhoiTao(0, 0);
    b.KhoiTao(0, 1);
    c.KhoiTao(1, 0);
}
// Thiết lập khi biết đầy đủ thông tin
CTamGiac::CTamGiac(CDiem a, CDiem b, CDiem c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}
// Thiết lập sao chép
CTamGiac::CTamGiac(CTamGiac &x)
{
    a = x.a;
    b = x.b;
    c = x.c;
}
// Phương thức khởi tạo mặc định
void CTamGiac::KhoiTao()
{
    a.KhoiTao(0, 0);
    b.KhoiTao(0, 1);
    c.KhoiTao(1, 0);
}
// Phương thức khởi tạo khi biết đầy đủ thông tin
void CTamGiac::KhoiTao(CDiem a, CDiem b, CDiem c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}
// Phương thức khởi tạo sao chép
void CTamGiac::KhoiTao(CTamGiac &x)
{
    a = x.a;
    b = x.b;
    c = x.c;
}
// Toán tử nhập
istream &operator>>(istream &is, CTamGiac &x)
{
    cout << "Nhap tam giac: \n";
    cout << "Diem A: ";
    is >> x.a;
    cout << "Diem B: ";
    is >> x.b;
    cout << "Diem C: ";
    is >> x.c;
    return is;
}
// Phương thức nhập
void CTamGiac::nhap()
{
    cout << "Nhap tam giac: \n";
    cout << "Diem A: ";
    cin >> a;
    cout << "Diem B: ";
    cin >> b;
    cout << "Diem C: ";
    cin >> c;
}
// Phương thức cung cấp  thông tin
// Lấy toạ độ điểm A
CDiem CTamGiac::getA()
{
    return a;
}
// Lấy toạ độ điểm B
CDiem CTamGiac::getB()
{
    return b;
}
//Lấy toạ độ điểm C
CDiem CTamGiac::getC()
{
    return c;
}
// Toán tử xuất
ostream &operator<<(ostream &os, CTamGiac &X)
{
    os << "Tam giac co: \n";
    os << "Dinh A: " << X.a << endl;
    os << "Dinh B: " << X.b << endl;
    os << "Dinh C: " << X.c << endl;
    return os;
}
// Phương thức cập nhập thông tin
// Toán tử gán
CTamGiac &CTamGiac::operator=(const CTamGiac &X)
{
    a = X.a;
    b = X.b;
    c = X.c;
    return *this;
}
// Cập nhập điểm A
void CTamGiac::SetA(CDiem &x)
{
    this->a = x;
}
// Cập nhập điểm B
void CTamGiac::SetB(CDiem &x)
{
    this->b = x;
}
// Cập nhập diểm C
void CTamGiac::SetC(CDiem &x)
{
    this->c = x;
}
// Phương thức kiểm tra
// Kiểm tra Tam giac can
int CTamGiac::isCan()
{
    float temp, temp1, temp2;
    temp = a.KhoangCach(b);
    temp1 = a.KhoangCach(c);
    temp2 = b.KhoangCach(c);
    return (temp == temp1 || temp == temp2 || temp1 == temp2);
}
// Kiểm tra Tam giac deu
int CTamGiac::isDeu()
{
    float temp, temp1, temp2;
    temp = a.KhoangCach(b);
    temp1 = a.KhoangCach(c);
    temp2 = b.KhoangCach(c);
    return (temp == temp1 && temp == temp2);
}
// Kiểm tra tam giác vuông
int CTamGiac::isVuong()
{
    float temp, temp1, temp2;
    temp = a.KhoangCach(b);
    temp1 = a.KhoangCach(c);
    temp2 = c.KhoangCach(b);
    float s1,s2,s3;
    s1 = sqrt(temp * temp + temp1 * temp1);
    s2 = sqrt(temp1 * temp1 + temp2*temp2);
    s3 = sqrt(temp2*temp2 + temp * temp);
    if ((s1 == temp2 || s2 == temp || s3 == temp1))
        return 1;
    else
        return 0;
}
// Phương thức xử lí
// So sánh bằng
int CTamGiac::operator==(CTamGiac X)
{
    float temp = this->ChuVi();
    float temp1 = X.ChuVi();
    return (temp == temp1);
}
// So sánh khác
int CTamGiac::operator!=(CTamGiac X)
{
    float temp = this->ChuVi();
    float temp1 = X.ChuVi();
    return (temp != temp1);
}
// Tính chu vi
float CTamGiac::ChuVi()
{
    float temp, temp1, temp2;
    temp = a.KhoangCach(b);
    temp1 = a.KhoangCach(c);
    temp2 = b.KhoangCach(c);
    return (temp + temp1 + temp2);
}
// Tính diện tích
float CTamGiac::DienTich()
{
    float temp, temp1, temp2;
    temp = a.KhoangCach(b);
    temp1 = a.KhoangCach(c);
    temp2 = b.KhoangCach(c);
    float p = (temp + temp1 + temp2) / 2;
    return sqrt(p * (p - temp) * (p - temp1) * (p - temp2));
}

int main()
{
    return 0;
}