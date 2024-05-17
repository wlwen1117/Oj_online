#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		int L1 = s.size();
		int L2 = t.size();

		int SP = 0;
		int FP = 0;

		while (FP < L1)
		{
			if (s[FP] == '#')
			{
				
			}
			++FP;
		}
		
	}

};


int main(void)
{
	//vector<int> nums = { 0,1,0,3,12 };
	string s = "ab#c";
	string t = "ad#c";

	Solution it;
	it.backspaceCompare(s, t);
	//for (auto it = nums.begin(); it != nums.end(); ++it)
	//{
		//cout << *it << endl;
	//}
	for (auto & it : s)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}