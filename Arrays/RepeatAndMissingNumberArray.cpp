/*
You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Note that in your output A should precede B.

Example:
Input:[3 1 2 5 3] 
Output:[3, 4] 
A = 3, B = 4

Time Complexity: O(N)
Space Complexity: O(1)
*/


vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    vector<int> res;
    long long n = A.size();
    long long s = (n*(n+1))/2;
    long long p = (n*(n+1)*(2*n+1))/6;
    for(int i=0; i<A.size(); i++)
    {
        s -= A[i];
        p -= (long long)A[i] * (long long)A[i];
    }
    long long t = ((p/s)+(s))/2;
    long long t1 = t - s;
    res.push_back(t1);
    res.push_back(t);
    return res;
}
