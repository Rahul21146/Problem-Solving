/*
You are given two arrays of strings wordsContainer and wordsQuery.

For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].

 

Example 1:

Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

Output: [1,1,1]

Explanation:

Let's look at each wordsQuery[i] separately:

For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
Example 2:

Input: wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]

Output: [2,0,2]

Explanation:

Let's look at each wordsQuery[i] separately:

For wordsQuery[0] = "gh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
For wordsQuery[1] = "acbfgh", only the string at index 0 shares the longest common suffix "fgh". Hence it is the answer, even though the string at index 2 is shorter.
For wordsQuery[2] = "acbfegh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
 

Constraints:

1 <= wordsContainer.length, wordsQuery.length <= 104
1 <= wordsContainer[i].length <= 5 * 103
1 <= wordsQuery[i].length <= 5 * 103
wordsContainer[i] consists only of lowercase English letters.
wordsQuery[i] consists only of lowercase English letters.
Sum of wordsContainer[i].length is at most 5 * 105.
Sum of wordsQuery[i].length is at most 5 * 105.
*/

const int SIZE = 26;
class Trie{
public:
    char node;
    pair<int,int> st;
    Trie* ar[SIZE];
    Trie(char c){
        this->node = c;
        for(int i=0;i<26;i++) this->ar[i] = nullptr;
    }
};

class Solution {

    void insert(Trie* root,string& s,int ind,int len){
        Trie* tempRoot = root;
        for(int i=0;i<s.size();i++){
            int index = s[i]-'a';
            if(tempRoot->ar[index]==nullptr){
                tempRoot->ar[index] = new Trie(s[i]);
                tempRoot->ar[index]->st = {len,ind};
            }
            tempRoot = tempRoot->ar[index];
            if((tempRoot->st).first>len){
                tempRoot->st = {len,ind};
            }
           
        }
    }

    pair<int,int> search(Trie* root,string& s){
        Trie* temp = root;
        int n = s.size();
        for(int i=0;i<n;i++){
            int ind = s[i]-'a';
            if(temp->ar[ind]==nullptr){
                int index = (temp->st).second;
                return temp->st;
            }
            temp = temp->ar[ind];
        }
        int last = (temp->st).second;
        return temp->st;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* trie = new Trie('#');
        int minLen = 1e6, ind = 1e6;
        for(int i=0;i<wordsContainer.size();i++){
            string wordTemp = wordsContainer[i];
            int n = wordTemp.size();
            if(n<minLen){
                minLen = n;
                ind = i;
            }
            reverse(wordTemp.begin(),wordTemp.end());
            insert(trie,wordTemp,i,n);
        }       
        trie->st = {minLen,ind};
        vector<int> ans;
        for(string word:wordsQuery){
            string wordTemp = word;
            int n = word.size();
            reverse(wordTemp.begin(),wordTemp.end());
            pair<int,int> ind1 = search(trie,wordTemp);
            cout << ind1.first << " " << ind1.second << endl;
            ans.push_back(ind1.second);
        }
        return ans;
    }
};
