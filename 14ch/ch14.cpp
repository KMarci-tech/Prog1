#include "std_lib_facilities.h"

class B1
	{
	public:
		virtual void vf() {std::cout << "B1::vf()\n";}
		void f() {std::cout << "B1::f()\n";}
		virtual void pvf() =0;

	};

class D1 : public B1
{
public:
	void vf() override {std::cout << "D1::vf()\n";}
	void f() {std::cout << "D1::f()\n";}
	virtual void pvf() {std::cout << "D1_pvf\n";}

};

class D2: public D1
{
public:
	void vf() override {std::cout << "D2::vf()\n";}
	void f()  {std::cout << "D2::f()\n";}
	virtual void pvf() override {std::cout << "D2_pvf\n";}
};


class B2
{
public:
	virtual void pvf() =0;
};

class D21 : public B2
{
	string s = "string";
	void pvf() override {std::cout << s << '\n';}
};

class D22 : public B2
{
public:
	int m = 10;
	void pvf() override {std::cout << m << '\n';}
};

void f(B2& b) {	b.pvf();}

int main()
{
/*
	B1 b;
	b.vf();
	b.f();
*/

	D1 d;
	d.vf();
	d.f();
	d.pvf();

	B1 &b_ref = d;
	b_ref.vf();
	b_ref.f();
	b_ref.pvf();

	D2 dd;
	dd.vf();
	dd.f();
	dd.pvf();

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

	return 0;
}