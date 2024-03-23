/*
You're given two sorted arrays 'arr1' and 'arr2' of size 'n' and 'm' respectively and an element 'k'.



Find the element that would be at the 'kth' position of the combined sorted array.



Position 'k' is given according to 1 - based indexing, but arrays 'arr1' and 'arr2' are using 0 - based indexing.



For example :
Input: 'arr1' = [2, 3, 45], 'arr2' = [4, 6, 7, 8] and 'k' = 4
Output: 6
Explanation: The merged array will be [2, 3, 4, 6, 7, 8, 45]. The element at position '4' of this array is 6. Hence we return 6.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5
2 3 6 7 9
4
1 4 8 10
4
Sample Output 1:
4
Explanation of sample input 1 :
The merged array will be: [1, 2, 3, 4, 6, 7, 8, 9, 10]

The element at position '4' is 4 so we return 4.
Sample Input 2:
5
1 2 3 5 6
5
4 7 8 9 100  
6
Sample Output 2:
6
Explanation of sample input 2 :
The merged array will be: [1, 2, 3, 4, 5, 6, 7, 8, 9, 100]

The element at position '6'  is 6, so we return 6.
Constraints :
1 <= 'n' <= 5000
1 <= 'm' <= 5000
0 <= 'arr1[i]', 'arr2[i]' <= 10^9
1 <= 'k' <= 'n' + 'm'

'n' and 'm' denote the size of 'arr1' and 'arr2'.

Time limit: 1 second
Expected time complexity :
The expected time complexity is O(log('n') + log('m')). 

  */



#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int upperBound(vector<int> &arr ,int mid){
    int start=0;
    int end=arr.size()-1;
    int ans=arr.size();

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



int Kth_smallest_element(vector<int> &nums1 ,vector<int> &nums2, int k){
    
    int start=min(nums1[0],nums2[0]);
    int end=max(nums1[nums1.size()-1],nums2[nums2.size()-1]);
    while(start<=end){
        int mid=(start+end)/2;
        int smallerEqual=0;
        smallerEqual=upperBound(nums1,mid);
        smallerEqual+=upperBound(nums2,mid);
        if(smallerEqual<=k){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }

    return start;
}

int main(){

    vector<int> nums1={2,3,45};
    vector<int> nums2={4,6,7,8};
    int k=7;
    int median=Kth_smallest_element(nums1,nums2,k-1);
    cout<<median;


    return 0;
}
