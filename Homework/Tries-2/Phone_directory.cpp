/*
  Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:

Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explaination: By running the search query on 
contact list for "g" we get: "geeikistest", 
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list 
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0". 
No results found for "geeips", so print "0".
Your Task:
You do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|)

Constraints:
1 ≤ T ≤ 100, T = number of test cases
1 ≤ n ≤ 50
1 ≤ |contact[i]| ≤ 50
1 ≤ |s| ≤ 6 

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class TrieNode{
  public:
  char data;
  bool isTerminal;
  TrieNode* children[26];
  
  
  TrieNode(char data){
      this->data = data;
      this->isTerminal = false;
      
      for(int i=0;i<26;i++)
      {
          this->children[i] = NULL;
      }
  }
 
};


class Solution{
   void insertWord(TrieNode* &root, string str)
    {
        if(str.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        char ch=str[0];
        int index = ch -'a';
        
        TrieNode * child;
        
        if(root->children[index] != NULL)
        {
          child = root->children[index];
            
        }
        else{
            child = new TrieNode(ch);
            root->children[index] = child;
        }
     
        insertWord(child,str.substr(1));
    }
    
    
    void printSugesstion(TrieNode * curr,vector<string> &temp, string &inputHelper,string & dummy)
    {
        if(curr->isTerminal)
        {
            temp.push_back(inputHelper+dummy);
        }
        
        
        for(char ch = 'a';ch <= 'z';ch++)
        {
            int index = ch-'a';
            TrieNode *next = curr->children[index];
            
            if(next!= NULL)
            {
                dummy.push_back(ch);
                printSugesstion(next,temp,inputHelper,dummy);
                dummy.pop_back();
            }
            
        }
    }
    
    
    vector<vector<string>> getSuggestion(TrieNode* root, string query)
    {
        string inputHelper = "";
        TrieNode *prev= root;
        vector<vector<string>> ans;
        
        for(int i=0;i<query.length();i++)
        {
            char lastch = query[i];
            inputHelper.push_back(lastch);
            
            int index = lastch - 'a';
            TrieNode* curr = prev->children[index];
            
            if(curr != NULL)
            {
                vector<string> temp;
                string dummy="";
                printSugesstion(curr,temp,inputHelper,dummy);
                ans.push_back(temp);
                temp.clear();
                prev = curr;
                
            }
            
            else{
                
                break;
            }
        }
        
        int remaining = query.size()-ans.size();
        for(int i=0;i<remaining;i++)
        {
            ans.push_back({"0"});
        }
        
        return ans;
    }
    
    
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        TrieNode* root = new TrieNode('#');
        for(int i=0;i<n;i++)
        {
            insertWord(root,contact[i]);
        }
        
        
        return getSuggestion(root,s);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
