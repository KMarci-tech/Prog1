#include<map>
#include<iostream>
#include<algorithm>
#include<string>
#include<numeric>

void my_read(std::map<std::string,int>& x)
{
	int i = 0;
	int a;
	std::string s;

	while(i<3)
	{
		std::cin >> s >> a;
		x.insert(make_pair(s,a));
		++i;
	}
}

struct my_sum{
	int operator()(int sum,  std::pair<std::string,int> map1) {return sum += map1.second;}
};


int main()
{

	std::map<std::string,int> msi;

	my_read(msi);

	std::cout << "\nMap elements:\n";

	for(auto& i : msi)
		std::cout << i.first << ' ' << i.second << std::endl;

	msi.erase(msi.begin(),msi.end());

	std::cout << '\n';

	my_read(msi);



	int sum = std::accumulate(msi.begin(),msi.end(),0,my_sum());

	std::cout << "\nSum of interegers:" << sum << std::endl;

	std::map<int,std::string> mis;

	for (const auto& a : msi)
        mis[a.second] = a.first;

    std::cout << '\n';

	for(auto& i : mis)
		std::cout << i.first << ' ' << i.second << std::endl;

	return 0;
}