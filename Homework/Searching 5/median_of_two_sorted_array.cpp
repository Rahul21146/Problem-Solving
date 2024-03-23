/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//binary search apporach

double findMedain(vector<int> &nums1 ,vector<int> &nums2){
    int n1=nums1.size();
    int n2=nums2.size();
    if(n1>n2){
        return findMedain(nums2,nums1);
    }

    int start=0;
    int end=n1;
    int left=(n1+n2+1)/2;
    int n=n1+n2;

    while(start<=end){
        int mid1=(start+end)>>1;
        int mid2=left-mid1;
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
        if(mid1<n1){
            r1=nums1[mid1];
        }
        if(mid2<n2){
            r2=nums2[mid2];
        }
        if(mid1-1>=0){
            l1=nums1[mid1-1];
        }
        if(mid2-1>=0){
            l2=nums2[mid2-1];
        }

        if(l1<=r2 && l2<=r1){
            if(n%2==1){
                return max(l1,l2);
            }
            else{
                return double(max(l1,l2)+min(r1,r2))/2.0;
            }
        }

        else if(l1>r2){
            end=mid1-1;
        }
        else{
            start=mid1+1;
        }

    }
    return 0;

}








//iteerative appoarach
/*double findMedain(vector<int> &nums1 ,vector<int> &nums2){
    int nums1_index=0;
    int nums2_index=0;
    vector<int> ans;

    while(nums1_index<nums1.size() && nums2_index<nums2.size()){
        if(nums1[nums1_index]<=nums2[nums2_index]){
            ans.push_back(nums1[nums1_index++]);
        }
        else{
             ans.push_back(nums2[nums2_index++]);
        }
    }

    while(nums1_index<nums1.size()){
        ans.push_back(nums1[nums1_index++]);
    }

    while(nums2_index<nums2.size()){
        ans.push_back(nums2[nums2_index++]);
    }

    int mid=ans.size()/2;
    if(mid%2==0){
        return double((ans[mid]+ans[mid-1])/2.0);
    }

    return double(ans[mid]);

}*/


int main(){
    vector<int> nums1={1,2};
    vector<int> nums2={3,4};

    double medain=findMedain(nums1,nums2);
    cout<<medain;


    return 0;
}
