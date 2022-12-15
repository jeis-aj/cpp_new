#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std; 


void print( auto v2 );
void print(auto,string);
class Solution{
	private:
		vector<int> nums;
		int target;
	public:
		Solution(vector<int> nums,int target){
			cout << "\t NEW OBJ"<<endl;
			cout << "Target : " << target ;
			print(nums,"obj");
			this->nums = nums;
			this->target = target;
		}
		vector<int> pairSum()
		{
			vector <pair<int,int>> result;
			set <int> st;
			for (int i = 0;  i < nums.size(); ++i){
				int key = target - nums[i];
				if(st.find(key) != st.end()){
					auto pr = {key,nums[i]};
					result.push_back(pr);
				}
			}
			return result;
		}
};

int main()
{
	vector <int > nums{ 2,2 ,3 ,5 ,5 ,6 };
	int target = 8;
	Solution one(nums,target);
	auto result = one.pairSum();
	print(result,"result");
	return 0;
}

void print( auto v2 ){
	for( auto ele : v2 ){
		cout << ele.first << " " << ele.second;
	}
	cout << endl;
}
void print(auto cont,string str){
	transform(str.begin(),str.end(),str.begin(),::toupper) ;
	cout <<endl<<endl<< "printing .. "<< str <<endl;
	for (auto val: cont){
		cout << val << " ";
	}
	cout <<endl<<endl<<"! end !"<<endl;
}
