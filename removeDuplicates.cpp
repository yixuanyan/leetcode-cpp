#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slow = 0, fast = 1;
        if (nums.size() == 0)
        {
            return 0;
        }
        while (fast < nums.size())
        {
            if (nums[fast - 1] == nums[fast])
            {
                fast++;
                continue;
            }
            slow++;
            nums[slow] = nums[fast];
            fast++;
        }
        return slow + 1;
    }
};
int main()
{
    Solution sol;
    vector<int> test = {1, 2, 2, 3, 3, 4, 4, 5};
    cout << sol.removeDuplicates(test) << endl;
    return 0;
}
