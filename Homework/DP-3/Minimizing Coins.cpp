/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 11
1 5 7

Output:
3
*/
//recursion apporach----------------------------------------->
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long mod = 1e9 + 7;

long long solve(long long x,vector<long long>&nums){
    if(x==0){
        return 0;
    }

    if(x<0){
        return INT_MAX;
    }
    
    long long mini=INT_MAX;
    for(long long i=0;i<nums.size();i++){
        long long ans=solve(x-nums[i],nums);
       if(ans!=INT_MAX){
          mini=min(ans+1,mini);
       }
    }
    return mini;
}

int main() {
    long long n;
    long long x;
    vector<long long> nums;
    cin >>n;
    cin>>x;
    for(long long i=0;i<n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    long long ans=solve(x,nums);
    if(ans==INT_MAX){
        int p=-1;
        cout<<p;
    }
    else{
        cout<<ans;
    }
    return 0;
}
//MEmoisation apporach------------------------------------------>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long mod = 1e9 + 7;

int memoisation(long long x,vector<long long>&nums,vector<long long> &dp){
    if(x==0){
        return 0;
    }

    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    long long mini=INT_MAX;
    for(long long i=0;i<nums.size();i++){
        long long ans=memoisation(x-nums[i],nums,dp);
       if(ans!=INT_MAX){
          mini=min(ans+1,mini);
       }
    }
    dp[x]=mini;
    return dp[x];   
}

int main() {
    long long n;
    long long x;
    vector<long long> nums;
    cin >>n;
    cin>>x;
    for(long long i=0;i<n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    vector<long long> dp(x+1,-1);
    long long ans=memoisation(x,nums,dp);
    if(ans==INT_MAX){
        int p=-1;
        cout<<p;
    }
    else{
        cout<<ans;
    }
    return 0;
}

//bottom up Apporach
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long mod = 1e9 + 7;

 int tablutation(long long x,vector<long long> &nums){
       vector<long long> dp(x+1,INT_MAX);
       dp[0]=0;
       for(long long i=1;i<=x;i++){
           for(long long j=0;j<nums.size();j++){
            if (i - nums[j] >= 0 && dp[i - nums[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - nums[j]] + 1);
            }
            }    
        }
        return dp[x];
    }
int main() {
    long long n;
    long long x;
    vector<long long> nums;
    cin >>n;
    cin>>x;
    for(long long i=0;i<n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    long long ans=tabltation(x,nums);
    if(ans==INT_MAX){
        int p=-1;
        cout<<p;
    }
    else{
        cout<<ans;
    }
    return 0;
}

