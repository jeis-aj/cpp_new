#include <iostream>
#include <vector>
using namespace std; 

vector<vector<pair<int,int>>> getPath(auto mat, auto Spr, auto Dpr,auto Ppr);
void printPaths(auto mat,ostream& out);
ostream& fn(ostream& = cout);

bool operator==(const pair<int,int>& one,const pair<int,int>& two){
	if (one.first != two.first || one.second != two.second )
		return false;
		return true;
}
vector<pair<int,int>> mkPairlist(auto mat, pair<int,int>& Npr ,pair<int,int>& Ppr){
	pair<int,int> pr;
	vector<pair<int,int>> rtPr;
	int rwSize = mat.size();
	int clSize = mat[0].size();

	pair<int,int> rightPr = {Npr.first+1, Npr.second};
	pair<int,int> leftPr= {Npr.first-1, Npr.second};
	pair<int,int> bottomPr = {Npr.first, Npr.second+1};
	pair<int,int> topPr = {Npr.first, Npr.second-1};

	vector<pair<int,int>> direction = { rightPr,leftPr,topPr,bottomPr };

	for (auto pr: direction){
		if ( pr.first < rwSize && pr.first >= 0 ){
			if ( pr.second < clSize && pr.second >= 0 )
				if ( pr == Ppr);
				else
					rtPr.push_back(pr); 
		}
	}
	return rtPr;
}

int main(int argc, char *argv[])
{
	srand(time(0));
	vector<vector<int>> mat{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 1, 0, 1},
	};
	pair<int,int> Npr{0,0};
	pair<int,int> Dpr{1,6};
	pair<int,int> Ppr{1,0};
	/* vector<vector<pair<int,int>>> result = getPath(mat,Spr,Dpr,Ppr); */
	auto list = mkPairlist(mat,Npr,Ppr);
	for ( auto ele: list ){
		cout << "x:" <<ele.first << "y:"<< ele.second;
		cout <<endl;
	}
	/* cout << pr2 == pr; */
	return 0;
}


vector<vector<pair<int,int>>> getPath(auto mat, auto Spr, auto Dpr,auto Ppr) {
/*
vector<vector<pair<int,int>>> solutionMatrix;
vector<pair<int,int>> arr;
pair<int,int> pr;
int rwSize = mat.size();
int clSize = mat[0].size();
*/
vector<vector<pair<int,int>>> temp;
for (auto CurrentPair: nextPathlist){
	auto nextPathlist = mkPairlist(mat,CurrentPair,Ppr);
		getPath(mat,CurrentPair,Dpr,Spr);
}
return solutionMatrix;
}

void printPaths(auto mat,ostream& out){
	for (auto arr: mat){
		for(auto pr:arr ){
			out << "("<<pr.first << "," <<pr.second <<")";
			out << "->" ;
		}
		out <<endl;
	}
}
