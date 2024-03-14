/*

You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

 

Example 1:

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
Example 2:

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
Example 3:

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You cannot make any change, so the maximum length is 1.
 

Constraints:

1 <= s.length <= 105
t.length == s.length
0 <= maxCost <= 106
s and t consist of only lowercase English letters.

*/

#include<iostream>
#include<limits.h>
#include<climits>
using namespace std;

bool isPossible(string &s ,string &t , int mid,int maxCost){
     int i=0;
        int j=0;
        
        int price = 0;
        int mini_price = INT_MAX;

        while(j<s.size()){
            price += abs(s[j] - t[j]);

            if(j -i + 1 == mid){
                mini_price = min(price,mini_price);
                price -= abs(s[i]-t[i]);

                i++;
            }

            j++;
        }

        return (mini_price <= maxCost);
}

int solve(string &s ,string &t, int maxCost){
    int start=0;
    int end=s.size()+1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(s,t,mid,maxCost)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}


int main(){
    string s="abcd";
    string t="bcdf";
    int maxCost=3;
    int ans=solve(s,t,maxCost);
    cout<<ans;
    return 0;
}
