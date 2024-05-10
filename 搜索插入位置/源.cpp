#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int length = nums.size();
		int Hindex = 0;
		int Tindex = length - 1;
		while (Hindex <= Tindex)
		{
			int half = (Tindex - Hindex) / 2 + Hindex;
			//cout << half << endl;
			if (nums[half] < target)
			{
				Hindex = half + 1;
				//cout << "区间往右缩一次" << endl;
			}
			else if (nums[half] > target)
			{
				Tindex = half - 1;
				//cout << "区间往左缩一次" << endl;
			}
			else
			{
				return half;
			}
		}
		return Tindex + 1;
	}
};

int main(void)
{
	vector<int> nums = { 1,3,5,6 };
	Solution it;
	cout << it.searchInsert(nums, 0) << endl;
	//for(auto it = nums.begin(); it != nums.end(); ++it)
	//{
	//	cout << *it << endl;
	//}
	//for (auto & it : nums)
	//{
	//	cout << it << " ";
	//}
	//cout << endl;
	return 0;
}