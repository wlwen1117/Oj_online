#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {

	}
};

int main(void)
{
	vector<int> nums = { -1,0,3,5,9,12 };
	for(auto it = nums.begin(); it != nums.end(); ++it)
	{
		cout << *it << endl;
	}
	for (auto & it : nums)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}