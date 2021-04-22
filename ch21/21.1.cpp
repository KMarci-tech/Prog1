#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <list>


struct Item{
	std::string name;
	int iid;
	double value;
	Item(std::string s, int i, double d): name(s), iid(i), value(d) {}
	Item(): name(std::string()), iid(int()), value(double()) {}


};

std::ostream& operator<<(std::ostream& os, Item& i)
{
	os << i.name << '\t' << i.iid << '\t' << i.value << '\n';
	return os;
}

std::istream& operator>>(std::istream& is, Item& i)
{
	is >> i.name >> i.iid >> i.value;
	return is;
}

template<typename T>
void printout(T& t)
{
	for(auto& i : t)
		std::cout << i;
}

struct erase_name
{
	std::string ename;
	erase_name(std::string s): ename(s) {}
	bool operator()(const Item& x) const {return x.name == ename;}
};

struct erase_iid
{
	int val;
	erase_iid(int x): val(x) {}
	bool operator()(const Item& y) const {return y.iid == val;}
	
};

struct  cmp_name {
    bool operator()(const Item& a, const Item& b) const {return a.name < b.name;}
};

struct cmp_iid{
	bool operator()(const Item& a, const Item& b) const {return a.iid > b.iid;}
};

struct cmp_value{
	bool operator()(const Item& a, const Item& b) const {return a.value > b.value;}
};



int main()
{
	
	std::vector<Item> vi;
	std::list<Item> li;

	std::ifstream file("21.1.txt");
	Item a;
	while(file>>a)
	{
		vi.push_back(a);
		li.insert(li.end(),a);

	} 



	printout(vi);

	std::cout << "\nSorted by name: " << "\n\n";
	std::sort(vi.begin(),vi.end(), cmp_name());
	printout(vi);

	std::cout << "\nSorted by iid: " << "\n\n";
	std::sort(vi.begin(),vi.end(),cmp_iid());
	printout(vi);
	
	std::cout << "\nSorted by value: " << "\n\n";
	std::sort(vi.begin(),vi.end(),cmp_value());
	printout(vi);

	Item h("horse_shoe",99,12.34);
	Item c("Canon_S400",9988,499.95);
	vi.insert(vi.end(),h);
	vi.insert(vi.end(),c);
	
	vi.erase(std::find_if(vi.begin(),vi.end(),erase_name("Chloe")));
	vi.erase(std::find_if(vi.begin(),vi.end(),erase_name("Tyler")));
	vi.erase(std::find_if(vi.begin(),vi.end(),erase_iid(4)));
	vi.erase(std::find_if(vi.begin(),vi.end(),erase_iid(0)));


	std::cout << std::endl;
	printout(vi);


	std::cout << "\nList elements:" << std::endl;

	printout(li);

	std::cout << "\nSorted by name(list)" << "\n\n";
	li.sort(cmp_name());
	printout(li);

	std::cout << "\nSorted by iid(list): " << "\n\n";
	li.sort(cmp_iid());
	printout(li);
	
	std::cout << "\nSorted by value(list): " << "\n\n";
	li.sort(cmp_value());
	printout(li);

	std::cout << std::endl;
	li.insert(li.end(),h);
	li.insert(li.end(),c);

	std::list<Item>::iterator li_it = std::find_if(li.begin(),li.end(),erase_name("Jack"));
    li.erase(li_it);
    li_it = std::find_if(li.begin(),li.end(),erase_name("Thomas"));
    li.erase(li_it);


    li_it = std::find_if(li.begin(),li.end(),erase_iid(2));
    li.erase(li_it);
    li_it = std::find_if(li.begin(),li.end(),erase_iid(8));
    li.erase(li_it);

	std::cout << std::endl;
	printout(li);

	return 0;
}