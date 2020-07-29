/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:
Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Time Complexity: O(N*Log(N))
Space Complexity: O(N)
*/

bool byMaxCombination(const string A, const string B)
{
    return ( A + B > B + A);
}

string Solution::largestNumber(const vector<int> &A) 
{
    vector<string> nums;
    for(int i = 0; i < A.size(); i++) nums.push_back(to_string(A[i]));
    sort(nums.begin(), nums.end(), byMaxCombination);
    string result = "";
    for(int i=0 ; i < nums.size(); i++) result += nums[i];
    int start = 0;
    while(result[start]=='0') start++;
    result = result.substr(start);
    if(result.length() != 0) return result;
    return "0";
}
