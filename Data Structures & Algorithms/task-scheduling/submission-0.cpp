class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
            unordered_map<char,int>freq;

            int count=0;
            for(char task :tasks){
                freq[task]++;
                count = max(count,freq[task]);
            }
            int ans = (count-1)*(n+1);
            for(auto f : freq){
                if(f.second == count){
                    ans++;
                }
            }
            return max(ans,(int)tasks.size());
    }
};
