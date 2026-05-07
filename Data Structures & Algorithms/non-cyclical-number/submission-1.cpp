class Solution {
public:
    bool isHappy(int n) {
        if(n==0)return false;
        int slow,fast;
        slow=n,fast=n;
        do{
            slow=s(slow);
            fast=s(fast);
            fast=s(fast);
        }
        while(slow!=fast);
        if(slow==1){
            return true;
        }
        else{
            return false;
        }
    }
    int s(int n){
        int res=0;
        while(n>0){
            int temp=n%10;
            res+=temp*temp;
            n/=10;
        }
        return res;
    }
};
