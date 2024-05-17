#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int length = nums.size();
		int SP = 0;
		int FP = 0;

		while (FP < length)
		{
			if (nums[FP] != 0)
			{
				nums[SP++] = nums[FP];
			}
			++FP;
		}

		while (SP < length)
		{
			nums[SP] = 0;
			++SP;
		}
	}

};


int main(void)
{
	vector<int> nums = { 0,1,0,3,12 };
	Solution it;
	it.moveZeroes(nums);
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