#include <iostream>
#include <cmath>
using namespace std;

class CDiemKhongGian
{
private:
    float x;
    float y;
    float z;

public:
    // Phương thức khởi tạo
    CDiemKhongGian();
    CDiemKhongGian(const CDiemKhongGian&);
    CDiemKhongGian(float, float, float);
    void KhoiTao();
    void KhoiTao(const CDiemKhongGian&);
    void KhoiTao(float, float, float);
    void Nhap();
    friend istream& operator>>(istream&, CDiemKhongGian&);
    // Phương thức cung cấp thông tin
    void Xuat();
    friend ostream& operator<<(ostream&, CDiemKhongGian&);
    float getX();
    float getY();
    float getZ();
    // Phương thức cập nhập thông tin
    CDiemKhongGian& operator=(const CDiemKhongGian&);
    void setX(float);
    void setY(float);
    void setZ(float);
    // Phương thức kiểm tra
    int TrungGoc();
    int TrungNhau(const CDiemKhongGian&);
    int KhongTrungNhau(const CDiemKhongGian&);
    int ThuocOxy();
    int ThuocOxz();
    int ThuocOyz();
    // Phương thức xử lý
    float KhoangCachGoc();
    float KhoangCach(const CDiemKhongGian&);
    float KhoangCachOxy();
    float KhoangCachOxz();
    float KhoangCachOyz();
    int operator==(CDiemKhongGian&);
    int operator!=(CDiemKhongGian&);
    int operator>(CDiemKhongGian&);
    int operator>=(CDiemKhongGian&);
    int operator<(CDiemKhongGian&);
    int operator<=(CDiemKhongGian&);
    CDiemKhongGian DoiXungGoc();
    CDiemKhongGian DoiXungOxy();
    CDiemKhongGian DoiXungOxz();
    CDiemKhongGian DoiXungOyz();
    ~CDiemKhongGian();
};
//-------------------------------------
//Phương thức khởi tạo
//-------------------------------------
// Phương thức thiết lập mặc định
CDiemKhongGian::CDiemKhongGian()
{
    x = 0;
    y = 0;
    z = 0;
}
// Phương thức thiết lập sao chép
CDiemKhongGian::CDiemKhongGian(const CDiemKhongGian& a)
{
    x = a.x;
    y = a.y;
    z = a.z;
}
// Phương thức thiết lập khi biết đầy đủ thông tin
CDiemKhongGian::CDiemKhongGian(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
// Phương thức khởi tạo mặc định
void CDiemKhongGian::KhoiTao()
{
    x = 0;
    y = 0;
    z = 0;
}
// Phương thức khởi tạo sao chép
void CDiemKhongGian::KhoiTao(const CDiemKhongGian& a)
{
    x = a.x;
    y = a.y;
    z = a.z;
}
// Phương thức khởi tạo khi biết đầy đủ thông tin
void CDiemKhongGian::KhoiTao(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
// Phương thức nhập
void CDiemKhongGian::Nhap()
{
    cout << "Nhap X: ";
    cin >> x;
    cout << "Nhap Y: ";
    cin >> y;
    cout << "Nhap Z: ";
    cin >> z;
}
// Toán tử vào
istream& operator>>(istream& is, CDiemKhongGian& a)
{
    cout << "Nhap X: ";
    is >> a.x;
    cout << "Nhap Y: ";
    is >> a.y;
    cout << "Nhap Z: ";
    is >> a.z;
    return is;
}
//------------------------------------
// Phương thức cung cấp thông tin
//------------------------------------
// Phương thức xuất
void CDiemKhongGian::Xuat()
{
    cout << "( " << x << " , " << y << " , " << z << " )";
}
// Toán tử ra
ostream& operator<<(ostream& os, CDiemKhongGian& a)
{
    os << "( " << a.x << " , " << a.y << " , " << a.z << " )";
    return os;
}
// Phương thức cung cấp hoành độ
float CDiemKhongGian::getX()
{
    return x;
}
// Phương thức cung cấp tung độ
float CDiemKhongGian::getY()
{
    return y;
}
// Phương thức cung cấp cao độ
float CDiemKhongGian::getZ()
{
    return z;
}
//-------------------------------------
// Phương thức cập nhập thông tin
//-------------------------------------
// Toán tử gán
CDiemKhongGian& CDiemKhongGian::operator=(const CDiemKhongGian& a)
{
    x = a.x;
    y = a.y;
    z = a.z;
    return *this;
}
// Phương thức cung cấp hoành độ
void CDiemKhongGian::setX(float x)
{
    this->x = x;
}
// Phương thức cung cấp tung độ
void CDiemKhongGian::setY(float y)
{
    this->y = y;
}
// Phương thức cung cấp cao độ
void CDiemKhongGian::setZ(float z)
{
    this->z = z;
}
//-------------------------------------
// Phương thức kiểm tra
//-------------------------------------
// Kiểm tra có trùng gốc không?
int CDiemKhongGian::TrungGoc()
{
    return (x == 0 && y == 0 && z == 0);
}
// Kiểm tra 2 điểm có trùng nhau không?
int CDiemKhongGian::TrungNhau(const CDiemKhongGian& a)
{
    return (x == a.x && y == a.y && z == a.z);
}
// Kiểm tra 2 điểm có không trùng nhau không?
int CDiemKhongGian::KhongTrungNhau(const CDiemKhongGian& a)
{
    return (x != a.x || y != a.y || z != a.z);
}
// Kiểm tra có thuộc Oxy không?
int CDiemKhongGian::ThuocOxy()
{
    return (z == 0);
}
// Kiểm tra có thuộc Oxz không?
int CDiemKhongGian::ThuocOxz()
{
    return (y == 0);
}
// Kiểm tra có thuộc Oyz không?
int CDiemKhongGian::ThuocOyz()
{
    return (x == 0);
}
//-------------------------------------
// Phương thức xứ lí
//-------------------------------------
// Khoảng cách đến gốc toạ độ
float CDiemKhongGian::KhoangCachGoc()
{
    return sqrt(x * x + y * y + z * z);
}
// KHoảng cách giữa 2 điểm
float CDiemKhongGian::KhoangCach(const CDiemKhongGian& a)
{
    return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) + (z - a.z) * (z - a.z));
}
// Khoảng cách đến mặt phẳng Oxy
float CDiemKhongGian::KhoangCachOxy()
{
    if (z < 0)
        return -z;
    else
        return z;
}
// Khoảng cách đến mặt phẳng Oxz
float CDiemKhongGian::KhoangCachOxz()
{
    if (y < 0)
        return -y;
    else
        return y;
}
// Khoảng cách đến mặt phẳng Oyz
float CDiemKhongGian::KhoangCachOyz()
{
    if (x < 0)
        return -x;
    else
        return x;
}
// Toán tử so sánh bằng
int CDiemKhongGian::operator==(CDiemKhongGian& a)
{
    return (x == a.x && y == a.y && z == a.z);
}
// Toán tử so sánh khác
int CDiemKhongGian::operator!=(CDiemKhongGian& a)
{
    return (x != a.x || y != a.y || z != a.z);
}
// Toán tử so sánh lớn hơn
int CDiemKhongGian::operator>(CDiemKhongGian& a)
{
    if (KhoangCachGoc() > a.KhoangCachGoc())
        return 1;
    else return 0;
}
// Toán tử so sánh lớn hơn bằng
int CDiemKhongGian::operator>=(CDiemKhongGian& a)
{
    if (KhoangCachGoc() >= a.KhoangCachGoc())
        return 1;
    else return 0;
}
// Toán tử so sánh nhỏ hơn
int CDiemKhongGian::operator<(CDiemKhongGian& a)
{
    if (KhoangCachGoc() < a.KhoangCachGoc())
        return 1;
    else return 0;
}
// Toán tử so sánh nhỏ hơn bằng
int CDiemKhongGian::operator<=(CDiemKhongGian& a)
{
    if (KhoangCachGoc() <= a.KhoangCachGoc())
        return 1;
    else return 0;
}
// Tìm toạ độ đối xứng qua gốc toạ độ
CDiemKhongGian CDiemKhongGian::DoiXungGoc() {
    CDiemKhongGian temp;
    temp.x = -x;
    temp.y = -y;
    temp.z = -z;
    return temp;
}
// Tìm toạ độ đối xứng qua Oxy
CDiemKhongGian CDiemKhongGian::DoiXungOxy() {
    CDiemKhongGian temp;
    temp.x = x;
    temp.y = y;
    temp.z = -z;
    return temp;
}
// Tìm toạ độ đối xứng qua Oxz
CDiemKhongGian CDiemKhongGian::DoiXungOxz() {
    CDiemKhongGian temp;
    temp.x = x;
    temp.y = -y;
    temp.z = z;
    return temp;
}
// Tìm toạ độ đối xứng qua Oyz
CDiemKhongGian CDiemKhongGian::DoiXungOyz() {
    CDiemKhongGian temp;
    temp.x = -x;
    temp.y = y;
    temp.z = z;
    return temp;
}
// Phương thức phá huỷ
CDiemKhongGian::~CDiemKhongGian() {
    return;
}

int main() {
   
}