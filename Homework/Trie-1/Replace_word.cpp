/*
n English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "help" is followed by the successor word "ful", we can form a new word "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.

*/


class TrieNode{
    public:
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val){
        this->value=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }

        this->isTerminal=false;
    }
};


class Solution {
    TrieNode* root;

   
    //insertion
void insertWord(TrieNode* root, string word){
    //base case
    if(word.length()==0){
        root->isTerminal=true;
        return;
    }

    char ch=word[0];
    int index=ch-'a';

    TrieNode* child;
    if(root->children[index]!=NULL){
        //present
        child=root->children[index];
    }

    else{
        //absent
        child=new TrieNode(ch);
        root->children[index]=child;
    }

    //recurssion
    insertWord(child,word.substr(1));

}


bool searchWord(TrieNode* root, string word , int &count){
    //base case
    if(root->isTerminal==true){
        return true;
    }
    if(word.length()==0){
        return true;
    }

    char ch=word[0];
    int index=ch-'a';
     count++;

    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return false;
    }

    bool recAns=searchWord(child,word.substr(1),count);

    return recAns;
}


public:

    Solution(){
        root=new TrieNode('#');
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        
        string ans="";

        for(auto str:dictionary){
            insertWord(root,str);
        }

        int start=0;
        int end=0;

        while(end<sentence.length()){
            if(sentence[end]==' ' || end==sentence.length()-1){
                int len=end==sentence.length()-1?sentence.length():end-start;
                string words =sentence.substr(start,len);
                int count=0;
                bool matchIndex=searchWord(root,words,count);
                if(matchIndex==true){
                    ans+=count!=-1? words.substr(0,count): words;
                }
                else{
                    ans+=words;
                }
                
                if(sentence[end]==' '){
                    ans+=" ";
                }

                start=end+1;
            }
            end++;
        }
        return ans;
    }
};
