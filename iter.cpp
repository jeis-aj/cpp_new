#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iterator>

using namespace std; 

int main(int argc, char *argv[])
{
	vector <int> v{1,2,3,4};	
	map<string, int> mp;

	mp["hello"] = 88;
	mp["hell"] = 90;
	mp["ell"] = 92;

	for (auto val: mp){
	cout << val.first <<" ";
	cout << val.second <<endl;
	}

	vector<int>::iterator it;
	it = v.begin();
	v.insert(it,8);
	for (auto val: v){
	cout << val <<endl;
	}
	sort(v.begin(),v.end());
	cout << "sorted " <<endl;
	for (auto val: v){
	cout << val <<endl;
	}
	return 0;
}
