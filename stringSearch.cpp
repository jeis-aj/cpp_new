#include <iostream>	
#include <vector>	
#include <algorithm>	
#include <map>	
#include <unordered_map>	
using namespace std; 

void print(auto);
bool comp(pair<char,int> arg1,pair<char,int> arg2);
int main(int argc, char *argv[])
{
	map <char,int> mp;

	string str = "hello world how are you"; // string for test
	for ( char ch: str ){ 		
		mp[ch] += 1; }		// incr values wrt key

	vector <pair<char,int>> vect(mp.begin(),mp.end());
	print(vect);			// key--value before sort
	sort(vect.begin(),vect.end(),comp);
	cout<<"sorted"<<endl;
	print(vect);			// key--value after sort

	return 0;
}

bool comp(pair<char,int> arg1,pair<char,int> arg2){
	return arg1.second > arg2.second;		// Descending Sorting comparator
}
void print(auto arg){
	for (auto val: arg){
		cout << val.first <<" -- "<< val.second <<endl; }		// print values
}
