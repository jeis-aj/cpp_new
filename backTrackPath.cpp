#include <iostream>
#include <map>
#include <vector>
using namespace std; 

void getPath(auto mat,auto & result, auto Spr, auto Dpr,auto Ppr);
void printPaths(auto mat,ostream& out = cout);
ostream& fn(ostream& = cout);

bool operator==(const pair<int,int>& one,const pair<int,int>& two){
	if (one.first != two.first || one.second != two.second )
		return false;
	return true;
}
vector<pair<int,int>> mkPairlist(auto mat, pair<int,int> Npr ,pair<int,int> Ppr){
	pair<int,int> pr;
	vector<pair<int,int>> rtPr;
	int rwSize = mat.size();
	int clSize = mat[0].size();

	pair<int,int> rightPr = {Npr.first+1, Npr.second};
	pair<int,int> leftPr= {Npr.first-1, Npr.second};
	pair<int,int> bottomPr = {Npr.first, Npr.second+1};
	pair<int,int> topPr = {Npr.first, Npr.second-1};

	vector<pair<int,int>> direction = { rightPr,bottomPr,leftPr,topPr };

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

void printList(auto vect){
	for ( auto Spr: vect ){
		cout << "x:" <<Spr.first<<" y:"<<Spr.second <<" -> ";
	}
	cout <<endl;}
void printVisual(auto mat,auto vect);
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
	pair<int,int> Dpr{3,3};
	pair<int,int> Ipr{-1,-1};

	vector<vector<pair<int,int>>> result;
	getPath(mat,result,Spr,Dpr,Ipr);
	/* auto vect = mkPairlist(mat,Spr,Npr); */
	/* cout << "hello" <<endl; */
	printVisual(mat,result);
	printPaths(result);
	return 0;
}


void getPath(auto mat,auto & result, auto Spr, auto Dpr,auto Ppr) {
	static vector<pair<int,int>> temp;
	static map <pair<int,int>,bool> mp;
	if (Spr == Dpr){
		/* cout << "dest reach" <<endl; */
		temp.push_back(Spr);
		result.push_back(temp);
		temp.pop_back();
	}
	else if(mp[Spr]){
 	/* cout << "same node"  <<endl; */
	}
	else{
		/* cout << "else"  <<endl; */
		temp.push_back(Spr);
		mp[Spr] = true;
		/* printList(temp); */
		auto nextPathlist = mkPairlist(mat,Spr,Ppr);
		/* printList(nextPathlist); */
		for (auto CurrentPair: nextPathlist){
			getPath(mat,result,CurrentPair,Dpr,Spr);
		}
		temp.pop_back();
	}
}
void printVisual(auto mat,auto vect){
	map<pair<int,int>,bool> mp; 
	for (auto cont: vect){
		cout <<endl<<"New Path:"<<endl;
		for (auto Mpr: cont){
			mp[Mpr] = true;
		}
			for(int i=0; i <mat.size(); ++i){
				for(int j=0; j <mat[0].size(); ++j){
						if(mp[{i,j}]){
							cout <<" * ";
						}
						else
							cout << "   ";
					}
				cout<<endl;
		}
			mp.clear();
	}
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
