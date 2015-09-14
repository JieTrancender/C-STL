//alg_transform.cpp
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename anytype>
class MultValue
{
private:
	anytype Factor;

public:
	//Constructor initializes the value to multiply by
	MultValue(const anytype &_val) : Factor(_val){};

	//The function call for the element to be multiplied
	anytype operator()(anytype &elem) const
	{
		return elem * Factor;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	vector<int> v1, v2(7), v3(7);
	vector<int>::iterator Iter1, Iter2, Iter3;

	for (int i = -4; i <= 2; ++i)
	{
		v1.push_back(i);
	}
	cout << "Original vector :\nv1 = ( ";
	for (auto &it : v1)
		cout << it << ' ';
	cout << " )." << endl;

	//Modifying the vector v1 in place
	transform(v1.begin(), v1.end(), v1.begin(), MultValue<int>(2));
	//for_each(v1.begin(), v1.end(), MultValue<int>(2));
	cout << "The elements of the vector v1 multiplied by 2 in place gives: " << "\n v1 mod = ( ";
	for (auto &it : v1)
		cout << it << ' ';
	cout << " )." << endl;

	//Using transform to multiply each element by a factor of 5
	transform(v1.begin(), v1.end(), v2.begin(), MultValue<int>(5));
	cout << "Multplying the elements of the vector v1 mod\n by the factor 5 & copying to v2 gives: \n v2 = ( ";
	for (auto &it : v2)
		cout << it << ' ';
	cout << " )." << endl;

	//The second version of transform used to multiply the elements of the vectors v1 mod & v2 pairwise
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), multiplies<int>());//v3.beg == v1.beg * v2.beg
	cout << "Multiplying elements of the vectors v1 mod v2 pairwise gives:\n v3 = ( ";
	for (auto &it : v3)
		cout << it << ' ';
	cout << " )." << endl;
	return 0;
}
