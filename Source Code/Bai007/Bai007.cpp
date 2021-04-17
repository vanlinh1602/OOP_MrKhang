#include<iostream>
#include<windows.h>
using namespace std;

class ThoiGian {
private:
	int gio;
	int phut;
	int giay;
public:
	// nhom phuong thuc khoi tao

	ThoiGian();
	ThoiGian(const ThoiGian&);
	ThoiGian(int, int, int);
	void KhoiTao();
	void KhoiTao(int, int, int);
	void KhoiTao(const ThoiGian&);
	friend istream& operator>>(istream&, ThoiGian&);
	void Nhap();

	// nhom phuong thuc cung cap thong tin

	friend ostream& operator<<(ostream&, ThoiGian&);
	void xuat();
	int GetGio();
	int GetPhut();
	int GetGiay();

	// nhom phuong thuc cap nhat thong tin

	void SetGio();
	void SetPhut();
	void SetGiay();
	

	//nhom phuong thuc kiem tra

	int operator>(const ThoiGian&);
	int operator<(const ThoiGian&);
	int operator==(const ThoiGian&);
	int operator>=(const ThoiGian&);
	int operator<=(const ThoiGian&);
	int operator!=(const ThoiGian&);
	int KTHopLe();

	//nhom phuong thuc xu ly

	ThoiGian& operator=(const ThoiGian&);
	ThoiGian CongThoiGian();
	ThoiGian TruThoiGian();
	void AddTime(const ThoiGian&);
	void SubTime(const ThoiGian&);
	ThoiGian KhoangThoiGian(const ThoiGian&);
	ThoiGian GioKeTiep();
	ThoiGian PhutKeTiep();
	ThoiGian GiayKeTiep();
	~ThoiGian();
};
int main() {
	return 0;
}
//nhom phuong thuc khoi tao
istream& operator>>(istream& is, ThoiGian& tg) {
	cout << "Nhap mot thoi gian moi:" << endl;
	cout << "Nhap gio:";
	is >> tg.gio;
	while (tg.gio < 0 || tg.gio>23) {
		cout << "Nhap lai gio:";
		is >> tg.gio;
	}
	cout << "Nhap phut:";
	is >> tg.phut;
	while (tg.phut < 0 || tg.phut>59) {
		cout << "Nhap lai phut:";
		is >> tg.phut;
	}
	cout << "Nhap giay:";
	is >> tg.giay;
	while (tg.giay < 0 || tg.giay>59) {
		cout << "Nhap lai giay:";
		is >> tg.giay;
	}
	return is;
}

void ThoiGian:: Nhap() {
	cout << "Nhap mot thoi gian moi:" << endl;
	cout << "Nhap gio:";
	cin >> gio;
	while (gio < 0 || gio>23) {
		cout << "Nhap lai gio:";
		cin >> gio;
	}
	cout << "Nhap phut:";
	cin >> phut;
	while (phut < 0 || phut>59) {
		cout << "Nhap lai phut:";
		cin >> phut;
	}
	cout << "Nhap giay:";
	cin >> giay;
	while (giay < 0 || giay>59) {
		cout << "Nhap lai giay:";
		cin >> giay;
	}
}
ThoiGian::ThoiGian() {
	gio = 0;
	phut = 0;
	giay = 0;
}
ThoiGian::ThoiGian(int hr, int mn, int sc) {
	gio = hr;
	phut = mn;
	giay = sc;
}
ThoiGian::ThoiGian(const ThoiGian& tgian) {
	gio = tgian.gio;
	phut = tgian.phut;
	giay = tgian.giay;
}

void ThoiGian::KhoiTao() {
	gio = 0;
	phut = 0;
	giay = 0;
}
void ThoiGian::KhoiTao(int hr, int mn, int sc) {
	gio = hr;
	phut = mn;
	giay = sc;
}
void ThoiGian::KhoiTao(const ThoiGian& tgian) {
	gio = tgian.gio;
	phut = tgian.phut;
	giay = tgian.giay;
}
// nhom phuong thuc cung cap thong tin
ostream& operator<<(ostream& os, ThoiGian& tg) {
	os << tg.gio << ':' << tg.phut << ':' << tg.giay ;
	return os;
}

void ThoiGian::xuat() {
	cout << gio << ':' << phut<<':' << giay;
}

int ThoiGian::GetGio() {
	return gio;
}

int ThoiGian::GetPhut() {
	return phut;
}

int ThoiGian::GetGiay() {
	return giay;
}

// nhom phuong thuc cap nhat thong tin

void ThoiGian::SetGio() {
	int x;
	do {
		cout << "Nhap gio moi:";
		cin >> x;
	} while (x < 0 || x>23);
	this->gio = x;
}

void ThoiGian::SetPhut() {
	int x;
	do {
		cout << "Nhap phut moi:";
		cin >> x;
	} while (x < 0 || x>59);
	this->phut = x;
}

void ThoiGian::SetGiay() {
	int x;
	do {
		cout << "Nhap giay moi:";
		cin >> x;
	} while (x < 0 || x>59);
	this->giay = x;
}
//nhom phuong thuc kiem tra
int ThoiGian::operator>(const ThoiGian& tg) {
	if (gio < tg.gio) return 0;
	else if (gio == tg.gio && phut < tg.phut) return 0;
	else if (gio == tg.gio && phut == tg.phut && giay <= tg.giay) return 0;
	else return 1;
}

int ThoiGian::operator<(const ThoiGian& tg) {
	if (gio > tg.gio) return 0;
	else if (gio == tg.gio && phut > tg.phut) return 0;
	else if (gio == tg.gio && phut == tg.phut && giay >= tg.giay) return 0;
	else return 1;
}

int ThoiGian::operator==(const ThoiGian& tg) {
	if (tg.gio == gio && tg.phut == phut && tg.giay == giay) return 1;
	else return 0;
}

int ThoiGian::operator>=(const ThoiGian& tg) {
	if (*this > tg || *this == tg) return 1;
	else return 0;
}

int ThoiGian::operator<=(const ThoiGian& tg) {
	if (*this < tg || *this == tg) return 1;
	else return 0;
}

int ThoiGian::operator!=(const ThoiGian& tg) {
	if (tg.gio == gio && tg.phut == phut && tg.giay == giay) return 0;
	else return 1;
}

int ThoiGian:: KTHopLe() {
	if (gio < 0 || phut < 0 || giay < 0) return 0;
	if (gio > 23 || phut > 60 || giay > 60) return 0;
	return 1;
}
//nhom phuong thuc xu ly
ThoiGian::~ThoiGian() {
	return;
}

ThoiGian& ThoiGian::operator=(const ThoiGian& tg) {
	this->gio = tg.gio;
	this->phut = tg.phut;
	this->giay = tg.giay;
	return *this;
}

ThoiGian ThoiGian::CongThoiGian() {
	ThoiGian re, tg;
	cout << "Nhap khoang thoi gian muon cong vao:" << endl;
	cout << "Nhap so gio cong them:";
	cin >> tg.gio;
	while (tg.gio < 0) {
		cout << "Nhap lai so gio:";
		cin >> tg.gio;
	}
	cout << "Nhap so phut muon cong them:";
	cin >> tg.phut;
	while (tg.phut < 0 || tg.phut>59) {
		cout << "Nhap lai so phut:";
		cin >> tg.phut;
	}
	cout << "Nhap so giay muon cong them:";
	cin >> tg.giay;
	while (tg.giay < 0 || tg.giay>59) {
		cout << "Nhap lai so  giay:";
		cin >> tg.giay;
	}
	re = *this;
	re.AddTime(tg);
	return re;
}
void ThoiGian::AddTime(const ThoiGian& tg) {
	int sec = tg.giay;
	int pregiay;
	while (sec > 0) {
		pregiay = giay;
		giay = giay + sec;
		if (giay > 59) {
			sec = sec - (60 - pregiay);
			giay = 0;
			phut++;
			if (phut > 59) {
				phut = 0;
				gio++;
			}
			if (gio > 23) {
				gio = 0;
			}
		}
		else if (giay <= 59) {
			sec = 0;
		}
	}
	int min = tg.phut;
	int prephut;
	while (min > 0) {
		prephut = phut;
		phut = phut + min;
		if (phut > 59) {
			min = min - (60 - prephut);
			phut = 0;
			gio++;
			if (gio > 23) {
				gio = 0;
			}
		}
		else if (phut <= 59) {
			min = 0;
		}
	}
	int hrs = tg.gio;
	int pregio;
	while (hrs > 0) {
		pregio = gio;
		gio = gio + hrs;
		if (gio > 23) {
			hrs = hrs - (24 - pregio);
			gio = 0;
		}
		else if (gio < 23) {
			hrs = 0;
		}
	}
}

ThoiGian ThoiGian::TruThoiGian() {
	ThoiGian re, tg;
	cout << "Nhap khoang thoi gian muon tru di:" << endl;
	cout << "Nhap gio:";
	cin >> tg.gio;
	while (tg.gio < 0) {
		cout << "Nhap lai gio:";
		cin >> tg.gio;
	}
	cout << "Nhap phut:";
	cin >> tg.phut;
	while (tg.phut < 0 || tg.phut>59) {
		cout << "Nhap lai phut:";
		cin >> tg.phut;
	}
	cout << "Nhap giay:";
	cin >> tg.giay;
	while (tg.giay < 0 || tg.giay>59) {
		cout << "Nhap lai giay:";
		cin >> tg.giay;
	}
	re = *this;
	re.SubTime(tg);
	return re;
}
void ThoiGian::SubTime(const ThoiGian& tg) {
	int sec = tg.giay;
	int pregiay;
	while (sec > 0) {
		pregiay = giay;
		giay = giay - sec;
		if (giay < 0) {
			sec = sec - (pregiay + 1);
			giay = 59;
			phut--;
		}
		if (phut < 0) {
			phut = 59;
			gio--;
		}
		if (gio < 0) {
			gio = 23;
		}
		if (giay >= 0) {
			sec = 0;
		}
	}
	int min = tg.phut;
	int prephut;
	while (min > 0) {
		prephut = phut;
		phut = phut - min;
		if (phut < 0) {
			min = min - (prephut + 1);
			phut = 59;
			gio--;
		}
		if (gio < 0) {
			gio = 23;
		}
		if (phut >= 0) {
			min = 0;
		}
	}
	int hrs = tg.gio;
	int pregio;
	while (hrs > 0) {
		pregio = gio;
		gio = gio - hrs;
		if (gio < 0) {
			hrs = hrs - (pregio + 1);
			gio = 23;
		}
		if (gio >= 0) {
			hrs = 0;
		}
	}
}
ThoiGian ThoiGian::KhoangThoiGian(const ThoiGian&tg1) {
	ThoiGian re, temp, tg;
	tg = tg1;
	if (*this < tg) {
		temp = *this;
		*this = tg;
		tg = temp;
	}
	re = *this;
	re.SubTime(tg);
	return re;
}

ThoiGian ThoiGian::GioKeTiep() {
	ThoiGian tg(1, 0, 0), re;
	re = *this;
	re.AddTime(tg);
	return re;
}
ThoiGian ThoiGian::PhutKeTiep() {
	ThoiGian tg(0, 1, 0), re;
	re = *this;
	re.AddTime(tg);
	return re;
}
ThoiGian ThoiGian::GiayKeTiep() {
	ThoiGian tg(0, 0, 1), re;
	re = *this;
	re.AddTime(tg);
	return re;
}