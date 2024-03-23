/*
Problem Description
 
 

Given a matrix of integers A of size N x M in which each row is sorted.

Find and return the overall median of matrix A.

NOTE: No extra memory is allowed.

NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
1 <= N, M <= 10^5

1 <= N*M <= 10^6

1 <= A[i] <= 10^9

N*M is odd



Input Format
The first and only argument given is the integer matrix A.



Output Format
Return the overall median of matrix A.



Example Input
Input 1: 

A = [   [1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]   ] 
Input 2: 

A = [   [5, 17, 100]    ]


Example Output
Output 1: 

 5 
Output 2: 

 17


Example Explanation
Explanation 1: 

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
Median is 5. So, we return 5. 
Explanation 2:

Median is 17.

*/


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int upperBound(vector<int> &arr ,int mid, int col){
    int start=0;
    int end=col-1;
    int ans=col;

    while(start<=end){
        int middle=(start+end)/2;
        if(arr[middle]>mid){
            ans=middle; 
            end=middle-1;
        }
        else{
            start=middle+1;
        }

    }
    return ans;
}


int countSmallerEqual(vector<vector<int>> &matrix ,int row, int col,int mid){
    int cnt=0;
    for(int i=0;i<row;i++){
        cnt+=upperBound(matrix[i],mid,col);
    }
    return cnt;
}


int FindMedian(vector<vector<int>> &matrix){
    int start=INT_MAX;
    int end=INT_MIN;
    int row=matrix.size();
    int col=matrix[0].size();

    for(int i=0;i<row;i++){
        start=min(start,matrix[i][0]);
        end=max(end,matrix[i][col-1]);
    }

    int req=(row*col)/2;

    while(start<=end){
        int mid=(start+end)/2;
        int smallerEqual=countSmallerEqual(matrix,row,col,mid);
        if(smallerEqual<=req){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }

    return start;
}

int main(){

    vector<vector<int>> matrix={{1,3,5},{2,6,9},{3,6,9}};
    int median=FindMedian(matrix);
    cout<<median;


    return 0;
}
