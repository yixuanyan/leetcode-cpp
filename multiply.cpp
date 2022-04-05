#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int l1 = num1.size(), l2 = num2.size();
        vector<int> ans(l1 + l2);
        string result;
        for (int i = l1 - 1; i >= 0; i--)
        {
            for (int j = l2 - 1; j >= 0; j--)
            {
                ans.at(i + j + 1) += (num1.at(i) - '0') * (num2.at(j) - '0');
            }
        }
        for (int i = l1 + l2 - 1; i >= 1; i--)
        {
            ans.at(i - 1) += ans.at(i) / 10;
            ans.at(i) %= 10;
        }
        int index = ans.at(0) == 0 ? 1 : 0;
        while (index < l1 + l2)
        {
            result.push_back((ans.at(index) + '0'));
            index++;
        }
        return result;
    }
};
int main()
{
    Solution sol;
    cout << sol.multiply("123456789", "987654321") << endl; // 121932631112635269
    return 0;
}
