#include <string>
#include <vector>
#include <iostream>


template<typename T>

struct S
{
	S(T t = 0): val(t) {}
	
	T& get();
	const T& get() const;
	void set(T v) { val = v;}



private:
	T val;

};
 

template<typename T>
T& S<T>::get() { return val;}

template<typename T>
const T& S<T>::get() const { return val;}



template<typename T>
void read_val(T& v)
{
	std::cin >> v;
}


template<typename T>
std::istream& operator>>(std::istream& is, S<T>& s)
{
	is >> s.get();
	return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, S<T>& s)
{
	os << s.get();
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> &v)
{
	for(int i = 0; i < v.size()-1; ++i)
		os << v[i] << ", ";
	os << v[v.size()-1];
	return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T> &v)
{
	for(int i = 0; i < v.size(); ++i)
		is >> v[i];
	return is;
}



int main()
{
	S<int> i(10);
	S<char> c('c');
	S<double> d(1.1);
	S<std::string> s("string");
	S<std::vector<int>> v{std::vector<int>{1,2,3}};

	read_val(i);
	read_val(c);
	read_val(d);
	read_val(s);
	read_val(v);

	std::cout << "--------------------" << std::endl;

	std::cout << i.get() << std::endl;
	std::cout << c.get() << std::endl;
	std::cout << d.get() << std::endl;
	std::cout << s.get() << std::endl;
	std::cout << v.get() << std::endl;

	

	return 0;
}