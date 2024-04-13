/*
  We are given a Trie with a set of strings stored in it. Now the user types in a prefix of his search query, we need to give him all recommendations to auto-complete his query based on the strings stored in the Trie. We assume that the Trie stores past searches by the users.
For example if the Trie store {“abc”, “abcd”, “aa”, “abbbaba”} and the User types in “ab” then he must be shown {“abc”, “abcd”, “abbbaba”}.
Prerequisite Trie Search and Insert.

Given a query prefix, we search for all words having this query.  

Search for the given query using the standard Trie search algorithm.
If the query prefix itself is not present, return -1 to indicate the same.
If the query is present and is the end of a word in Trie, print query. This can quickly be checked by seeing if the last matching node has isEndWord flag set. We use this flag in Trie to mark the end of word nodes for purpose of searching.
If the last matching node of the query has no children, return.
Else recursively print all nodes under a subtree of last matching node.
  */


#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char value;
    TrieNode * children[26];
    bool isTerminal;

    TrieNode(char val){
        this->value=val;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
        this->isTerminal=false;
    }
};

//insertion of word
void insertWord(TrieNode* root, string word){
    //base case
    if(word.length()==0){
        root->isTerminal=true;
        return;
    }

    TrieNode* child;
    char ch=word[0];
    int index=ch-'a';

    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        child=new TrieNode(ch);
        root->children[index]=child;
    }

    insertWord(child,word.substr(1));
}

void storeString(TrieNode* root, string &input, vector<string> &ans,string &prefix){
    //base case
    if(root->isTerminal==true){
        ans.push_back(prefix+input);
    }

    for(char ch='a';ch<='z';ch++){
        int index=ch-'a';
        TrieNode* next= root->children[index];
        if(next!=NULL){
            input.push_back(ch);

            storeString(next,input,ans,prefix);

            input.pop_back();
        }
    }
}



void findPrefixSring(TrieNode* root, string input, vector<string> &ans,string &prefix){
    //base case
    if(input.length()==0){
        TrieNode* lastChar=root;
        storeString(lastChar ,input, ans,prefix);
        return;
    }

    char ch=input[0];
    int index=ch-'a';

    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return;
    }

    findPrefixSring(child,input.substr(1),ans,prefix);

}

int main(){
    TrieNode* root=new TrieNode('-');

    insertWord(root,"cater");
    insertWord(root,"care");
    insertWord(root,"com");
    insertWord(root,"lover");
    insertWord(root,"loved");
    insertWord(root,"lov");
    insertWord(root,"bat");
    insertWord(root,"cat");
    insertWord(root,"car");

    cout<<"Insertion done"<<endl;

    string input="c";
    string prefix=input;

    vector<string> ans;
    findPrefixSring(root,input,ans,prefix);

    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}/*
