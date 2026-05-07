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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts,ends;
        for (const auto& i : intervals){
            starts.emplace_back(i.start);
            ends.emplace_back(i.end);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());

        int min_rooms=0;int cur_rooms=0;
        int s=0,e=0;
        while(s<starts.size()){
            if(starts[s]<ends[e]){
                cur_rooms++;
                min_rooms=max(cur_rooms,min_rooms);
                ++s;
            }
            else{
                ++e;
                cur_rooms--;
            }
        }
        return min_rooms;
    }
};
