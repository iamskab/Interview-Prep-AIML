#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:

        TrieNode *child[26]; // storing a-z chars, a->0, z-> 25
        bool isLeafNode; // last char of the word

        TrieNode(){
            isLeafNode = false;
            for (int i=0; i<26; i++){
                child[i] = NULL; //nullptr
            }
        }
};

void insert(TrieNode *root, string key){
    TrieNode *currNode = root;

    transform(key.begin(), key.end(), key.begin(), ::tolower);

    for (char c:key){
        if (currNode->child[c-'a'] == NULL){ // 'c' -'a' = 2
            TrieNode *newNodeToAdd = new TrieNode(); // a from atul
            currNode->child[c-'a'] = newNodeToAdd; // a , child[0] = new node
        }
        currNode = currNode->child[c-'a'];
    }
    // a->t>u->l

    currNode->isLeafNode = true;
}

bool isWordStored(TrieNode *root, string key){
    TrieNode *currNode = root;

    transform(key.begin(), key.end(), key.begin(), ::tolower); // needed to lower uppercase words

    for(char c: key){
        if(currNode->child[c-'a'] == NULL){ // Kand -> kand
            return false;
        }
        currNode = currNode->child[c-'a'];
    }
    return true;
}

// 100, 234, 546 (100 elements array) --> o(100)
// 
//  child[10] -> 0 to 9

// 22 o(2)

// a-z , 1 to 26

// ATUL -> atul

int main(){
    TrieNode *root = new TrieNode();

    vector<string> strArray{"Atul", "Amal", "Kamal","Dhhamal"};

    for( auto s: strArray){
        insert(root, s);
    }

    cout<< "\n Completed storing all the words in Trie DS \n";

    cout << "\nChecking if word is added: "<<isWordStored(root, "Amal")<<endl;
    cout << "\nChecking if word is added: "<<isWordStored(root, "ka")<<endl;

}