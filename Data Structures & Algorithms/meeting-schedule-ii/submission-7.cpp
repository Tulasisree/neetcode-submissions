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
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),[](auto& a,auto &b){
            return a.start<b.start;
        });
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int count=0;
        for(auto& interval: intervals){
            if(!minHeap.empty() && interval.start >= minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};
