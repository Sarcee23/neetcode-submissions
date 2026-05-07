/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int,int> mp;
        int have = 0;
        for(auto& interval: intervals){
            mp[interval.start]++;
            mp[interval.end]--;
        }
        for(auto&[index,count] : mp){
            have += count;
            if(have >=2){
                return false;
            }
        }
        return true;
    }
};
