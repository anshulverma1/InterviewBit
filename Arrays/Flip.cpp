/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN.
In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR.
By flipping, we mean change character 0 to 1 and vice-versa.
Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.
If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R.
If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:
Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.

For example,
S = 010
Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001
We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

Another example
If S = 111
No operation can give us more than three 1s in final string. So, we return empty array [].

Time Complexity: O(N)
Space Complexity: O(1)
*/

vector<int> Solution::flip(string A) 
{
    int st = 0, end = 0, maxChange = 0, flag = 0, tempSt = 0, tempEnd = 0, tempMax = 0, i;
    for(i=0; i<A.length(); i++)
    {
        if(flag == 0 && A[i] == '0'){
            tempSt = i+1, tempEnd = i+1;
            tempMax = 1;
            flag = 1; 
        }
        else if(flag == 1)
        {
            if(tempMax > maxChange){
                maxChange = tempMax;
                st = tempSt;
                end = i;
            }
            
            if(A[i] == '1')tempMax--;
            else tempMax++;
            
            if(tempMax < 0) flag = 0;
        }
    }
    
    if(tempMax > maxChange){
        maxChange = tempMax;
        st = tempSt;
        end = i;
    }
    
    vector<int> res;
    if(st == 0 && end == 0) return res;
    res.push_back(st);
    res.push_back(end);
    return res;
}
