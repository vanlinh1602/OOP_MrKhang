
#include<iostream>
#include<math.h>
using namespace std;

class CDuongThang {
private:
	float a;
	float b;
	float c;
public:
	//nhom phuong thuc tao lap

	CDuongThang();
	CDuongThang(const CDuongThang&);
	CDuongThang(float, float, float);
	void KhoiTao();
	void KhoiTao(float, float, float);
	void KhoiTao(const CDuongThang&);
	friend istream& operator>>(istream&, CDuongThang&);
	void Nhap();

	//nhom phuong thuc cung cap thong tin
	friend ostream& operator<<(ostream&, CDuongThang&);
	void Xuat();
	float GetHeSoa();
	float GetHeSob();
	float GetHeSoc();

	//nhom cac phuong thuc cap nhat thong tin
	void Seta();
	void Setb();
	void Setc();
	CDuongThang& operator=(const CDuongThang&);

	//nhom phuong thuc kiem tra
	int KTHopLe();
	int KTCatNhau(const CDuongThang&);
	int KTSongSong(const CDuongThang&);
	int KTVuongGoc(const CDuongThang&);
	int KTTrungNhau(const CDuongThang&);
	int operator>(const CDuongThang&);
	int operator<(const CDuongThang&);
	int operator==(const CDuongThang&);
	int operator>=(const CDuongThang&);
	int operator<=(const CDuongThang&);
	int operator!=(const CDuongThang&);

	//nhom cac phuong thuc xu ly

	CDuongThang DiChuyenTrenOx(float x);
	CDuongThang DiChuyenTrenOy(float y);
	float KhoangCachToiGoc();
	~CDuongThang();

};
int main() {
	CDuongThang dt1, dt2;
	return 0;
}

// nhom cac phuong thuc tao lap

istream& operator>>(istream& is, CDuongThang& dt) {
	cout << "Nhap duong thang:\n";
	cout << "He so a:";
	is >> dt.a;
	cout << "He so b:";
	is >> dt.b;
	cout << "He so c:";
	is >> dt.c;
	return is;
}

CDuongThang::CDuongThang() {
	a = 1;
	b = 1;
	c = 0;
}

void CDuongThang:: KhoiTao() {
	a = 1;
	b = 1;
	c = 0;
}

CDuongThang::CDuongThang(float a1, float b1, float c1) {
	a = a1;
	b = b1;
	c = c1;
}

void CDuongThang::KhoiTao(float a1, float b1, float c1) {
	a = a1;
	b = b1;
	c = c1;
}

CDuongThang::CDuongThang(const CDuongThang& dt) {
	a = dt.a;
	b = dt.b;
	c = dt.c;
}

void CDuongThang:: KhoiTao(const CDuongThang& dt) {
	a = dt.a;
	b = dt.b;
	c = dt.c;
}

void CDuongThang::Nhap() {
	cout << "Nhap duong thang:\n";
	cout << "He so a:";
	cin >> a;
	cout << "He so b:";
	cin >> b;
	cout << "He so c:";
	cin >> c;
}

//nhom cac phuong thuc cung cap thong tin

ostream& operator<<(ostream& os, CDuongThang& dt) {
	if (dt.a != 0) os << dt.a << "x";
	if (dt.b != 0) {
		if (dt.b < 0 || dt.a == 0) os << dt.b << 'y';
		else os << '+' << dt.b << 'y';
	}
	if (dt.c != 0) {
		if (dt.c < 0 || dt.a == 0 && dt.b == 0) os << dt.c;
		else os << '+' << dt.c;
	}
	if (dt.c == 0 && dt.a == 0 && dt.b == 0) os << "0" << endl;
	os << "=0";
	return os;
}

void CDuongThang::Xuat() {
	if (a != 0) cout << a << "x";
	if (b != 0) {
		if (b < 0 || a == 0) cout << b << 'y';
		else cout << '+' << b << 'y';
	}
	if (c != 0) {
		if (c < 0 || a == 0 && b == 0) cout << c;
		else cout << '+' << c;
	}
	if (c == 0 && a == 0 && b == 0) cout << "0" << endl;
	cout << "=0";
}

float CDuongThang:: GetHeSoa() {
	return a;
}

float CDuongThang::GetHeSob() {
	return b;
}
float CDuongThang::GetHeSoc() {
	return c;
}
//nhom cac phuong thuc cap nhat thong tin
void CDuongThang::Seta() {
	float x;
	cout << "Nhap he so a moi:";
	cin >> x;
	this->a = x;
	while (this->KTHopLe() == 0) {
		cout << "Cap nhat khong hop le, nhap lai he so:";
		cin >> x;
		this->a = x;
	}
}

void CDuongThang::Setb() {
	float x;
	cout << "Nhap he so b moi:";
	cin >> x;
	this->b = x;
	while (this->KTHopLe() == 0) {
		cout << "Cap nhat khong hop le, nhap lai he so:";
		cin >> x;
		this->b = x;
	}
}

void CDuongThang::Setc() {
	float x;
	cout << "Nhap he so c moi:";
	cin >> x;
	this->c = x;
}

CDuongThang& CDuongThang::operator=(const CDuongThang& dt) {
	this->a = dt.a;
	this->b = dt.b;
	this->c = dt.c;
	return *this;
}
//nhom cac phuong thuc kiem tra

int CDuongThang:: KTSongSong(const CDuongThang& dt) {
	if (a * dt.b == dt.a * b && c * dt.b != b * dt.c && a * dt.c != c * dt.a) return 1;
	else return 0;
}

int CDuongThang::KTTrungNhau(const CDuongThang& dt) {
	if (a * dt.b == b * dt.a && b * dt.c == c * dt.b) return 1;
	else return 0;
}

int CDuongThang::KTVuongGoc(const CDuongThang& dt) {
	if (a * dt.a + b * dt.b == 0) return 1;
	else return 0;
}

int CDuongThang:: KTCatNhau(const CDuongThang& dt) {
	if (this->KTSongSong(dt) == 0 && this->KTTrungNhau(dt) == 0) return 1;
	else return 0;

}

int CDuongThang::KTHopLe() {
	if (a * a + b * b == 0) return 0;
	else return 1;
}

int CDuongThang::operator<(const CDuongThang& dt) {
	float kc1 = this->KhoangCachToiGoc();
	CDuongThang temp;
	temp = dt;
	float kc2 = temp.KhoangCachToiGoc();
	if (kc1 < kc2) return 1;
	else return 0;
}

int CDuongThang::operator>(const CDuongThang& dt) {
	float kc1 = this->KhoangCachToiGoc();
	CDuongThang temp;
	temp = dt;
	float kc2 = temp.KhoangCachToiGoc();
	if (kc1 > kc2) return 1;
	else return 0;
}

int CDuongThang::operator==(const CDuongThang& dt) {
	float kc1 = this->KhoangCachToiGoc();
	CDuongThang temp;
	temp = dt;
	float kc2 = temp.KhoangCachToiGoc();
	if (kc1 == kc2) return 1;
	else return 0;
}

int CDuongThang::operator>=(const CDuongThang& dt) {
	if (*this > dt || *this == dt) return 1;
	else return 0;
}

int CDuongThang::operator<=(const CDuongThang& dt) {
	if (*this < dt || *this == dt) return 1;
	else return 0;
}

int CDuongThang::operator!=(const CDuongThang& dt) {
	return(!(*this == dt));
}

//nhom cac phuong thuc xu ly

float CDuongThang::KhoangCachToiGoc() {
	return abs(c) / (sqrt(a * a + b * b));
}

CDuongThang CDuongThang::DiChuyenTrenOx(float x) {
	CDuongThang temp = *this;
	temp.c = temp.c - temp.a * x;
	return temp;
}

CDuongThang CDuongThang::DiChuyenTrenOy(float x) {
	CDuongThang temp = *this;
	temp.c = temp.c - temp.b * x;
	return temp;
}

CDuongThang::~CDuongThang() {
	return;
}
