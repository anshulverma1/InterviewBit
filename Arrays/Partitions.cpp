/*
You are given a 1D integer array B containing A integers.
Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.
Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])

Input Format
First argument is an integer A.
Second argument is an 1D integer array B of size A.

Output Format
Return a single integer denoting the number of ways to split the array B into three parts with the same sum.

Input 1:
A = 5
B = [1, 2, 3, 0, 3]
Output 1:
2
Explanation 1:
There are no 2 ways to make partitions -
1. (1,2)+(3)+(0,3).
2. (1,2)+(3,0)+(3).

Input 2:
A = 4
B = [0, 1, -1, 0]
Output 2:
1
Explanation 2:
There is only 1 way to make partition
1. (0)+(-1,1)+(0).

Time Complexity: O(N)
Space Complexity: O(N)
*/

int Solution::solve(int B, vector<int> &A) 
{
    int resultCount = 0;
    if(A.size() < 3) return resultCount;
    unordered_map<int, vector<int>> mp;
    vector<int> cummSum(A.size());
    cummSum[0] = A[0];
    for(int i = 1; i < A.size(); i++)
    {
        cummSum[i] = A[i] + cummSum[i-1];
    }
    int revCummSum = 0;
    for(int i = A.size()-1; i > 1; i--)
    {
        revCummSum += A[i];
        if(mp.find(revCummSum) != mp.end()) mp[revCummSum].push_back(i);
        else mp[revCummSum] = {i};
    }
    for(int i = 0; i < A.size()-2; i++)
    {
        int currSum = cummSum[i];
        for(int j = 0; j < mp[currSum].size(); j++)
        {
            if(cummSum[mp[currSum][j]-1] - currSum == currSum && mp[currSum][j] > i+1) resultCount++;
        } 
    }

    return resultCount;
    
}
