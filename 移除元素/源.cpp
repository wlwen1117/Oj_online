#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int offset = 0;
		int length = nums.size();
		for (int i = 0; i < length; ++i)
		{
			if (nums[i] == val)
			{
				offset++;
				for (int j = i + 1; j < length; ++j)
				{
					nums[j - 1] = nums[j];
				}

			}
			i--;
		}
		

		return length - offset;

	}

};

int main(void)
{
	int val = 2;
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	Solution it;
	cout << it.removeElement(nums, val) << endl;
	for(auto it = nums.begin(); it != nums.end(); ++it)
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