#include "Account.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <math.h>
#include <sstream>
using namespace std;

void Account::setSecondname(string value)
{
	secondname = value;
}

bool Account::setNo(int value)
{
	if (value > 0)
	{
		no = value;
		return true;
	}
	else
	{
		no = 0;
		return false;
	}
}

bool Account::setPercent(double value)
{
	if (value > 0)
	{
		percent = value;
		return true;
	}
	else
	{
		percent = -value;
		return false;
	}
}

void Account::setSumma()
{
	cin >> summa;
}

Account::Account()
{
	setNo(0);
	setPercent(0);
}
Account::Account(int no, double percent)
{
	setNo(no);
	setPercent(percent);
}
Account::Account(const Account& a)
{
	setNo(a.getNo());
	setPercent(a.getPercent());
}

ostream& operator <<(ostream& out, const Account& x)
{
	out << string(x);
	return out;
}
istream& operator >>(istream& in, Account& x)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "¬вед≥ть номер банк≥вського рахунку: "; in >> x.no;
	cout << "¬вед≥ть пр≥звище власника: "; in >> x.secondname;

	return in;
}
Account& Account::operator =(const Account& r)
{
	secondname = r.secondname;
	percent = r.percent;
	no = r.no;
	summa = r.summa;
	return *this;
}
Account::operator string() const
{
	stringstream ss;
	ss << "----------------------------------------------------------------------------\n";
	ss << "|500h|200h|100h| 50h| 20h| 10h|  5h|  2h|  1h| 50c| 25c| 10c|  5c|  2c|  1c|\n";
	ss << "----------------------------------------------------------------------------\n";
	ss << "|" << setw(4) << summa.getH500() << "|" << setw(4) << summa.getH200() << "|" << setw(4) << summa.getH100() << "|" <<
		setw(4) << summa.getH50() << "|" << setw(4) << summa.getH20() << "|" << setw(4) << summa.getH10() << "|" << setw(4) <<
		summa.getH5() << "|" << setw(4) << summa.getH2() << "|" << setw(4) << summa.getH1() << "|" << setw(4) << summa.getC50() <<
		"|" << setw(4) << summa.getC25() << "|" << setw(4) << summa.getC10() << "|" << setw(4) << summa.getC5() << "|" <<
		setw(4) << summa.getC2() << "|" << setw(4) << summa.getC1() << "|\n" <<
		"----------------------------------------------------------------------------\n";

	int a = summa.getH500() * 500 + summa.getH200() * 200 + summa.getH100() * 100 +
		summa.getH50() * 50 + summa.getH20() * 20 + summa.getH10() * 10 + summa.getH5() * 5 + summa.getH2() * 2 + summa.getH1();
	int b = summa.getC50() * 50 + summa.getC25() * 25 + summa.getC10() * 10 + summa.getC5() * 5 + summa.getC2() * 2 + summa.getC1();
	while (b >= 100)
	{
		b -= 100;
		a += 1;
	}
	if (b < 10)
		ss << "Sum = " << a << ",0" << b << endl;
	else
		ss << "Sum = " << a << "," << b << endl;

	return ss.str();
}

void Account::ChangeOwner()
{
	cin >> summa;
	setPercent(5);
}

void Account::GetMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "—к≥льки грошей ви бажаЇте зн€ти?" << endl;
		cout << "[1] - 500 грн." << endl;
		cout << "[2] - 200 грн" << endl;
		cout << "[3] - 100 грн" << endl;
		cout << "[4] - 50 грн" << endl;
		cout << "[5] - 20 грн" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa.setH500(summa.getH500() - 1);
			cout << "¬и усп≥шно зн€ли 500 гривень" << endl;
			break;
		case 2:
			summa.setH200(summa.getH200() - 1);
			cout << "¬и усп≥шно зн€ли 200 гривень" << endl;
			break;
		case 3:
			summa.setH100(summa.getH100() - 1);
			cout << "¬и усп≥шно зн€ли 100 гривень" << endl;
			break;
		case 4:
			summa.setH50(summa.getH50() - 1);
			cout << "¬и усп≥шно зн€ли 50 гривень" << endl;
			break;
		case 5:
			summa.setH20(summa.getH20() - 1);
			cout << "¬и усп≥шно зн€ли 20 гривень" << endl;
		}
		break;
		cout << endl;
	} while (no != 6);
}

void Account::AddMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "—к≥льки грошей ви бажаЇте покласти на рахунок?" << endl;
		cout << "[1] - 500 грн." << endl;
		cout << "[2] - 200 грн" << endl;
		cout << "[3] - 100 грн" << endl;
		cout << "[4] - 50 грн" << endl;
		cout << "[5] - 20 грн" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa.setH500(summa.getH500() + 1);
			cout << "¬и усп≥шно поклали 500 гривень" << endl;
			break;
		case 2:
			summa.setH200(summa.getH200() + 1);
			cout << "¬и усп≥шно поклали 200 гривень" << endl;
			break;
		case 3:
			summa.setH100(summa.getH100() + 1);
			cout << "¬и усп≥шно поклали 100 гривень" << endl;
			break;
		case 4:
			summa.setH50(summa.getH50() + 1);
			cout << "¬и усп≥шно поклали 50 гривень" << endl;
			break;
		case 5:
			summa.setH20(summa.getH20() + 1);
			cout << "¬и усп≥шно поклали 20 гривень" << endl;
		}
		break;
		cout << endl;
	} while (no != 6);
}

Account Account::MakePercent(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	sum = summa.Total();
	int no;
	do {
		cout << "¬и справд≥ бажаЇте нарахувати " << percent << "% на ваш баланс?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * (percent / 100);
			cout << "¬и усп≥шно нарахували в≥дсотки!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

Account Account::ToDollar(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int no;
	do {
		cout << "¬и справд≥ бажаЇте перевести " << summa.Total() << "грн. у доллари?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * 0.033;
			cout << "¬и усп≥шно перевели грош≥ у доллари!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

Account Account::ToEuro(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int no;
	do {
		cout << "¬и справд≥ бажаЇте перевести " << summa.Total() << "грн. у Ївро?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * 0.030;
			cout << "¬и усп≥шно перевели грош≥ у Ївро!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

void Account::Propys()
{
	double x = summa.Total();
	double frac = 0;
	double integral = 0;
	frac = modf(x, &integral);
	int numb = (int)integral;

	int osn[11] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

	string basis[11][10] = {
		{"","","","","","","","","",""},
		{"","один","два","три","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","четириста","п'€тсот","ш≥стсот","с≥мсот","в≥с≥мсот","дев'€тсот"},
		{"","одна","дв≥","три","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","чотириста","п'€тсот","ш≥стсот","семсот","в≥с≥мсот","дев'€тсот"},
		{"","один","два","три","четире","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стьдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","чотириста","п'€тсот","ш≥стсот","с≥мсот","в≥с≥мсот","дев'€тсот"},
		{"","один","два","три ","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"} };


	string termination[10][10] = {
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ча","","","м≥льйон","","","м≥ль€рд"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч","","","м≥льйона","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"} };

	string dec[10] = { "дес€ть","одинадц€ть","дванадц€ть","тринадц€ть","чотирнадц€ть","п'€тнадц€ть","ш≥стнадц€ть","с≥мнадц€ть","в≥с≥мнадц€ть","дев'€тнадц€ть" };
	string result;

	if (!numb) {
		result = "нуль ";
	}
	int n1 = numb;
	int cnt = 0;

	//п≥драхунок к≥лькост≥ символ≥в в числ≥
	while (numb) {
		numb /= 10;
		cnt++;
	}
	int cile = 0;

	while (n1) {
		if (!((cnt + 1) % 3)) {
			if ((n1 / osn[cnt]) == 1) {
				n1 %= osn[cnt];
				--cnt;
				cile = n1 / osn[cnt];
				n1 %= osn[cnt];
				result += dec[cile];
				--cnt;
				if (!(cnt % 3))
					result += " " + termination[0][cnt] + " ";
			}
			if (!cnt) break;
		}
		cile = n1 / osn[cnt];
		n1 %= osn[cnt];
		result += basis[cnt][cile] + " ";
		--cnt;
		if (!(cnt % 3))
			result += termination[cile][cnt] + " ";
	}
	cout << "Ќа вашому рахунку " << result << "гривень " << fixed << setprecision(0) << frac * 100 << " коп≥йок";
	cout << endl;
}

double Account::Total(const Account& a) {
	int hrn, kop;
	double sum;
	hrn = a.summa.getH500() * 500 + a.summa.getH200() * 200 + a.summa.getH100() * 100 +
		a.summa.getH50() * 50 + a.summa.getH20() * 20 + a.summa.getH10() * 10 + a.summa.getH5() * 5 + a.summa.getH2() * 2 + a.summa.getH1();
	kop = a.summa.getC50() * 50 + a.summa.getC25() * 25 + a.summa.getC10() * 10 + a.summa.getC5() * 5 + a.summa.getC2() * 2 + a.summa.getC1();
	sum = (double)hrn + (double)kop / 100.;
	return sum;
}

Account Account::Add(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) + Total(y);
	int hrn = (int)subt;
	int coin = (floor((subt - hrn) * 100 + 0.501));

	return Change(hrn, coin, a);
}

Account Account::Subtract(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) - Total(y);
	if (subt <= 0)
	{
		cerr << "Sum on first account is lesser than that on the latter.\n";
	}
	else
	{
		int hrn = (int)subt;
		int coin = (floor((subt - hrn) * 100 + 0.501));

		return Change(hrn, coin, a);
	}
}

Account Account::Multiply(Account& x, const double y)
{
	if (y <= 0)
		Account(x);
	else
	{
		if (y != 1)
		{
			double sum = Total(x);
			sum *= y;
			int hrn = (int)sum;
			int coin = (floor((sum - hrn) * 100 + 0.501));

			return Change(hrn, coin, x);
		}
		else
			Account(x);
	}
	return x;
}

Account Account::Division(Account& x, const double y)
{
	if (y == 0)
		Account(x);
	else
	{
		if (y != 1)
		{
			double sum = Total(x);
			sum = sum / y;
			int hrn = (int)sum;
			int coin = (floor((sum - hrn) * 100 + 0.501));

			return Change(hrn, coin, x);
		}
		else
			Account(x);
	}
	return x;
}

Account Account::DivOfSums(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) / Total(y);
	int hrn = (int)subt;
	int coin = (floor((subt - hrn) * 100 + 0.501));

	return Change(hrn, coin, a);
}

Account Account::Change(int hrn, int coin, Account& d)
{
	d.summa.setH500(hrn / 500);
	hrn -= d.summa.getH500() * 500;
	d.summa.setH200(hrn / 200);
	hrn -= d.summa.getH200() * 200;
	d.summa.setH100(hrn / 100);
	hrn -= d.summa.getH100() * 100;
	d.summa.setH50(hrn / 50);
	hrn -= d.summa.getH50() * 50;
	d.summa.setH20(hrn / 20);
	hrn -= d.summa.getH20() * 20;
	d.summa.setH10(hrn / 10);
	hrn -= d.summa.getH10() * 10;
	d.summa.setH5(hrn / 5);
	hrn -= d.summa.getH5() * 5;
	d.summa.setH2(hrn / 2);
	hrn -= d.summa.getH2() * 2;
	d.summa.setC50(coin / 50);
	coin -= d.summa.getC50() * 50;
	d.summa.setC25(coin / 25);
	coin -= d.summa.getC25() * 25;
	d.summa.setC10(coin / 10);
	coin -= d.summa.getC10() * 10;
	d.summa.setC5(coin / 5);
	coin -= d.summa.getC5() * 5;
	d.summa.setC2(coin / 2);
	coin -= d.summa.getC2() * 2;

	return d;
}

bool Less(Account a, Account b) {
	return a.summa.Total() < b.summa.Total();
}
bool NLess(Account a, Account b) { return !Less(a, b); }

bool Great(Account a, Account b) {
	return a.summa.Total() > b.summa.Total();
}
bool NGreat(Account a, Account b) { return !Great(a, b); }

bool Equal(Account a, Account b) {
	return a.summa.Total() == b.summa.Total();
}
bool NEqual(Account a, Account b) { return !Equal(a, b); }


void Account::Money::setH500(const int x) { h500 = x; };
void Account::Money::setH200(const int x) { h200 = x; };
void Account::Money::setH100(const int x) { h100 = x; };
void Account::Money::setH50(const int x) { h50 = x; };
void Account::Money::setH20(const int x) { h20 = x; };
void Account::Money::setH10(const int x) { h10 = x; };
void Account::Money::setH5(const int x) { h5 = x; };
void Account::Money::setH2(const int x) { h2 = x; };
void Account::Money::setH1(const int x) { h1 = x; };
void Account::Money::setC50(const int x) { c50 = x; };
void Account::Money::setC25(const int x) { c25 = x; };
void Account::Money::setC10(const int x) { c10 = x; };
void Account::Money::setC5(const int x) { c5 = x; };
void Account::Money::setC2(const int x) { c2 = x; };
void Account::Money::setC1(const int x) { c1 = x; };

Account::Money::Money()
{
	h500 = 0;
	h200 = 0;
	h100 = 0;
	h50 = 0;
	h20 = 0;
	h10 = 0;
	h5 = 0;
	h2 = 0;
	h1 = 0;
	c50 = 0;
	c25 = 0;
	c10 = 0;
	c5 = 0;
	c2 = 0;
	c1 = 0;
}
Account::Money::Money(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o)
{
	h500 = a;
	h200 = b;
	h100 = c;
	h50 = d;
	h20 = e;
	h10 = f;
	h5 = g;
	h2 = h;
	h1 = i;
	c50 = j;
	c25 = k;
	c10 = l;
	c5 = m;
	c2 = n;
	c1 = o;
}
Account::Money::Money(Money& a)
{
	h500 = a.h500;
	h200 = a.h200;
	h100 = a.h100;
	h50 = a.h50;
	h20 = a.h20;
	h10 = a.h10;
	h5 = a.h5;
	h2 = a.h2;
	h1 = a.h1;
	c50 = a.c50;
	c25 = a.c25;
	c10 = a.c10;
	c5 = a.c5;
	c2 = a.c2;
	c1 = a.c1;
}
Account::Money::operator string() const
{
	stringstream sout;
	int a = h500 * 500 + h200 * 200 + h100 * 100 +
		h50 * 50 + h20 * 20 + h10 * 10 + h5 * 5 + h2 * 2 + h1;
	int b = c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5 + c2 * 2 + c1;
	while (b >= 100)
	{
		b -= 100;
		a += 1;
	}
	if (b < 10)
		sout << "Cума = " << a << ",0" << b << endl;
	else
		sout << "—ума = " << a << "," << b << endl;

	return sout.str();
}

ostream& operator <<(ostream& out, const Account::Money& x)
{
	out << string(x);
	return out;
}
istream& operator >>(istream& in, Account::Money& x)
{
	do {
		cout << "¬еед≥ть к≥льк≥сть кожноњ купюри:" << endl;
		cout << "500 = "; in >> x.h500;
		cout << "200 = "; in >> x.h200;
		cout << "100 = "; in >> x.h100;
		cout << "50 = "; in >> x.h50;
		cout << "20 = "; in >> x.h20;
		cout << "10 = "; in >> x.h10;
		cout << "5 = "; in >> x.h5;
		cout << "2 = "; in >> x.h2;
		cout << "1 = "; in >> x.h1;
		cout << "0.50 = "; in >> x.c50;
		cout << "0.25 = "; in >> x.c25;
		cout << "0.10 = "; in >> x.c10;
		cout << "0.5 = "; in >> x.c5;
		cout << "0.02 = "; in >> x.c2;
		cout << "0.01 = "; in >> x.c1;
	} while ((x.h500 || x.h200 || x.h100 || x.h50 || x.h20 || x.h10 || x.h5 || x.h2 ||
		x.h1 || x.c50 || x.c25 || x.c10 || x.c5 || x.c2 || x.c1) < 0);

	return in;
}

Account::Money& Account::Money::operator =(const Money& r)
{
	h500 = r.h500;
	h200 = r.h200;
	h100 = r.h100;
	h50 = r.h50;
	h20 = r.h20;
	h10 = r.h10;
	h5 = r.h5;
	h2 = r.h2;
	h1 = r.h1;
	c50 = r.c50;
	c25 = r.c25;
	c10 = r.c10;
	c5 = r.c5;
	c2 = r.c2;
	c1 = r.c1;
	return *this;
}


double Account::Money::Total() {
	int hrn, kop;
	double sum;
	hrn = h500 * 500 + h200 * 200 + h100 * 100 +
		h50 * 50 + h20 * 20 + h10 * 10 + h5 * 5 + h2 * 2 + h1;
	kop = c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5 + c2 * 2 + c1;
	sum = (double)hrn + (double)kop / 100.;
	return sum;
}
