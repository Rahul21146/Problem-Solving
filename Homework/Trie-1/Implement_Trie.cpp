/*


 trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

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


class Trie {
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

bool searchWord(TrieNode* root, string word){
    //base case
    if(word.length()==0){
        if(root->isTerminal==true){
            return true;
        }
        else{
            return false;
        }
    }

    char ch=word[0];
    int index=ch-'a';

    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return false;
    }

    bool recAns=searchWord(child,word.substr(1));

    return recAns;
}

bool startWithPrefix(TrieNode* root, string word){
    if(word.length()==0){
        return true;
    }

    ListNode* child;
    char ch=word[0];
    int index=ch-'a';

    if(root->children[index]==NULL){
        return false;
    }

    bool recAns=startWithPrefix(root->children[index],word.substr(1));
    return recAns;
}


public:
    Trie() {
        root=new TrieNode('#');
    }
    
    void insert(string word) {
        insertWord(root,word);
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
    
    bool startsWith(string prefix) {
        return startWithPrefix(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
