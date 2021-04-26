#include<iostream>
#include<math.h>
#define pi 3.14;
using namespace std;

class CDiem {
private:
	float x;
	float y;
public:
	//nhom phuong thuc tao lap
	CDiem();
	CDiem(float, float);
	CDiem(const CDiem&);
	friend istream& operator>>(istream&, CDiem&);

	//nhom phuong thuc cung cap thong tin
	friend ostream& operator<<(ostream&, CDiem&);

	//nhom phuong thuc kiem tra
	int operator==(const CDiem&);

	//nhom phuong thuc xu ly
	~CDiem();
	float KCToiOx();
	float KCToiOy();
};
class CDuongTron {
private:
	CDiem tam;
	float bankinh;
public:
	//Nhom phuong thuc tao lap
	CDuongTron();
	CDuongTron(float,const CDiem&);
	CDuongTron(const CDuongTron&);
	void KhoiTao();
	void KhoiTao(float,const CDiem&);
	void KhoiTao(const CDuongTron&);
	friend istream& operator>>(istream&, CDuongTron&);
	void Nhap();

	//nhom phuong thuc cung cap thong tin
	friend ostream& operator<<(ostream&, CDuongTron&);
	void Xuat();
	void GetTam();
	void GetBanKinh();

	//nhom phuong thuc cap nhat thong tin
	void SetTam();
	void SetBanKinh();
	CDuongTron& operator=(const CDuongTron&);

	//nhom phuong thuc kiem tra
	int KTHopLe();
	int KTTrung(const CDuongTron&);
	int TiepXucOx();
	int TiepXucOy();
	int operator<(const CDuongTron&);
	int operator>(const CDuongTron&);
	int operator==(const CDuongTron&);
	int operator>=(const CDuongTron&);
	int operator<=(const CDuongTron&);
	int operator!=(const CDuongTron&);

	//nhom phuong thuc xu ly
	float ChuVi();
	float DienTich();
	~CDuongTron();
};
int main() {
	CDuongTron a, b;
	return 0;
}

//lop CDiem
//nhom phuong thuc tao lap
istream& operator>>(istream& is, CDiem& diem) {
	cout << "Nhap x:";
	is >> diem.x;
	cout << "Nhap y:";
	is >> diem.y;
	return is;
}
CDiem::CDiem() {
	x = 0;
	y = 0;
}
CDiem::CDiem(float x, float y) {
	this->x = x;
	this->y = y;
}
CDiem::CDiem(const CDiem& dd) {
	this->x = dd.x;
	this->y = dd.y;
}

//nhom phuong thuc cung cap thong tin
ostream& operator<<(ostream& os, CDiem& diem) {
	os << '(' << diem.x << ',' << diem.y << ')';
	return os;
}

//nhom phuong thuc kiem tra
int CDiem::operator==(const CDiem& d) {
	if (x == d.x && y == d.y) return 1;
	else return 0;
}

//nhom phuong thuc xu ly
CDiem::~CDiem() {
	return;
}

float CDiem::KCToiOx() {
	return abs(y);
}

float CDiem::KCToiOy() {
	return abs(x);
}

//lop duong CDuongTron

//nhom phuong thuc tao lap
istream& operator>>(istream& is, CDuongTron& tron) {
	cout << "Nhap mot duong tron moi:\n";
	cout << "Nhap tam duong tron:\n";
	is >> tron.tam;
	cout << "Ban kinh:";
	is >> tron.bankinh;
	while (tron.bankinh <= 0) {
		cout << "Ban kinh khong hop le, xin nhap lai ban kinh:";
		cin >> tron.bankinh;
	}
	return is;
}

CDuongTron::CDuongTron() {
	bankinh = 1;
}

void CDuongTron::KhoiTao() {
	bankinh = 1;
}

CDuongTron::CDuongTron(float bk,const CDiem& dd) {
	this->bankinh = bk;
	this->tam = dd;
}


void CDuongTron::KhoiTao(float bk, const CDiem& dd) {
	this->bankinh = bk;
	this->tam = dd;
}

CDuongTron::CDuongTron(const CDuongTron& tron) {
	this->bankinh = tron.bankinh;
	this->tam = tron.tam;
}

void CDuongTron:: KhoiTao(const CDuongTron& tron) {
	this->bankinh = tron.bankinh;
	this->tam = tron.tam;
}


void CDuongTron::Nhap() {
	cout << "Nhap mot duong tron moi:\n";
	cout << "Nhap tam duong tron:\n";
	cin >> tam;
	cout << "Ban kinh:";
	cin >> bankinh;
	while (bankinh <= 0) {
		cout << "Ban kinh khong hop le, xin nhap lai:";
		cin >> bankinh;
	}
}
//nhom phuong thuc cung cap thong tin


ostream& operator<<(ostream& os, CDuongTron& tron) {
	os << '(';
	os << "Ban kinh:" << tron.bankinh << ';';
	os << "Tam:" << tron.tam << ')';
	return os;
}

void CDuongTron::GetTam() {
	cout << "Tam duong tron:";
	cout << tam;
}

void CDuongTron::GetBanKinh() {
	cout << "Ban kinh duong tron:";
	cout << bankinh;
}

void CDuongTron:: Xuat() {
	cout << '(';
	cout << "Ban kinh:" <<bankinh << ';';
	cout << "Tam:" << tam << ')';
}

//nhom phuong thuc cap nhat thong tin
void CDuongTron:: SetTam() {
	cout << "Nhap tam moi:\n";
	cin >> tam;
}

void CDuongTron::SetBanKinh() {
	float r;
	cout << "Nhap ban kinh moi:";
	cin >> r;
	while (r <= 0) {
		cout << "Ban Kinh khong hop le, xin nhap lai:";
		cin >> r;
	}
	bankinh = r;
}

CDuongTron& CDuongTron:: operator=(const CDuongTron& tr) {
	this->bankinh = tr.bankinh;
	this->tam = tr.tam;
	return *this;
}

//nhom phuong thuc kiem tra
int CDuongTron::KTHopLe() {
	if (bankinh > 0) return 1;
	else return 0;
}

int CDuongTron::KTTrung(const CDuongTron& tr) {
	if (tam == tr.tam && bankinh == tr.bankinh) return 1;
	else return 0;
}

int CDuongTron::operator>(const CDuongTron& tr) {
	if (bankinh > tr.bankinh) return 1;
	else return 0;
}

int CDuongTron::operator<(const CDuongTron& tr) {
	if (bankinh < tr.bankinh) return 1;
	else return 0;
}

int CDuongTron::operator==(const CDuongTron& tr) {
	if (bankinh == tr.bankinh) return 1;
	else return 0;
}

int CDuongTron::operator!=(const CDuongTron& tr) {
	return(!(bankinh == tr.bankinh));
}

int CDuongTron::operator<=(const CDuongTron& tr) {
	if (*this == tr || *this < tr) return 1;
	else return 0;
}

int CDuongTron::operator>=(const CDuongTron& tr) {
	if (*this == tr || *this > tr) return 1;
	else return 0;
}

int CDuongTron::TiepXucOx() {
	if (bankinh == tam.KCToiOx()) return 1;
	else return 0;
}

int CDuongTron::TiepXucOy() {
	if (bankinh == tam.KCToiOy()) return 1;
	else return 0;
}
//nhom phuong thuc xu ly

float CDuongTron::ChuVi() {
	float re;
	re = (float)2 * pi;
	re = (float)re * bankinh;
	return re;
}

float CDuongTron::DienTich() {
	float re;
	re = (float) pi;
	re = (float)re * bankinh*bankinh;
	return re;
}

CDuongTron::~CDuongTron() {
	return;
}
