/*

You have given an array A having N elements and an integer S. You have to find a
maximum number X such that the sum of all its subarrays of size X is less than or equal
to S.
Example Input:
A = [1, 3, 4, 2]
S = 7
Example Output:
2
Explanation:
All subarrays of size 2 have the sum less than 7.
Subarays are :
1. [1, 3]
2. [3, 4]
3. [4, 2]

  */

#include<iostream>
#include<vector>
using namespace std;

bool check(int mid, vector<int> &nums, int s, int size)
{
   int j=0;
   int subSum=0;
   while(j<mid)
   {
     subSum+=nums[j];
       j++;
   }
   int i=0;
   while(j<size)
   {
       if(subSum>s){
        return false;
       }
       subSum+=nums[j++];
       subSum-=nums[i++];
   }
   return true;
}
int main()
{
    int n;
    cout<<"enter the number of th element in the array"<<endl;
    cin>>n;
    vector<int> nums;
    cout<<"enter the elements in array"<<endl;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        nums.push_back(data);
    }
    int s;
    cout<<"enter the target sum"<<endl;
    cin>>s;

    int start=1;
    int end=n;
    int ans=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(check(mid,nums,s,n))
        {
         ans=mid;
         start=mid+1;
        }
        else
         end=mid-1;
    }
    cout<<"Maximum Subarray size:"<<ans;
    return 0;
}
