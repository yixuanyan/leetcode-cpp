class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || ( x % 10 == 0 && x != 0))//负数不是回文数
                                            //如果数字的最后一位是 0，为了使该数字为回文，必须是0
            return false;
        int ans = 0;
        while(x > ans){//当原始数字小于或等于反转后的数字时，就意味着已经处理了一半位数的数字了
            ans = ans * 10 + x % 10;
            x /= 10;
        }
		return x == ans || x == ans / 10;//奇数还要/10
    }
};
