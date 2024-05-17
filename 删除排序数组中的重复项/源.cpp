#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int length = nums.size();

		int FastIndex = 1;
		int SlowIndex = 1;
		while (FastIndex < length)
		{
			
			if (nums[FastIndex] != nums[FastIndex - 1])
			{
				nums[SlowIndex++] = nums[FastIndex];
			}
			++FastIndex;	

		}
	}

};


int main(void)
{
	vector<int> nums = { 1, 1, 2};
	Solution it;
	it.moveZeroes(nums);
	//cout << result << endl;
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