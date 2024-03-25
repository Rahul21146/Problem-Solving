/*

Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.


Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.
 

Expected Time Complexity: O(K*Log(N))
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 50
1 <= mat[][] <= 10000
1 <= K <= N*N

*/



#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;


int Kth_element(vector<vector<int>> &matrix ,int k){
    int n=matrix.size();
    int start=matrix[0][0];
    int end=matrix[n-1][n-1];
    while(start<end){
        int mid=start+(end-start)/2;
        int count=0;
        for(int i=0;i<n;i++){
            count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }

        if(count<k){
            
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return start;
}

int main(){

    vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}};
    int k=8;
    int element=Kth_element(matrix,k);
    cout<<element;

    return 0;
}
