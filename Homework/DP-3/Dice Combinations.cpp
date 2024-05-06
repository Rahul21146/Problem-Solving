/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
4
  */
//recursion--------------------------------------------->
#include<iostream>
using namespace std;
long long mod = 1e9 + 7;
long long solve(long long n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }

    long long include = 0;
    for (long long i = 1; i <= 6; i++) {
        if (n - i >= 0)
            include += solve(n - i)%mod;
    }
    return include%mod;
}

int main() {
    long long n;
    cin >> n;
    long long ans = solve(n);
    cout << ans;
    return 0;
}

//memoisation-------------------------------------------------->
#include<iostream>
#include<vector>
using namespace std;
long long mod = 1e9 + 7;
long long solve(long long n,vector<long long> &dp) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    long long include = 0;
    for (long long i = 1; i <= 6; i++) {
        if (n - i >= 0)
            include += solve(n - i,dp)%mod;
    }
    dp[n]=include%mod;
    return dp[n];
}

int main() {
    long long n;
    cin >> n;
    vector<long long> dp(n+1,-1);
    long long ans = solve(n,dp);
    cout << ans;
    return 0;
}

//bottom up appoach--------------------------------------->

#include<iostream>
#include<vector>
using namespace std;
long long mod = 1e9 + 7;
long long solve(long long n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; 
    
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= 6 && i - j >= 0; j++) {
            dp[i] += dp[i - j];
            dp[i] %=mod;
        }
    }
    
    return dp[n];
}

int main() {
    long long n;
    cin >> n;
    long long ans = solve(n);
    cout << ans;
    return 0;
}
