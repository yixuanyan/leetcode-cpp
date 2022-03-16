class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            if(res <INT_MIN/10 || res >INT_MAX/10 ){//  INT_MIN <=rev⋅10+digit <= INT_MAX   
                                                    //  INT_MIN/10 <=rev <= INT_MAX/10
                return 0;
            }
            int tail = x % 10;
            x /=10;
            res = res*10 +tail;
        }
        return res;
    }
};
