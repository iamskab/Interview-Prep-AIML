/*
Given a string s and a dictionary of strings wordDict,
return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example-1:
Input: s = "leetcodeleetleet", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


"aaa" "aa" -> dict
"aaaaa" -> new word


Leetcode problem link: https://leetcode.com/problems/word-break/
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *child[26];
    int childCount;
    bool isLeafNode;

    TrieNode()
    {
        childCount = 0;
        isLeafNode = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

void insert(TrieNode *root, string str) //aaa(lf), aa ; root->a->a(lf)->a(lf)
{
    TrieNode *curr = root;
    for (char c : str)
    {
        int idx = c - 'a';
        if (curr->child[idx] == NULL)
        {
            curr->child[idx] = new TrieNode();
            curr->childCount++;
        }
        curr = curr->child[idx];
    }
    curr->isLeafNode = true;
}

bool isWordBreakPossible(TrieNode *root, string &s, int start, vector<int> &dp) // aaaaa , ["aaa", "aa"]
{
    if (start == s.size()) // reached end
        return true;
    if (dp[start] != -1) // already checked
        return dp[start];

    TrieNode *curr = root; // root -> a -> a(lf) -> a(lf)
    for (int i = start; i < s.size(); i++) // s = "aaaaa"
    {
        int idx = s[i] - 'a'; // index of a
        if (curr->child[idx] == NULL)
            break;
        curr = curr->child[idx]; // 
        if (curr->isLeafNode)
        {
            if (isWordBreakPossible(root, s, i + 1, dp))
            {
                return dp[start] = true;
            }
        }
    }
    return dp[start] = false;
}

int main()
{
    vector<string>wordDict{"leet","code"};
    string s = "leetcode";

    TrieNode *root = new TrieNode();

    for (auto word : wordDict)
    {
        insert(root, word);
    }

    vector<int> dp(s.size(), -1); // aaaaa : [-1 -1 -1 -1 -1]
    cout<< isWordBreakPossible(root, s, 0, dp) << "\n";
}