#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		int left = 0;
		int right = x;
		while (left <= right)
		{
			int half = left + (right - left) / 2;
			long long sqrt = (long long)half * half;
			if (sqrt > x)
			{
				right = half - 1;
			}
			else if (sqrt < x)
			{
				left = half + 1;
			}
			else
			{
				return half;
			}
		}
		return right;
	}
};

int main(void)
{
	int x = 2147395599;
	Solution it;
	cout << it.mySqrt(x) << endl;
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