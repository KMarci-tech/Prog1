#include "std_lib_facilities.h"

struct Person
{
private:
	string first_name;
	string last_name;
	int age;
public:
	Person(string fn,string ln,int a) : first_name(fn), last_name(ln), age(a) {
		if(age < 1 || age > 149) error("Helytelen kor");

		string bad = "\":'[]*&^%$#@!.";

		for(int i = 0; i < first_name.size(); ++i)
		{
			for(int j = 0; j < bad.size(); ++j)
			{
				if(first_name[i] == bad[j]) error("Helytelen nev");
			}
		}

		for(int i = 0; i < last_name.size(); ++i)
		{
			for(int j = 0; j < bad.size(); ++j)
			{
				if(last_name[i] == bad[j]) error("Helytelen nev");
			}
		}


	}
	Person() {}
	string f_name() const { return first_name;}
	string l_name() const { return last_name;}
	int get_age() const {return age;}
	

};

ostream& operator<<(ostream& o, const Person& p)
{
	o << p.f_name() << ' ' << p.l_name() << ' ' << p.get_age() << '\n';
	return o;
}

istream& operator>>(istream &i, Person &p)
{
	string first_name;
	string last_name;
	int age;


	i >> first_name >> last_name >> age;
	p = Person(first_name,last_name,age);
	return i;
}




int main()
{
	vector<Person> people = {};
	cout << "Kilepes x,x,1" << endl;

	for(Person p; cin >> p;)
	{
		if (p.f_name() == "x")
			break;
		else
			people.push_back(p);
	}

	for(Person p : people)
		cout << p << '\n';


	return 0;
}