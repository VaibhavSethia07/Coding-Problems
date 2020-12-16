/*
Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

Example 1:

Input:
N = 8
key[] = {the,a,there,answer,any,by,
         bye,their}
search = the
Output: 1
Explanation: the is present in the given
string "the a there answer any by bye
their"
Example 2:

Input:
N = 8
key[] = {the,a,there,answer,any,by,
         bye,their}
search = geeks
Output: 0
Explanation: geeks is not present in the
given string "the a there answer any by
bye their"
Your Task:
Complete insert and search function and return true if key is present in the formed trie else false in the search function. (In case of true, 1 is printed and false, 0 is printed by the driver's code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
N = length of the string

Constraints:
1 <= N <= 104
1 <= |input strings|, |A| <= 100

######################################################################################Solution###################################################################################
*/

// Insert
void insert(struct TrieNode *root, string key) {
    TrieNode* curr = root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(curr->children[index]==NULL)
            curr->children[index] = new TrieNode();
        curr = curr->children[index];
    }
    curr->isLeaf = true;
}

// Search
bool search(struct TrieNode *root, string key) {
    TrieNode* curr = root;
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        if(curr->children[index]==NULL)
            return false;
        curr = curr->children[index];
    }
    return curr->isLeaf;
}
