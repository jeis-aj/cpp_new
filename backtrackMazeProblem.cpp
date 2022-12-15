#include <iostream>
#include <vector>

using namespace std; 

template<typename T>
class Solution{
	private:
		/* vector<vector<int>> mat; */
		T mat;
	public:
		void print();
		Solution(T mat){
			if( typeid(T) != typeid(vector<vector<int>>) ){
				cout << 
					"Wrong Type Matrix Recieved"<<endl;
				return;
			}
			this->mat = mat;
			print();
		}
		vector<vector<pair<int,int>>> allPaths();

};


int main(int argc, char *argv[])
{
	vector<vector<int>> mat{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 1, 0, 1},
	};

	Solution S1(mat);
	/* S1.print(); */
	/* auto ans = S1.allPaths(); */
	return 0;
}


template<typename T>
void Solution<T>::print(){
	if ( typeid(this->mat) != typeid(vector<vector<int>>))
	{
	cout << "type doesn't match" <<endl;
	return;
	}
	cout << "\tGIVEN MATRIX "<< endl<<endl;
	for (auto arr: mat){
		for ( auto val: arr ){
			cout <<"\t"<< val;
		}
		cout << endl;
	}
}

template<typename T>
vector<vector<pair<int,int>>> Solution<T>::allPaths(){
	vector<vector<pair<int,int>>> ans;
	vector<pair<int,int>> li;
	pair<int,int> pr;
	pr = {3,5};
	li.push_back(pr);
	ans.push_back(li);
	return ans;
}
