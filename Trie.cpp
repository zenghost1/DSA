class TrieNode{
    bool isWord;
    unordered_map<char,TrieNode*> children;
    TrieNode() : isWord(false), children(unordered_map<char,TrieNode*>()) {}
};

// logic only
TrieNode* (vector<string>& words){
    TrieNode* root = new TrieNode();
    for(string word : words){
        TrieNode* curr = root;
        for(char c: word){
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }

    return root;
}

/* 
NOTE: This is only for Word Break problem on leetcode.
The Trie template ends above
*/

vector<bool> dp(s.length());
for(int i=0; i<s.length(); i++){
    if(i-1 == -1 || dp[i-1]){
        TrieNode* curr = root;
        for(int j=i; j<s.length(); j++){
            char c = s[j];
            if(curr->children.find(c) == curr->children.end()) break;
            curr = curr->children[c];
            if(curr->isWord) dp[j] = true;
        }
    }
}

return dp[s.length()-1];