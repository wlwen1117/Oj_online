#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int FastIndex = 0;
		int SlowIndex = 0;
		int length = nums.size();

		for (int i = 0; i < length; ++i)
		{
			int target = nums[i];
			if (i - 1 >= 0 && nums[i - 1] == target) 
			{
				for (SlowIndex = i, FastIndex = i; FastIndex < length; ++FastIndex)
				{
					if (target != nums[FastIndex])
					{
						nums[SlowIndex++] = nums[FastIndex];
					}
				}
			}
			
		}

		return length;
	}

};


int main(void)
{
	vector<int> nums = { 1, 1, 2};
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