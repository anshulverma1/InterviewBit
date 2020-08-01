/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.
If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

Examples:
Input 1:
    A = [1, 2, 3]
Output 1:
    [1, 3, 2]

Input 2:
    A = [3, 2, 1]
Output 2:
    [1, 2, 3]

Input 3:
    A = [1, 1, 5]
Output 3:
    [1, 5, 1]

Input 4:
    A = [20, 50, 113]
Output 4:
    [20, 113, 50]
    
Time Complexity: O(N)
Space Complexity: O(1)
*/

vector<int> Solution::nextPermutation(vector<int> &A) 
{
    if(A.size() <= 1) return A;
    int j = A.size()-2;
    int i = A.size()-1;
    for( ; j>=0; j--)
    {
        if(A[j] < A[j+1]) break;
    }

    if(j >= 0)
    {
        while(A[i] <= A[j]) i--;
        swap(A[i],A[j]);
        
    }
    reverse(A.begin()+j+1,A.end());
    return A;
}
