#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

void errLog(int);
template<typename T>
class Solution{
	private:
		/* vector<vector<int>> mat; */
		T mat;
	public:
		void print(ostream& out = cout);
		Solution(T mat){
			if( typeid(T) != typeid(vector<vector<int>>) ){
				cout << 
					"Wrong Type Matrix Recieved"<<endl;
					errLog(112);
				return;
			}
			this->mat = mat;
			print();
		}
		vector<vector<pair<int,int>>> allPaths();

};

void fstore(auto obj){
	// fstore function receives any object and perform _obj.print(store)_  operation
	// in which store is a output file stream.
	//
	// print() function should be print(ostream& out) where _out_ recieves file stream & when calling this function
	//
	
	/* fstream store("out.txt",ios::out); */
	fstream store("out.txt",ios::app);
	obj.print(store);
	store.close();
}
int otherMain();

// Generate Random bool matrix , when row and coloumn are specified.
vector <vector<int>> generateMatrix(int rw,int cl){
	vector<int> arr;
	vector <vector<int>> matrix;
	for (int i=0; i< rw; ++i){
		for (int j=0; j< cl; ++j){
			bool state = rand()%2 == 0;
			arr.push_back(state);
		}
		matrix.push_back(arr);
		arr.clear();
	}
	cout << " in gen cl: " << matrix.size()<< " rw: "<< matrix[0].size()<<endl;
	return matrix;
}

// Generate random matrix
vector <vector<int>> generateMatrix(){
	 int cl = 3+rand()%5;	// random number bw 3 and 8
	 int rw = 3+rand()%5;
	 cout << "cl: " <<cl<< " rw: "<<rw <<endl;
	 return generateMatrix(rw,cl);
}

int main(int argc, char *argv[])
{
	srand(time(0));
	otherMain();
	/* generateMatrix(); */
	return 0;
}
int otherMain()
{
	vector<vector<int>> mat{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 1, 0, 1},
	};
	auto ranMat = generateMatrix();
	int rw = ranMat.size();
	int cl = ranMat[0].size();
	cout << "cl: " <<cl<< " rw: "<<rw <<endl;
	
	errLog(0xFF01);
	errLog(0x0A01);
	errLog(0x0FF1);
	Solution S1(ranMat);
	S1.print();
	fstore(S1);
	/* auto ans = S1.allPaths(); */
	return 0;
}


template<typename T>
void Solution<T>::print(ostream& out){
	if ( typeid(this->mat) != typeid(vector<vector<int>>))
	{
	out << "type doesn't match" <<endl;
	return;
	}
	out << "\tGIVEN MATRIX "<< endl<<endl;
	for (auto arr: mat){
		for ( auto val: arr ){
			out <<"\t"<< val;
		}
		out << endl;
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

void errLog(int errInt){
	fstream err("errLog.txt",ios::app);
	err << errInt ;
	/* err.width(10); */
	err << "\t:";
	/* err.width(20); */
	if (errInt > 0xAA00){
		err <<"\t\t\t";
	}
	else if (errInt > 0x0A00){
		err <<"\t\t";
	}
	else if (errInt > 0x00FF){
		err <<"\t";
	}
	switch(errInt)
	{
		case 0x00FA:
			err << "Matrix type doesn't match" ;
			break;
		case 0xFFFF:
			err << "recursion timeout" ;
			break;
		default:
			/* err.width(6); */
			err << "error";
	}
	err << endl;
}
