class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength = 1;
        int start = 0;
        int l = s.length();
        vector<vector<bool> > dp(l,vector<bool>(l));
        for(int right=1;right<l;right++){
            for(int left=0;left<=right;left++){
                if(s[right]!=s[left])
                    continue;
                if(right==left)//
                    dp[left][right] = true;
                else if(right-left<=2)
                    dp[left][right] = true;
                else{
                    dp[left][right]=dp[left+1][right-1];
                }//3个边界条件
                if(dp[left][right]==true && right - left + 1 >maxlength){
                    maxlength = right - left + 1;
                    start = left;                   
                }
            }
        }
        return s.substr(start,maxlength);
    }
};
