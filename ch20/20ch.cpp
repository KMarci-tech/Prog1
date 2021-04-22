#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <string>
#include <array>


template<typename C>
void inc_contents(C& c, int n = 1)
{
    for (auto& a : c)
        a += n;
}
 
template<typename T>
void printout(T& t)
{
	for(const auto& v : t)
		std::cout << v << ' ';
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for(Iter1 p = f1; p != e1; ++p)
	{
		*f2++ = *p; // postfix mert léptetjük v1-et is
	}
	return f2;
}


int main()
{


	std::array<int,10> a1 = {0,1,2,9,4,5,6,3,8,9};

	std::vector<int> v1 = {0,1,2,9,4,5,6,3,8,9};

	std::list<int> list1 = {0,1,2,3,4,5,6,7,8,9};

	std::array<int,10> a2 = a1;

	std::vector<int> v2 = v1;

	std::list<int> list2 = list1;

	inc_contents(a1,2);
	inc_contents(v1,3);
	inc_contents(list1,5);

	std::cout << "Vector1 elements: ";
	printout(v1);
	std::cout << "\nArray1 elements: ";
	printout(a1);
	std::cout << "\nList1 elements: ";
	printout(list1);
	std::cout << '\n';

	my_copy(a1.begin(),a1.end(),v1.begin());
	my_copy(list1.begin(),list1.end(),a1.begin());

	std::cout << "\nAfter copy: " << std::endl;

	std::cout << "\nVector1 elements: ";
	printout(v1);
	std::cout << "\nArray1 elements: ";
	printout(a1);
	std::cout << "\nList1 elements: ";
	printout(list1);
	std::cout << "\n\n";


	std::vector<int>::iterator it1 = std::find(v1.begin(),v1.end(),3);
	if(it1 != v1.end())
	{
		int index1 = it1 - v1.begin();
		std::cout << "3 in the vector is at index:" << index1 << std::endl;
	}
	else
		std::cout << "value was not found" << std::endl;


	std::list<int>::iterator it2 = std::find(list1.begin(),list1.end(),27);
	if(it2 != list1.end())
	{
		int index2 = 0;
		for(std::list<int>::iterator p = list1.begin(); p != it2; ++p)
		{
			++index2;
		}
		std::cout << "index:" << index2 << std::endl;
	}
	else
		std::cout << "value(27) was not found in list1" << std::endl;



	
	return 0;
} 