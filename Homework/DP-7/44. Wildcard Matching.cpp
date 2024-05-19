/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
  */
class Solution {
public:

bool isMatchHelper(string &s, int si, string &p ,int pi,vector<vector<int>> &dp){
    //base case
    if(si==s.size() && pi==p.size()){
        return true;
    }

    if(si==s.size() && pi<p.size()){
         
        for(int i=pi;i<p.size();i++){
            if(p[i]!='*'){
                return false;
            }
        }
        return true;
    }

    if(dp[si][pi]!=-1){
        return dp[si][pi];
    }

    if(s[si]==p[pi] || p[pi]=='?'){
        dp[si][pi] =isMatchHelper(s,si+1,p,pi+1,dp);
        return dp[si][pi];
    }

    if(p[pi]=='*'){
        //tret * as a NULL
        bool caseA=isMatchHelper(s,si,p,pi+1,dp);
        //Treat * consume 1 char
        bool caseB=isMatchHelper(s,si+1,p,pi,dp);
        dp[si][pi]= caseA||caseB;
        return dp[si][pi];
    }
    //char doen not match
    dp[si][pi]=false;
    return dp[si][pi];
}


    bool isMatch(string s, string p) {
    int si=0;
    int pi=0;
    vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
    return isMatchHelper(s,si,p,pi,dp);
        
    }
};
