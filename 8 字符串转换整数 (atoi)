class Solution {
public:
    int myAtoi(string s) {
      int flag = 1;
      int ans = 0;
      int index = 0;
      //int temp = 1;
      while(s[index]==' '){
          index++;
      }
      if(s[index]=='-'){
        flag=-1;
        index++;
      }else if(s[index]=='+'){
        index++;
      }else{
      }
      for(int i=index;i<s.length();i++){
        int tail = s[i] - '0';
        if(s[i]>='0'&&s[i]<='9'){
          if(ans >= (INT_MIN+tail)/10 && ans <=(INT_MAX-tail)/10){
            ans = ans *10+tail*flag;
            //temp = 2;
            continue;
          }else if(ans <  (INT_MIN+tail)/10){
            ans = INT_MIN;
          }else{
            ans = INT_MAX;
          }
        }
           break;
      }
          return ans;
	}
};
