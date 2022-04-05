#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    void trackback(vector<int> &nums, vector<int> &track, vector<vector<int>> &ans, vector<int> &status)
    {
        if (nums.size() == track.size())
        {
            ans.emplace_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!status.at(i))
            {
                track.emplace_back(nums.at(i));
                status.at(i) = 1;
                trackback(nums, track, ans, status);
                track.pop_back();
                status.at(i) = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> track;
        vector<int> status(nums.size());
        trackback(nums, track, ans, status);
        return ans;
    }
};
int main()
{

    Solution sol;
    vector<int> num = {1, 2, 3};
    vector<vector<int>> nums = sol.permute(num);
    for (vector<vector<int>>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        for (int i = 0; i < (*it).size(); i++)
        {
            cout << (*it).at(i) << " ";
        }
        cout << endl;
    }
    return 0;
}
