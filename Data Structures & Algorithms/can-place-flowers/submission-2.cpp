class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(n==0)return true;
        for(int i=0;i<size;i++){
            bool leftEmpty = (i==0)||(flowerbed[i-1]==0)?true:false;
            bool rightEmpty = (i==size-1) || (flowerbed[i+1]==0)?true:false;
            if(flowerbed[i]==0 and leftEmpty and rightEmpty){
                n--;
                flowerbed[i]=1;
                if(n==0)return true;
            }
        }
        return false;
    }
};