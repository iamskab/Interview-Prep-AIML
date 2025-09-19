
/*
Print all valid words that are possible using Characters of Array

Input : Dict - {"go","bat","me","eat","goal", 
                                "boy", "run"} 
        arr[] = {'e','o','b', 'a','m','g', 'l'} 
Output : go, me, goal. 
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:

        TrieNode *child[26]; // 0->a, 25->z
        bool isLeafNode;

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
        if (currNode->child[c-'a'] == NULL){
            TrieNode *newNodeToAdd = new TrieNode();
            currNode->child[c-'a'] = newNodeToAdd;
        }
        currNode = currNode->child[c-'a'];
    }

    currNode->isLeafNode = true;
}

string searchNextChar(TrieNode *root, int hashMap[], string out){

    if (root->isLeafNode){
        cout<< out << endl;
    }

    for (int i=0; i<26; i++){
        if (hashMap[i] && (root->child[i] != NULL)){

            out += char(char(i)+char('a'));

            searchNextChar(root->child[i], hashMap, out);
        }
    }
}

void printValidWords(TrieNode *root, vector<char> charArray){
    
    int hashMap[26] = {0};
    for (int i=0; i<charArray.size(); i++){
        hashMap[charArray[i]-'a'] = 1;
    }

    TrieNode *curr = root; 

    string out = "";

    for (int i=0; i<26; i++){
        if (hashMap[i] && (curr->child[i] != NULL)){ // g

            out += char(char(i)+char('a')); // g

            searchNextChar(curr->child[i], hashMap, out);

            out = "";

        }
    }

}


int main(){

    TrieNode *root = new TrieNode;

    vector<string> strArr{"go","bat","me","eat","goal","boy", "run"};
    for (string s: strArr){
        insert(root, s);
    }
    
    vector<char> charArray{'e','o','b', 'a','m','g', 'l'};
    
    printValidWords(root, charArray);


}
