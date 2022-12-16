#include <iostream>
#include <vector>
using namespace std; 

/* vector<vector<pair<int,int>>> getPath(auto mat, auto Spr, auto Dpr,auto Ppr); */
void getPath(auto mat,auto & result, auto Spr, auto Dpr,auto Ppr);
void printPaths(auto mat,ostream& out = cout);
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
	pair<int,int> Spr{0,0};
	pair<int,int> Dpr{2,2};
	pair<int,int> Ipr{-1,-1};

	vector<vector<pair<int,int>>> result;
	getPath(mat,result,Spr,Dpr,Ipr);
	/* cout << "hello" <<endl; */
	printPaths(result);
	return 0;
}


void getPath(auto mat,auto & result, auto Spr, auto Dpr,auto Ppr) {
	vector<pair<int,int>> temp;
	if (Spr == Dpr){
		result.push_back(temp);
	}
	else if(temp.front() == temp.back());
	else{
		temp.push_back(Spr);
		auto nextPathlist = mkPairlist(mat,Spr,Ppr);
		for (auto CurrentPair: nextPathlist){
			getPath(mat,result,CurrentPair,Dpr,Spr);
		}
	}
	temp.pop_back();
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
