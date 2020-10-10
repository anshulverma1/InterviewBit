/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

Make sure the returned intervals are also sorted.

Time Complexity: O(N)
Space Complexity: O(1)

Similar LeetCode question: https://leetcode.com/problems/merge-intervals/
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 * }
 * */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    vector<Interval> ans;
    bool inserted = false;
    for(int i =0; i < intervals.size() ;i++)
    {
        //No overlap
        if(intervals[i].start > newInterval.end && inserted == false)
        {
            ans.push_back(newInterval);
            inserted = true;
            ans.push_back(intervals[i]);
        }
        //Mergin overlap
        else if((intervals[i].start >= newInterval.end ||intervals[i].end >= newInterval.start) && inserted == false)
        {
            auto temp = intervals[i];
            temp.start = min(intervals[i].start, newInterval.start);
            while( i+1 < intervals.size() && intervals[i+1].start <= newInterval.end) i++;
            temp.end = max(intervals[i].end, newInterval.end);
            inserted = true;
            ans.push_back(temp); 
        }
        //General Case
        else ans.push_back(intervals[i]);
    }
    //newInterval last.
    if(inserted == false)
        ans.push_back(newInterval);
    return ans;
}
