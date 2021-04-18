#include <iostream>
using namespace std;

class CDiem{
private:
    float x;
    float y;
    float z;
public:

};

class CHinhCau{
private:
    CDiem i;
    float r;
public:
    // Phương thức khởi tạo.
    CHinhCau();
    CHinhCau(CDiem, float);
    CHinhCau(const CHinhCau&);
    void KhoiTao();
    void KhoiTao(CDiem, float);
    void KhoiTao(const CHinhCau&);
    friend istream& operator >> (istream&, CHinhCau&);
    void Nhap();
    // Phương thức cung cấp thông tin
    




};