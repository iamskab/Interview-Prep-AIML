/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Leetcode problem link: https://leetcode.com/problems/longest-common-prefix/
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:

        TrieNode *child[26];
        int childCount;
        bool isLeafNode;

        TrieNode(){
            isLeafNode = false;
            childCount = 0;
            for (int i=0; i<26; i++){
                child[i] = NULL; 
            }
        }
};

void insert(TrieNode *root, string key){
    TrieNode *currNode = root;

    transform(key.begin(), key.end(), key.begin(), ::tolower);

    for (char c:key){
        int idx = c-'a';
        if (currNode->child[idx] == NULL){

            TrieNode *newNodeToAdd = new TrieNode();
            currNode->child[idx] = newNodeToAdd;
            currNode->childCount++;
        }
        currNode = currNode->child[idx];
    }

    currNode->isLeafNode = true;
}

string findLongestCommonPrefix(TrieNode *root){
    string out = "";
    TrieNode *curr = root;

    while(curr && curr->childCount==1 && !curr->isLeafNode){
        for(int i=0; i<26; i++){
            if(curr->child[i]){
                out += char(i+'a');
                curr = curr->child[i];
                break;
            }
        }
    }

    return out;
}

int main(){
    vector<string> strArray{"Chandrika", "Chandu", "Chandamama"}; //{"flower","flow","flight"}; //{"Chandrika", "Chandu", "Chandamama"};
    TrieNode *root = new TrieNode();

    for( auto s:strArray){
        insert(root, s);
    }

    cout << "\n Longest Common Prefix: "<<findLongestCommonPrefix(root)<<"\n";
}