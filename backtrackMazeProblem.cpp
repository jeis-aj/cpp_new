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
		vector<vector<pair<int,int>>> solutionMatrix;
	public:
		void printPaths(ostream& out=cout);
		void print(ostream& out = cout);
		void sortSolution();
		T getMatrix()	{
			return mat;
		}
		Solution(T mat){
			if( typeid(T) != typeid(vector<vector<char>>) ){
				cout << "Wrong Type Matrix Recieved"<<endl;
					errLog(112);
				return;
			}
			this->mat = mat;
			/* print(); */
		}
		vector<vector<pair<int,int>>> allPaths();
		bool comp(vector<pair<int,int>> element1,vector<pair<int,int>> element2);
};

template <typename T>
bool Solution<T>::comp(vector<pair<int,int>> element1,vector<pair<int,int>> element2){
	return element1.size()<element2.size();
}
template <typename T>
void Solution<T>::sortSolution(){
	sort(solutionMatrix.begin(),solutionMatrix.end(),comp);
}
// put random rat and cheese
template <typename T>
void randomPositionTarget(T& mat){
	int rw = rand()%mat.size();
	int cl = rand()%mat[0].size();
	mat[rw][cl]	= '&';		// rat
	rw = rand()%mat.size();
	cl = rand()%mat[0].size();
	mat[rw][cl]	= '@';		// cheese
}
void fstore(auto obj){
	// fstore function receives any object and perform _obj.print(store)_  operation
	// in which store is a output file stream.
	//
	// print() function should be print(ostream& out) where _out_ recieves file stream & when calling this function
	
	/* fstream store("out.txt",ios::out); */
	fstream store("out.txt",ios::app);
	obj.print(store);
	store.close();
}
int otherMain();

// Generate Random bool matrix , when row and coloumn are specified.
vector <vector<char>> generateMatrix(int rw,int cl){
	vector<char> arr;
	vector <vector<char>> matrix;
	for (int i=0; i< rw; ++i){
		for (int j=0; j< cl; ++j){
			bool state = rand()%7 <= 1;			// probability of tracks 1/7
			char ch = state?'.':' ';
			arr.push_back(ch);
		}
		matrix.push_back(arr);
		arr.clear();
	}
	return matrix;
}

// Generate random matrix
vector <vector<char>> generateMatrix(){
	 int cl = 19+rand()%9;	// random number bw 3 and 8
	 int rw = 19+rand()%9;
	 return generateMatrix(rw,cl);
}

auto getPath(auto mat,pair<int,int> Spr,pair<int,int> Dpr){
	vector<vector<pair<int,int>>> result;
	vector<pair<int,int>> arr;
	/* pair<int,int> pr; */
}
int nextMain()
{
	srand(time(0));
	auto ranMat = generateMatrix();
	randomPositionTarget(ranMat);
	Solution S1(ranMat);
	errLog(0xFF01);
	errLog(0x0A01);
	errLog(0x0FF1);
	S1.print();
	/* S1.allPaths(); */
	/* S1.printPaths(); */
	fstore(S1);
	return 0;
}


template<typename T>
void Solution<T>::print(ostream& out){
	if ( typeid(this->mat) != typeid(vector<vector<char>>))
	{
	out << "type doesn't match" <<endl;
	return;
	}
	out << "\tGIVEN MATRIX "<<endl;
	out <<"ROWS: " << mat.size()<<" COLOUMS: "<< mat[0].size()<<endl;
	for (auto arr: mat){
		for ( auto val: arr ){
			out <<"  "<< val;
		}
		out << endl;
	}
	out << endl;
}

template<typename T>
vector<vector<pair<int,int>>> Solution<T>::allPaths(){
	vector<vector<pair<int,int>>> ans;
	vector<pair<int,int>> li;
	pair<int,int> pr;
	pr = {3,5};
	li.push_back(pr);
	ans.push_back(li);
	solutionMatrix = ans;
	return ans;
}
// print obtained paths
template<typename T>
void Solution<T>::printPaths(ostream& out){
	for (auto arr: solutionMatrix){
		for(auto pr:arr ){
			out << "("<<pr.first << "," <<pr.second <<")";
			out << "->" ;
		}
		out <<endl;
	}
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
