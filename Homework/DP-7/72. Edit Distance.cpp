/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
  */

class Solution {
public:
    //using memoization
    int edit_distance(string &str1 , string &str2 , int i , int j ,  vector<vector<int>>& dp){
    //base case

    if(i==str1.size()){
        return str2.size()-j;
    }

    if(j==str2.size()){
        return str1.size()-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(str1[i]==str2[j]){
        ans= 0 + edit_distance(str1,str2,i+1,j+1 ,dp);
    }
    
    else{
        int replace= 1+ edit_distance(str1,str2,i+1,j+1 ,dp);
        int remove= 1 + edit_distance(str1,str2,i+1,j ,dp);
        int insert= 1+ edit_distance(str1,str2,i,j+1 ,dp);

       ans= min(replace, min(remove,insert));
    }
     dp[i][j]=ans;
       return dp[i][j];  
}
    
    
    //using bottom up apporach-1----->
    int solveUsingTabulation(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, -1));

        for(int col=0; col<=b.length(); col++) {
            dp[a.length()][col] = b.length()-col;
        }
        for(int row=0; row<=a.length(); row++) {
            dp[row][b.length()] = a.length()-row;
        }

        for(int i_index=a.length()-1; i_index>=0; i_index--) {
            for(int j_index=b.length()-1; j_index>=0; j_index--) {
                int ans = 0;
                if(a[i_index] == b[j_index] ) {
                    ans = 0 + dp[i_index+1][j_index+1];
                }
                else {
                    int replace = 1 + dp[i_index+1][j_index+1];
                    int insert = 1 + dp[i_index][j_index+1];
                    int remove = 1 + dp[i_index+1][j_index];
                    ans = min(insert,min(remove,replace));
                }
                dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];
    }
    
    
    //using bottom up apporach-2
    
    int solveUsingTabulation2(string a, string b) {
        vector<int> curr(a.length()+1, 0);
        vector<int> next(a.length()+1, 0);

        for(int row=0; row<=a.length(); row++) {
            next[row] = a.length()-row;
        }

    for(int j_index=b.length()-1; j_index>=0; j_index--) {
        curr[a.length()] = b.length()-j_index;
        for(int i_index=a.length()-1; i_index>=0; i_index--) {
            
                int ans = 0;
                if(a[i_index] == b[j_index] ) {
                    ans = 0 + next[i_index+1];
                }
                else {
                    int replace = 1 + next[i_index+1];
                    int insert = 1 + next[i_index];
                    int remove = 1 + curr[i_index+1];
                    ans = min(insert,min(remove,replace));
                }
                curr[i_index] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingTabulation2(word1, word2);
        return ans;
    }
};
