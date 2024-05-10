#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		int left = 0;
		int right = num;
		while (left <= right)
		{
			int half = left + (right - left) / 2;
			long long sqrt = (long long)half * half;
			if (sqrt > num)
			{
				right = half - 1;
			}
			else if (sqrt < num)
			{
				left = half + 1;
			}
			else
			{
				return true;
			}
		}
		return false;

	}
};

int main(void)
{
	int x = 14;
	Solution it;
	cout << it.isPerfectSquare(x) << endl;
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