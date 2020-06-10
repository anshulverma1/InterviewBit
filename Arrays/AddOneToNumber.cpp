/*
Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.

Example:
If the vector has [1, 2, 3]
the returned vector should be [1, 2, 4]

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

Time Complexity = O(N)
Space Complexity = O(1)

Similar LeetCode question: https://leetcode.com/problems/add-to-array-form-of-integer/
*/

vector<int> Solution::plusOne(vector<int> &A)
{
    int ind = A.size()-1, carry = (A[ind] + 1)/10;
    A[ind] =  (A[ind] + 1)%10;
    while(carry && ind>0)
    {
        ind--;
        A[ind] += carry;
        carry = A[ind]/10;
        A[ind] %= 10;
        
    }
    if(carry > 0) A.insert(A.begin(), carry);
    ind = 0;
    while(A[ind]==0) ind++;
    A.erase(A.begin(), A.begin()+ind);
    return A;
}
