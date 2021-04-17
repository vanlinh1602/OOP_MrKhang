#include <iostream>
using namespace std;

class CDiem
{
private:
    float x;
    float y;

public:
    void KhoiTao(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(float x)
    {
        this->x = x;
    }
    void setY(float y)
    {
        this->y = y;
    }
    float getX()
    {
        return x;
    }
    float gety()
    {
        return y;
    }
    CDiem &operator=(CDiem &a)
    {
        this->x = a.x;
        this->y = a.y;
        return *this;
    }
    float KhoangCach(CDiem a)
    {
        return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
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
    CTamGiac &operator=(CTamGiac &);
    void SetA(CDiem);
    void SetB(CDiem);
    void SetC(CDiem);
    // Phương thức kiểm tra thông tin
    int isCan();
    int isDeu();
    int isVuong();
    // Phương thức xử lí
    int operator==(CTamGiac);
    int operator!=(CTamGiac);
    int operator>(CTamGiac);
    int operator>=(CTamGiac);
    int operator<(CTamGiac);
    int operator<=(CTamGiac);
    float ChuVi();
    float DienTich();
};

CTamGiac::CTamGiac()
{
    a.KhoiTao(0, 0);
    b.KhoiTao(0, 1);
    c.KhoiTao(1, 0);
}

CTamGiac::CTamGiac(CDiem a, CDiem b, CDiem c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

CTamGiac::CTamGiac(CTamGiac &x)
{
    a = x.a;
    b = x.b;
    c = x.c;
}

void CTamGiac::KhoiTao()
{
    a.KhoiTao(0, 0);
    b.KhoiTao(0, 1);
    c.KhoiTao(1, 0);
}

void CTamGiac::KhoiTao(CDiem a, CDiem b, CDiem c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void CTamGiac::KhoiTao(CTamGiac &x)
{
    a = x.a;
    b = x.b;
    c = x.c;
}

istream &operator>>(istream &is, CTamGiac &x){
    cout << "Nhap tam giac: \n";
    cout << "Diem A: ";
}
void nhap();