#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	vector <int> ans;	
	priority_queue <pair <int,int> > pq;
	pair<int,int> arr [] = {
		{1,2},
		{3,3},
		{1,4},
		{8,8},
		{3,2},
		{2,9},
		{2,2},
	};

	for (auto ele: arr){
		pq.push(ele);
	}

	for (auto ele: arr){
		cout << ele.first << " " << ele.second <<endl;
	}
	cout <<" pq" <<endl;

	while(!pq.empty()){
		cout << pq.top().first << " " << pq.top().second <<endl;
		pq.pop();
	}
	cout <<" it " <<endl;


	return 0;
}
