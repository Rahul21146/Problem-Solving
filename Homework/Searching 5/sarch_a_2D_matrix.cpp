/*
ou are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
  */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int m = matrix.size();
     int n = matrix[0].size();
     int e=m*n-1;
     int s=0;
     int k;
     while(s<=e)
     {
         k=s+(e-s)/2;
         if(matrix[k/n][k%n]==target)
         {
             return true;
         }
         else if(matrix[k/n][k%n]<target)
         {
             s=k+1;
         }
         else
         {
             e=k-1;
         }
     }
     return false;
    }

int main(){

    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    bool ans= searchMatrix(matrix,target);
    cout<<ans;


    return 0;
}
