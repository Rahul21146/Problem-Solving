/*
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
 

Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 108

  */

#define lg 31 
class Solution {
public:
    struct TrieNode{ 
        TrieNode* children[2];  
        int sum_of_indexes; 
        int number_of_indexes;
        TrieNode(){   
            this->children[0] = nullptr; 
            this->children[1] = nullptr; 
            this->sum_of_indexes = 0; 
            this->number_of_indexes = 0; 
        } 
    }; 
    void insert(TrieNode* node,int num,int index){
        for (int bits=lg; bits>=0; bits--){
            int curr_bit = (num >> bits) & 1;
            if (node->children[curr_bit]==nullptr)
                node->children[curr_bit]=new TrieNode(); 
            node = node->children[curr_bit]; 
        }
        node->sum_of_indexes += index;
        node->number_of_indexes++; 
    }
    int query(TrieNode* node,int num,int index){ 
        for (int bits = lg; bits >= 0; bits--){
            int curr_bit = (num >> bits) & 1; 
            if (node->children[curr_bit]== nullptr) 
                return 0;   
            node = node->children[curr_bit]; 
        }
        int sz = node->number_of_indexes; 
        int sum = node->sum_of_indexes; 
        int ans = (sz * index) - (sum);   
        return ans; 
    } 
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int curr_xor = 0;  
        int number_of_triplets = 0;
        TrieNode* root = new TrieNode();  
        for (int i = 0; i < n; i++){  
            int x = arr[i];
            insert(root, curr_xor, i);        
            curr_xor ^= x;
            number_of_triplets+= query(root, curr_xor, i); 
        }  
        return number_of_triplets;     
    }
};
