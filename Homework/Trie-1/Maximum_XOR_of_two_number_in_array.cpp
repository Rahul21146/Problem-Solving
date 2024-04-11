/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1

  */

class TrieNode{
    public:
    int bit;
    TrieNode* binary[2];

    TrieNode(int bit){
        this->bit=bit;
        for(int i=0;i<2;i++){
            this->binary[i]=nullptr;
        }
    }
};

class Solution {
    TrieNode* root;

    //insertion
    void insertNumber(TrieNode* root,int num){
        
        TrieNode* node = root;

        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(node->binary[bit] == nullptr){ 
                node->binary[bit] = new TrieNode(bit);
            }

            node = node->binary[bit]; 
        }
    }

    //xor operation
    int xorOperation(TrieNode* root, int num){
        TrieNode* node=root;
        int max=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)& 1;

            int flip=1-bit;
            if(node->binary[flip]!=NULL){
                max=max|(1<<i);
                node=node->binary[flip];
            }
            else{
                node=node->binary[bit];
            }
        }
        return max;
    }

public:

    Solution(){
        root=new TrieNode(0);
    }

    int findMaximumXOR(vector<int>& nums) {
        int maxi=0;
        for(auto it: nums){
            insertNumber(root,it);
        }

        for(int i=1;i<nums.size();i++){
            int ans =xorOperation(root,nums[i]);
            maxi=max(maxi,ans);
        }

        return maxi;
    }
};
