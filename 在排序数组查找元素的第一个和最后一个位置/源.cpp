#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int length = nums.size();
		int Hindex = 0;
		int Tindex = length - 1;
		vector<int> result = { -1, -1 };
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
				int FirstHalf = half;
				result[0] = FirstHalf;
				result[1] = FirstHalf;
				while (FirstHalf + 1 < length && nums[FirstHalf + 1] == nums[FirstHalf])
				{
					result[1] = ++FirstHalf;
				}

				FirstHalf = half;

				while (FirstHalf - 1 >= 0 && nums[FirstHalf - 1] == nums[FirstHalf]) 
				{
					result[0] = --FirstHalf;
				}
				return result;
			}
		}
		
		return result;
	}
};

int main(void)
{
	vector<int> nums = { 5,7,7,8,8,10 };
	Solution it;
	vector<int> result = it.searchRange(nums, 6);
	for(auto it = result.begin(); it != result.end(); ++it)
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