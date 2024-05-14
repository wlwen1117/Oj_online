#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int length = nums.size();
		
	}

};


int main(void)
{
	vector<int> nums = { 1, 1, 2 };
	Solution it;
	int result = it.removeDuplicates(nums);
	cout << result << endl;
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		cout << *it << endl;
	}
	//for (auto & it : nums)
	//{
	//	cout << it << " ";
	//}
	//cout << endl;
	return 0;
}