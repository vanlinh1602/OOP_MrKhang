# include<iostream>
using namespace std;

class CNgay
{
	private:
	int day;
	int month;
	int year;
	public:
	//nhom phuong thuc tao lap
	CNgay();
	CNgay(const CNgay&);
	CNgay(int, int, int);
	friend istream& operator>>(istream&, CNgay&);
	void KhoiTao();
	void KhoiTao(int, int, int);
	void KhoiTao(const CNgay&);
	void Nhap();

	//nhom phuong thuc cung cap thong tin
	friend ostream& operator<<(ostream&, CNgay&);
	void Xuat();
	int GetNgay();
	int GetThang();
	int GetNam();

	//nhom phuong thuc cap nhat thong tin

	CNgay& operator=(const CNgay&);
	void SetNgay();
	void SetThang();
	void SetNam();

	//nhom phuong thuc kiem tra
	int ktngay();
	int maxday();
	int namnhuan(int);
	int operator >(const CNgay&);
	int operator <(const CNgay&);
	int operator ==(const CNgay&);
	int operator <=(const CNgay&);
	int operator >=(const CNgay&);
	int operator !=(const CNgay&);

	//nhom phuong thuc xu ly

	CNgay CongNgay(int);
	CNgay CongThang(int);
	CNgay CongNam(int);
	CNgay TruNgay(int);
	CNgay TruThang(int);
	CNgay TruNam(int);
	CNgay NgayTiepTheo();
	CNgay NgayTruocDo();
	int KhoangCach(const CNgay&);

	~CNgay();
};

int main()
{
	CNgay a, b;
	return 0;
}

//cac phuong thuc tao lap
istream& operator >>(istream& is, CNgay& a)
{
	int i;
	do
	{
		cout << "Nhap ngay:";
		is >> a.day;
		while (a.day <= 0 || a.day > 31)
		{
			cout << "Nhap lai ngay:";
			is >> a.day;
		}
		cout << "Nhap thang:";
		is >> a.month;
		while (a.month <= 0 || a.month > 12)
		{
			cout << "Nhap lai thang:";
			is >> a.month;
		}
		cout << "Nhap nam:";
		is >> a.year;
		while (a.year < 0)
		{
			cout << "Nhap lai nam:";
			is >> a.year;
		}
		i = a.ktngay();
		if (i == 0)
		{
			cout << "Ngay nhap khong hop le, xin nhap lai" << endl;
		}
	} while (i == 0);
	return is;
}

CNgay::CNgay() {
	day = 1;
	month = 1;
	year = 0;
}

CNgay::CNgay(const CNgay& DD) {
	day = DD.day;
	month = DD.month;
	year = DD.year;
}

CNgay::CNgay(int DD, int MM, int YY) {
	day = DD;
	month = MM;
	year = YY;
}

void CNgay::KhoiTao()
{
	day = 1;
	month = 1;
	year = 0;
}
void CNgay::KhoiTao(const CNgay& DD)
{
	day = DD.day;
	month = DD.month;
	year = DD.year;
}

void CNgay::KhoiTao(int DD, int MM, int YY)
{
	day = DD;
	month = MM;
	year = YY;
}

void CNgay::Nhap()
{
	int i;
	do
	{
		cout << "Nhap ngay:";
		cin >> day;
		while (day <= 0 || day > 31)
		{
			cout << "Nhap lai ngay:";
			cin >> day;
		}
		cout << "Nhap thang:";
		cin >> month;
		while (month <= 0 || month > 12)
		{
			cout << "Nhap lai thang:";
			cin >> month;
		}
		cout << "Nhap nam:";
		cin >> year;
		while (year < 0)
		{
			cout << "Nhap lai nam:";
			cin >> year;
		}
		i = ktngay();
		if (i == 0)
		{
			cout << "Ngay nhap khong hop le, xin nhap lai" << endl;
		}
	} while (i == 0);
}

//cac phuong thuc cung cap thong tin

ostream & operator <<(ostream& os, CNgay& a)
{
	if (a.ktngay() == 0)
	{
		os << "Ngay khong hop le." << endl;
		return os;
	}
	os << a.day << '/' << a.month << '/' << a.year;
	return os;
}

int CNgay::GetNgay()
{
	return day;
}

int CNgay::GetThang()
{
	return month;
}

int CNgay::GetNam()
{
	return year;
}

void CNgay::Xuat()
{
	if (ktngay() == 0)
	{
		cout << "Thoi gian khong hop le." << endl;
		return;
	}
	cout << day << '/' << month << '/' << year << endl;
}

//cac phuong thuc cap nhat thong tin

CNgay & CNgay::operator=(const CNgay& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
	return *this;
}

void CNgay::SetNgay()
{
	int i;
	cout << "Nhap ngay moi:";
	cin >> i;
	day = i;
	do
	{
		cout << "Nhap lai ngay:";
		cin >> i;
		day = i;
	} while (this->ktngay() == 0);
}

void CNgay::SetThang()
{
	int i;
	cout << "Nhap thang moi:";
	cin >> i;
	month = i;
	do
	{
		cout << "Nhap lai thang:";
		cin >> i;
		month = i;
	} while (this->ktngay() == 0);
}

void CNgay::SetNam()
{
	int i;
	cout << "Nhap nam moi:";
	cin >> i;
	year = i;
	do
	{
		cout << "Nhap lai nam:";
		cin >> i;
		year = i;
	} while (this->ktngay() == 0);
}
//cac phuong thuc kiem tra

int CNgay::ktngay()
{
	if (day <= 0 || month <= 0 || year < 0 || day > maxday() || month > 12)
	{
		return 0;
	}
	if (day == 29 && month == 2)
	{
		if (namnhuan(year) == 1) return 1;
		else return 0;
	}
	return 1;
}

int CNgay::maxday()
{
	switch (month)
	{
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

int CNgay::namnhuan(int nam)
{
	if (nam % 100 == 0)
	{
		if (nam % 400 == 0) return 1;
		else return 0;
	}
	else
	{
		if (nam % 4 == 0) return 1;
		else return 0;
	}
}

int CNgay::operator>(const CNgay& tg)
{
	if (year < tg.year) return 0;
	else if (year == tg.year && month < tg.month) return 0;
	else if (year == tg.year && month == tg.month && day <= tg.day) return 0;
	else return 1;
}

int CNgay::operator<(const CNgay& tg)
{
	if (year > tg.year) return 0;
	else if (year == tg.year && month > tg.month) return 0;
	else if (year == tg.year && month == tg.month && day >= tg.day) return 0;
	else return 1;
}

int CNgay::operator==(const CNgay& tg)
{
	if (year == tg.year && month == tg.month && day == tg.day) return 1;
	else return 0;
}

int CNgay::operator!=(const CNgay& tg)
{
	if (year == tg.year && month == tg.month && day == tg.day) return 0;
	else return 1;
}

int CNgay::operator>=(const CNgay& tg)
{
	if (*this > tg || *this == tg) return 1;
	else return 0;
}
int CNgay::operator<=(const CNgay& tg)
{
	if (*this < tg || *this == tg) return 1;
	else return 0;
}
//cac phuong thuc xu ly
CNgay CNgay::CongNgay(int time)
{
	CNgay temp = *this;
	int preday;
	int max;
	if (time < 0)
	{
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	while (time > 0)
	{
		max = temp.maxday();
		preday = temp.day;
		temp.day = temp.day + time;
		if (temp.day > max)
		{
			time = time - (max - preday) - 1;
			temp.day = 1;
			temp.month++;
			if (temp.month > 12)
			{
				temp.month = 1;
				temp.year++;
			}
		}
		else if (temp.day <= max)
		{
			time = 0;
		}
	}
	return temp;
}

CNgay CNgay::CongThang(int time)
{
	CNgay temp = *this;
	int premonth;
	int max = 12;
	if (time < 0)
	{
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	while (time > 0)
	{
		premonth = temp.month;
		temp.month = temp.month + time;
		if (temp.month > max)
		{
			time = time - (max - premonth) - 1;
			temp.month = 1;
			temp.year++;
		}
		else if (temp.month <= max)
		{
			time = 0;
		}
	}
	return temp;
}

CNgay CNgay::TruThang(int time)
{
	CNgay temp = *this;
	int premonth;
	int max = 12;
	if (time < 0)
	{
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	while (time > 0)
	{
		premonth = temp.month;
		temp.month = temp.month - time;
		if (temp.month <= 0)
		{
			time = time - premonth - 1;
			temp.month = 12;
			temp.year--;
		}
		else if (temp.month > 0)
		{
			time = 0;
		}
	}
	if (temp.year < 0) temp.KhoiTao(0, 0, 0);
	return temp;
}

CNgay CNgay::TruNgay(int time)
{
	CNgay temp = *this;
	int preday;
	int max;
	if (time < 0)
	{
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	while (time > 0)
	{
		preday = temp.day;
		temp.day = temp.day - time;
		if (temp.day <= 0)
		{
			time = time - preday - 1;
			temp.month--;
			temp.day = temp.maxday();
			if (temp.month <= 0)
			{
				temp.month = 12;
				temp.year--;
			}
		}
		else if (temp.day > 0)
		{
			time = 0;
		}
	}
	if (temp.year < 0) temp.KhoiTao(0, 0, 0);
	return temp;
}

CNgay CNgay::CongNam(int time)
{
	CNgay temp = *this;
	if (time < 0)
	{
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	temp.year = temp.year + time;
	return temp;
}

CNgay CNgay::TruNam(int time)
{
	CNgay temp = *this;
	if (time < 0)
	{
		temp.KhoiTao(0, 0, 0);
		return temp;
	}
	temp.year = temp.year - time;
	if (temp.year < 0) temp.KhoiTao(0, 0, 0);
	return temp;
}

CNgay CNgay::NgayTiepTheo()
{
	CNgay temp = *this;
	temp.CongNgay(1);
	return temp;
}
CNgay CNgay::NgayTruocDo()
{
	CNgay temp = *this;
	temp.TruNgay(1);
	return temp;
}

int CNgay::KhoangCach(const CNgay& de)
{
	CNgay pio, cha;
	if (*this > de)
	{
		pio = *this;
		cha = de;
	}
	else if (*this < de)
	{
		pio = de;
		cha = *this;
	}
	else return 0;
	int i = 0;
	while (cha < pio)
	{
		cha = cha.CongNgay(1);
		i++;
	}
	return i;
}

CNgay::~CNgay() {
	return;
}
