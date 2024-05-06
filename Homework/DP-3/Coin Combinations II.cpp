/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 9
2 3 5

Output:
3
  */

//recursion Apporach-------------------------------------->
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(long long x, vector<int> &nums, set<vector<int>> &s, vector<int> &temp, int index) {
    if (x == 0) {
        s.insert(temp);
        return;
    }
    if (index >= nums.size() || x < 0) {
        return;
    }
    temp.push_back(nums[index]);
    solve(x - nums[index], nums, s, temp, index);
    temp.pop_back();
    solve(x, nums, s, temp, index + 1);
}

int main() {
    long long n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (long long i = 0; i < n; i++) {
        cin >> nums[i];
    }

    set<vector<int>> s;
    vector<int> temp;
    solve(x, nums, s, temp, 0);

    cout << s.size();

    return 0;
}
