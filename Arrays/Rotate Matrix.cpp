/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
*/


void Solution::rotate(vector<vector<int> > &A) 
{
    int l = A[0].size();
    int temp;
    for(int i=0; i<l/2; i++)
    {
        for(int j=i; j<l-i-1; j++)
        {
            temp = A[i][j];
            A[i][j] = A[l-1-j][i];
            A[l-1-j][i] = A[l-1-i][l-1-j];
            A[l-1-i][l-1-j] =A[j][l-1-i];
            A[j][l-1-i] = temp;
        }
    }
}
