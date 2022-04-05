#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int s = nums.size();
        if (s == 0)
            return -1;
        return binarysearch(nums, 0, s - 1, target);
    }
    int binarysearch(vector<int> &nums, int l, int r, int target)
    {
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[l] <= nums[mid] && target <= nums[mid] && target >= nums[l])
            {
                r = mid;
            }
            else if (nums[l] <= nums[mid])
            {
                l = mid + 1;
            }
            else if (nums[r] >= nums[mid] && target >= nums[mid] && target <= nums[r])
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return -1;
        // if (l > r)
        //     return -1;
        // int mid = (l + r) >> 1;
        // if (nums[mid] == target)
        // {
        //     return mid;
        // }
        // else if (nums[l] <= nums[mid] && target <= nums[mid] && target >= nums[l])
        // {
        //     return binarysearch(nums, l, mid, target);
        // }
        // else if (nums[l] <= nums[mid])
        // {
        //     return binarysearch(nums, mid + 1, r, target);
        // }
        // else if (nums[r] >= nums[mid] && target >= nums[mid] && target <= nums[r])
        // {
        //     return binarysearch(nums, mid + 1, r, target);
        // }
        // else
        //     return binarysearch(nums, l, mid, target);
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {5, 1, 3};
    cout << sol.search(nums, 3) << endl;
    return 0;
}
