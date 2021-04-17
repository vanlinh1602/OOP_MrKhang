#include<iostream>
using namespace std;

class date {
private:
	int day;
	int month;
	int year;
public:
	//nhom phuong thuc tao lap
	date();
	date(const date&);
	date(int, int, int);
	friend istream& operator>>(istream&, date&);
	void KhoiTao();
	void KhoiTao(int, int, int);
	void KhoiTao(const date&);
	void Nhap();
	
	//nhom phuong thuc cung cap thong tin
	friend ostream& operator<<(ostream&, date&);
	void Xuat();
	int GetNgay();
	int GetThang();
	int GetNam();

	//nhom phuong thuc cap nhat thong tin

	date& operator=(const date&);
	void SetNgay();
	void SetThang();
	void SetNam();

	//nhom phuong thuc kiem tra
	int ktngay();
	int maxday();
	int namnhuan(int);
	int operator>(const date&);
	int operator < (const date&);
	int operator==(const date&);
	int operator<=(const date&);
	int operator>=(const date&);
	int operator!=(const date&);

	//nhom phuong thuc xu ly

	date CongNgay(int);
	date CongThang(int);
	date CongNam(int);
	date TruNgay(int);
	date TruThang(int);
	date TruNam(int);
	date NgayTiepTheo();
	date NgayTruocDo();
	int KhoangCach(const date&);

	~date();
};

int main() {
	date a, b;
	return 0;
}

//cac phuong thuc tao lap
istream& operator>>(istream& is, date& a) {
	int i;
	do {
		cout << "Nhap ngay:";
		is >> a.day;
		while (a.day <= 0 || a.day > 31) {
			cout << "Nhap lai ngay:";
			is >> a.day;
		}
		cout << "Nhap thang:";
		is >> a.month;
		while (a.month <= 0 || a.month > 12) {
			cout << "Nhap lai thang:";
			is >> a.month;
		}
		cout << "Nhap nam:";
		is >> a.year;
		while (a.year < 0) {
			cout << "Nhap lai nam:";
			is >> a.year;
		}
		i = a.ktngay();
		if (i == 0) {
			cout << "Ngay nhap khong hop le, xin nhap lai" << endl;
		}
	} while (i == 0);
	return is;
}

date::date() {
	day = 1;
	month = 1;
	year = 0;
}

date::date(const date& DD) {
	day = DD.day;
	month = DD.month;
	year = DD.year;
}

date::date(int DD, int MM, int YY) {
	day = DD;
	month = MM;
	year = YY;
}

void date::KhoiTao() {
	day = 1;
	month = 1;
	year = 0;
}
void date::KhoiTao(const date& DD) {
	day = DD.day;
	month = DD.month;
	year = DD.year;
}

void date::KhoiTao(int DD, int MM, int YY) {
	day = DD;
	month = MM;
	year = YY;
}

void date::Nhap() {
	int i;
	do {
		cout << "Nhap ngay:";
		cin >> day;
		while (day <= 0 || day > 31) {
			cout << "Nhap lai ngay:";
			cin >> day;
		}
		cout << "Nhap thang:";
		cin >> month;
		while (month <= 0 || month > 12) {
			cout << "Nhap lai thang:";
			cin >> month;
		}
		cout << "Nhap nam:";
		cin >> year;
		while (year < 0) {
			cout << "Nhap lai nam:";
			cin >> year;
		}
		i = ktngay();
		if (i == 0) {
			cout << "Ngay nhap khong hop le, xin nhap lai" << endl;
		}
	} while (i == 0);
}

//cac phuong thuc cung cap thong tin

ostream& operator<<(ostream& os, date& a) {
	if (a.ktngay() == 0) {
		os << "Ngay khong hop le." << endl;
		return os;
	}
	os << a.day << '/' << a.month << '/' << a.year ;
	return os;
}

int date::GetNgay() {
	return day;
}

int date::GetThang() {
	return month;
}

int date::GetNam() {
	return year;
}

void date::Xuat() {
	if (ktngay() == 0) {
		cout << "Thoi gian khong hop le." << endl;
		return;
	}
	cout << day << '/' << month << '/' << year << endl;
}

//cac phuong thuc cap nhat thong tin

date& date::operator=(const date& d) {
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
	return *this;
}

void date::SetNgay() {
	int i;
	cout << "Nhap ngay moi:";
	cin >> i;
	day = i;
	do {
		cout << "Nhap lai ngay:";
		cin >> i;
		day = i;
	} while (this->ktngay() == 0);
}

void date::SetThang() {
	int i;
	cout << "Nhap thang moi:";
	cin >> i;
	month = i;
	do {
		cout << "Nhap lai thang:";
		cin >> i;
		month = i;
	} while (this->ktngay() == 0);
}

void date::SetNam() {
	int i;
	cout << "Nhap nam moi:";
	cin >> i;
	year = i;
	do {
		cout << "Nhap lai nam:";
		cin >> i;
		year = i;
	} while (this->ktngay() == 0);
}
//cac phuong thuc kiem tra

int date::ktngay() {
	if (day <= 0 || month <= 0 || year < 0 || day>maxday() || month > 12) {
		return 0;
	}
	if (day == 29 && month == 2) {
		if (namnhuan(year) == 1) return 1;
		else return 0;
	}
	return 1;
}

int date::maxday() {
	switch (month) {
	case 1:
		return 31;
		break;
	case 2:
		if (namnhuan(year) == 1) return 29;
		else return 28;
		break;
	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;
	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	case 12:
		return 31;
		break;
	}
}

int date::namnhuan(int nam) {
	if (nam % 100 == 0) {
		if (nam % 400 == 0) return 1;
		else return 0;
	}
	else {
		if (nam % 4 == 0) return 1;
		else return 0;
	}
}

int date::operator>(const date& tg) {
	if (year< tg.year) return 0;
	else if (year == tg.year && month < tg.month) return 0;
	else if (year == tg.year && month == tg.month && day <= tg.day) return 0;
	else return 1;
}

int date::operator<(const date& tg) {
	if (year > tg.year) return 0;
	else if (year == tg.year && month > tg.month) return 0;
	else if (year == tg.year && month == tg.month && day >= tg.day) return 0;
	else return 1;
}

int date::operator==(const date& tg) {
	if (year == tg.year && month == tg.month && day == tg.day) return 1;
	else return 0;
}

int date::operator!=(const date& tg) {
	if (year == tg.year && month == tg.month && day == tg.day) return 0;
	else return 1;
}

int date::operator>=(const date& tg) {
	if (*this > tg || *this == tg) return 1;
	else return 0;
}
int date::operator<=(const date& tg) {
	if (*this < tg || *this == tg) return 1;
	else return 0;
}
//cac phuong thuc xu ly
date date::CongNgay(int time) {
	date temp = *this;
	int preday;
	int max;
	if (time < 0) {
		 temp.KhoiTao(0,0,0);
		 return temp;
	}
	while (time > 0) {
		max = temp.maxday();
		preday = temp.day;
		temp.day = temp.day + time;
		if (temp.day > max) {
			time = time - (max - preday)-1;
			temp.day = 1;
			temp.month++;
			if (temp.month > 12) {
				temp.month = 1;
				temp.year++;
			}
		}
		else if (temp.day <= max) {
			time = 0;
		}
	}
	return temp;
}

date date::CongThang(int time) {
	date temp = *this;
	int premonth;
	int max = 12;
	if (time < 0) {
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	while (time > 0) {
		premonth = temp.month;
		temp.month= temp.month + time;
		if (temp.month > max) {
			time = time - (max - premonth) - 1;
			temp.month = 1;
			temp.year++;
		}
		else if (temp.month <= max) {
			time = 0;
		}
	}
	return temp;
}

date date::TruThang(int time) {
	date temp = *this;
	int premonth;
	int max = 12;
	if (time < 0) {
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	while (time > 0) {
		premonth = temp.month;
		temp.month = temp.month - time;
		if (temp.month <= 0) {
			time = time -  premonth - 1;
			temp.month = 12;
			temp.year--;
		}
		else if (temp.month > 0) {
			time = 0;
		}
	}
	if (temp.year < 0) temp.KhoiTao(0, 0, 0);
	return temp;
}

date date::TruNgay(int time) {
	date temp = *this;
	int preday;
	int max;
	if (time < 0) {
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	while (time > 0) {
		preday = temp.day;
		temp.day = temp.day - time;
		if (temp.day <= 0) {
			time = time -  preday - 1;
			temp.month--;
			temp.day = temp.maxday();
			if (temp.month <=0) {
				temp.month = 12;
				temp.year--;
			}
		}
		else if (temp.day >0) {
			time = 0;
		}
	}
	if (temp.year < 0) temp.KhoiTao(0, 0, 0);
	return temp;
}

date date::CongNam(int time) {
	date temp = *this;
	if (time < 0) {
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	temp.year = temp.year + time;
	return temp;
}

date date::TruNam(int time) {
	date temp = *this;
	if (time < 0) {
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	temp.year = temp.year - time;
	if (temp.year < 0) temp.KhoiTao(0, 0, 0);
	return temp;
}

date date::NgayTiepTheo() {
	date temp = *this;
	temp.CongNgay(1);
	return temp;
}
date date::NgayTruocDo() {
	date temp = *this;
	temp.TruNgay(1);
	return temp;
}

int date::KhoangCach(const date& de) {
	date pio, cha;
	if (*this > de) {
		pio = *this;
		cha = de;
	}
	else if (*this < de) {
		pio = de;
		cha = *this;
	}
	else return 0;
	int i = 0;
	while (cha < pio) {
		cha=cha.CongNgay(1);
		i++;
	}
	return i;
}

date::~date() {
	return;
}