/*
Given a collection of intervals, merge all overlapping intervals.

For example:
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

Time Complexity: O(N*Log(N))
Space Complexity: O(1)
*/

/*
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

static bool byStartingTime (Interval& i1, Interval& i2)
{
    return (i1.start < i2.start);
}

 
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> res;
    sort(A.begin(), A.end(), byStartingTime);
    int i = 0, j = 1, count = 0;
    while(i < A.size() && j < A.size())
    {
        if(A[i].end >= A[j].start)
        {
            A[i].end = max(A[i].end, A[j].end);
            A[j].start = -1;
            j++;
            count++;
        }
        else
        {
            i = j;
            j++;
        }
    }
    sort(A.begin(), A.end(), byStartingTime);
    A.erase(A.begin(), A.begin()+count);
    return A;
    
}
