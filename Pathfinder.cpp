#include <iostream>
#include <thread>
#include <algorithm>
#include <map>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 
typedef pair<int,int> ind;				// defined an alternative name to pair<int,int> -> ind, so that tedious typing can be reduced
char ratSymbol = '&';								// rat symbol in matrix
char cheeseSymbol = '@';							// cheese symbol in matrix
char pathValidSymbol = '.';							// valid path symbol in matrix
char pathBlockSymbol = ' ';							// path block symbol in matrix

void errLog(int);
vector <vector<char>> generateMatrix();
vector <vector<char>> generateMatrix(int rw,int cl);

template<typename T>
class Solution{												// main pathfinder class begins here
	private:
		/* vector<vector<int>> mat; */
		T mat;
		ind SourcePair;
		ind DestPair;
		ind Initialpair{-1,-1};
		vector<vector<ind>> result;
		ind Spr;
		ind Ppr;
	public:
		void fstore(string fileName,void (*fn)(ostream&));
		vector<ind> mkPairlist( auto Npr , auto Ppr);
		void getPath();
		void getPath(auto temp, auto mp);
		void printVisual(ostream& = cout, int = -1);
		void printPaths(ostream& out=cout);
		void print(ostream& out = cout);
		void sortSolution();
		pair<ind,ind> randomPositionTarget();
		vector<vector<ind>> allPaths();
		T getMatrix()	{
			return mat;
		}
		Solution( T mat){
			if( typeid(T) != typeid(vector<vector<char>>) ){
				cout << "Wrong Type Matrix Recieved"<<endl;
					errLog(112);
				return;
			}
			this->mat = mat;
		}
};
template <typename T>					
void Solution<T>::sortSolution(){								// Sorting solution vector ( result ), for finding shortest path first
	sort(result.begin(),result.end(),[](auto one,auto two){
			return one.size() < two.size();
			});
}

// put random rat and cheese
template <typename T>
pair<ind,ind> Solution<T>::randomPositionTarget(){				// function manipulate matrix (mat), put random rat and cheese somewhere in the valid matrix location
	SourcePair.first = rand()%mat.size();
	SourcePair.second = rand()%mat[0].size();
	mat[SourcePair.first][SourcePair.second]	= ratSymbol;		// rat
	DestPair.first = rand()%mat.size();
	DestPair.second = rand()%mat[0].size();
	mat[DestPair.first][DestPair.second]	= cheeseSymbol;		// cheese
	Spr = SourcePair;
	return {SourcePair,DestPair};
}

template <typename T>
void Solution<T>::fstore(string fileName,void (*fn)(ostream&)){
	// fstore function receives any object and perform _obj.print(store)_  operation
	// in which store is a output file stream.
	//
	// print() function should be print(ostream& out) where _out_ recieves file stream & when calling this function
	
	/* fstream store("out.txt",ios::out); */
	fstream store(fileName,ios::app);
	fn(store);
	store.close();
}

// Generate Random bool matrix , when row and coloumn are specified.

vector<vector<char>> generateMatrix(int rw,int cl){
	// generate matrix based on rw and cl size ( row size && coloumn size)
	// and put random paths and blocks
	vector<char> arr;
	vector <vector<char>> matrix;
	for (int i=0; i< rw; ++i){
		for (int j=0; j< cl; ++j){
			bool state = rand()% 10 < 6;										// probability of tracks 1/7
			char ch = state? pathValidSymbol : pathBlockSymbol ;
			arr.push_back(ch);
		}
		matrix.push_back(arr);
		arr.clear();
	}
	return matrix;
}

// Generate random matrix without specifying row and coloumn size ( randomly generate )
vector <vector<char>> generateMatrix(){
	 int cl = 10 +rand()%5;	// random number bw 10 and 14
	 int rw = 8 +rand()%5;
	 /* int cl = 3+rand()%3;	// random number bw 3 and 8 */
	 /* int rw = 3+rand()%3; */
	 return generateMatrix(rw,cl);
}

int randomPathFinder();
int main(int argc, char *argv[])
{
	char ch;
	while(ch != 'x'){			// Execute multiple times until key character x recieved
		randomPathFinder();
		cout << endl <<"Press 'X' to quit " <<endl;
		cin.get(ch);
	}
	return 0;
}

int randomPathFinder()			// main function to Execute random path find
{
	srand(time(0));
	auto ranMat = generateMatrix();
	Solution  S1(ranMat);
	auto pos = S1.randomPositionTarget();
	fstream store("out.txt",ios::app);
	/* S1.print(store); */
	S1.print();
	S1.getPath();

	/* S1.printPaths(); */		// printing all paths by pairs

	S1.sortSolution();			// sort solution matrix (result) so that shortest path will get in first
	/* S1.printVisual(store,3);			// visually prints paths, if any integer value provided that many paths will be printed, second argument by default is cout ( ostream& ) */
	S1.printVisual(cout,3);			// visually prints paths, if any integer value provided that many paths will be printed, second argument by default is cout ( ostream& )
	store.close();
	cout << "END" <<endl;

	/*
	errLog(0xFF01);
	errLog(0x0A01);
	errLog(0x0FF1);				// error logs can be included for debugging purpose
	*/

	return 0;
}


template<typename T>
void Solution<T>::print(ostream& out){	//		prints matrix in in its original form
	if ( typeid(this->mat) != typeid(vector<vector<char>>))			
	{
	out << "type doesn't match" <<endl;
	return;
	}
	out << "\tGIVEN MATRIX "<<endl;
	out <<"ROWS: " << mat.size()<<" COLOUMS: "<< mat[0].size()<<endl;
	for (auto arr: mat){
		for ( auto val: arr ){
			out <<" "<< val;
		}
		out << endl;
	}
	out << endl;
}

template<typename T>
void Solution<T>::getPath() {			// intial fn before executing recursive call of getPath
	vector<ind> temp;
	map <ind,bool> mp;
	getPath(temp,mp);
}

template<typename T>
vector<T> proc(auto obj){
	static vector<T> vect;
	vect.push_back(obj);
	return vect;
}

template<typename T>
void Solution<T>::getPath( auto temp, auto mp) {		// Recursively search for valid paths( backtrack/bruteforce )
	if ( !result.empty() && !(temp.size() > result.back().size()) ){
		/* mp[Spr] = false; */
		temp.clear();
		Spr = SourcePair;
	}
	if (Spr == DestPair){
		temp.push_back(Spr);
		result.push_back(temp);
		temp.pop_back();
	}
	else if(mp[Spr]);
	else{
			temp.push_back(Spr);
			mp[Spr] = true;
			auto nextPathlist = mkPairlist(Spr,Ppr);
			for (auto CurrentPair: nextPathlist){
				Spr = CurrentPair;
				/* auto obj = thread(getPath,temp,mp); */						// multithreading code
				/* auto vect = proc(obj); */
				getPath(temp,mp);												// single core/thread code
		}
	}
	mp[Spr] = false;
	temp.pop_back();
	/* for(auto obj:vect){ */
	/* 	obj.join(); } */
}

// print obtained paths in text
template<typename T>
void Solution<T>::printPaths(ostream& out){		// prints Solution vector (result)
	if(result.empty()){
		cout<< "No Path Available " <<endl;
		return;
	}
	for (auto arr: result){						// way of formating path ( text output )
		for(auto pr:arr ){
			out << "("<<pr.first << "," <<pr.second <<")";
			out << "->" ;
		}
		out <<endl;
	}
}

void errLog(int errInt){									// error logs for easy debugging 
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
	}														// hierarchial visualization of errors 
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

template<typename T>
void Solution<T>::printVisual(ostream& co ,int maxCount){				// visually print all valid path matrix ( result matrix in the form of  - vector<vector<pair<int,int>>> - )
	int i = 0;
	if(result.empty()){
		co << "No Path Available " <<endl;
		return;
	}
	co << "Number of Solutions Found: "<< result.size() << endl;
	ind pr;
	map<ind,bool> mp; 
	if ( maxCount != -1 ){									// if no argument passed in function, default argument is -1, so it prints all paths. but if provided any, prints that many
		co << "List of top "<< maxCount << " Solutions"<< endl; }
	for (auto cont: result){
		if ( i == maxCount )
			break;
		++i;
		co <<endl<<"New Path: \t\t\t\t\t\t\t\t ###"<<endl;				// just to see if any solution achieved in glimps of look during execution
		for (auto Mpr: cont){
			mp[Mpr] = true;
		}
		for(int i=0; i <mat.size(); ++i){
			for(int j=0; j <mat[0].size(); ++j){
				pr = {i,j};
				if ( pr == SourcePair){
					co << " " << ratSymbol ;									// rat symbol
				}
				else if ( pr == DestPair){
					co << " " << cheeseSymbol ;								// cheese symbol
				}
				else if(mp[pr]){
					co << " "<< pathValidSymbol ;							// valid path symbol can be changed here
				}
				else
					co << " "<< pathBlockSymbol ;							// path block symbol can be changed here
			}
			co<<endl;
		}
		mp.clear();
	}
}

template<typename T>
vector<ind> Solution<T>::mkPairlist( auto Npr , auto Ppr){				// mkpairlist creates vector of adjacent valid path
	ind pr;																
	vector<ind> rtPr;
	int rwSize = mat.size();
	int clSize = mat[0].size();

	ind rightPr = {Npr.first+1, Npr.second};							// four direction of valid pair
	ind leftPr= {Npr.first-1, Npr.second};
	ind bottomPr = {Npr.first, Npr.second+1};
	ind topPr = {Npr.first, Npr.second-1};

	vector<ind> direction = { rightPr,bottomPr,leftPr,topPr };
	for (auto pr: direction){
		if ( pr.first < rwSize && pr.first >= 0 ){
			if ( pr.second < clSize && pr.second >= 0 )					// ignoring pair out of edge pair
				if ( pr == Ppr);										// ignoring previously travelled pair
				else
				{
					char ch = mat[pr.first][pr.second];
					if (ch != ' ')										// push back paths if character is not ' ', just not to get print path through block
					rtPr.push_back(pr); 
				}
		}
	}
	return rtPr;
}
