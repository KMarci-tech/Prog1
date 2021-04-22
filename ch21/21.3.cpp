#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<numeric>

template<typename T, typename V>
void output_pair(std::vector<T>& a,std::vector<V>& b)
{
	int num = 0;
	std::cout << "\ndouble" << '\t' << "int" << std::endl;
	for(auto p = a.begin(); p!=a.end(); ++p)
	{
		std::cout << *p << '\t' << b[num] << std::endl;
		num++; 
	}
}

struct less_than
{
	int n;
	less_than(int y): n(y) {}
	bool operator()(int x) { return x < n;}
};

int main()
{
	std::ifstream file("21.3.txt");

	std::vector<double> vd;
	double n;
	while(file>>n) vd.push_back(n);

	std::cout << "Elements of vd: " << std::endl;

	for(auto& i : vd)
		std::cout << i << std::endl;

	std::vector<int> vi(16);


	std::copy(vd.begin(),vd.end(),vi.begin());

	output_pair(vd,vi);
	double sum_vd = std::accumulate(vd.begin(),vd.end(),0.0);
	int sum_vi = std::accumulate(vi.begin(),vi.end(),0);
	double sum_dif = sum_vd - sum_vi;


	std::cout << "\nSum of vd: " << sum_vd << std::endl;
	std::cout << "Difference between vi sum and vd sum: " << sum_dif << std::endl;

	std::reverse(vd.begin(),vd.end());

	std::cout << "\nVd after reverse:" << std::endl;

	for(auto& i : vd)
		std::cout << i << std::endl;

	std::cout << "\nMean value of vd: " << sum_vd/vd.size() << std::endl;

	std::vector<double> vd2(16);

	std::copy_if(vd.begin(),vd.end(),vd2.begin(),less_than(sum_vd/vd.size()));

	std::cout << "\nVd2 elements: " << std::endl;

	for(auto& i : vd2)
		std::cout << i << std::endl;


	std::sort(vd.begin(),vd.end());

	std::cout << "\nVd sorted: " << std::endl;

	for(auto& i : vd)
		std::cout << i << std::endl;



}