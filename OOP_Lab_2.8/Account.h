#pragma once
#include <string>
using namespace std;

class Account
{
private:
	string secondname;
	int no;
	double percent;

public:
	class Money
	{
	private:
		int h500, h200, h100, h50, h20, h10, h5, h2, h1, c50, c25, c10, c5, c2, c1;
	public:
		void setH500(const int);
		void setH200(const int);
		void setH100(const int);
		void setH50(const int);
		void setH20(const int);
		void setH10(const int);
		void setH5(const int);
		void setH2(const int);
		void setH1(const int);
		void setC50(const int);
		void setC25(const int);
		void setC10(const int);
		void setC5(const int);
		void setC2(const int);
		void setC1(const int);

		int getH500() const { return h500; };
		int getH200() const { return h200; };
		int getH100() const { return h100; };
		int getH50() const { return h50; };
		int getH20() const { return h20; };
		int getH10() const { return h10; };
		int getH5() const { return h5; };
		int getH2() const { return h2; };
		int getH1() const { return h1; };
		int getC50() const { return c50; };
		int getC25() const { return c25; };
		int getC10() const { return c10; };
		int getC5() const { return c5; };
		int getC2() const { return c2; };
		int getC1() const { return c1; };

		Money();
		Money(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
		Money(Money&);

		Money& operator =(const Money&);
		operator string() const;
		friend ostream& operator <<(ostream&, const Money&);
		friend istream& operator >>(istream&, Money&);

		double Total();
	};

	Money summa;
public:
	string getSecondame() const { return secondname; }
	int getNo() const { return no; }
	double getPercent() const { return percent; }

	Account();
	Account(int, double);
	Account(const Account&);

	Account& operator =(const Account&);
	operator string() const;

	friend ostream& operator <<(ostream&, const Account&);
	friend istream& operator >>(istream&, Account&);

	void setSecondname(string);
	bool setNo(int);
	bool setPercent(double);
	void setSumma();

	double Total(const Account&);

	void ChangeOwner();
	void GetMoney();
	void AddMoney();
	Account MakePercent(Account&);
	Account ToDollar(Account&);
	Account ToEuro(Account&);
	void Propys();

	Account Add(const Account&, const Account&, Account&);
	Account Subtract(const Account&, const Account&, Account&);
	Account Multiply(Account&, const double);
	Account Division(Account&, const double);
	Account DivOfSums(const Account&, const Account&, Account&);
	Account Change(int, int, Account&);
	friend bool Less(Account x, Account y);
	friend bool NLess(Account x, Account y);
	friend bool Great(Account x, Account y);
	friend bool NGreat(Account x, Account y);
	friend bool Equal(Account x, Account y);
	friend bool NEqual(Account x, Account y);
};

