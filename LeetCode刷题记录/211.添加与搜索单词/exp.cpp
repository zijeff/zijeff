struct TrieNode {
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        child = vector<TrieNode *>(26, nullptr);
        isEnd = false;
    }
};
class WordDictionary {
  public:
    TrieNode *root;
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) {
        TrieNode *node = root;
        for (auto c : word) {
            if (node->child[c - 'a'] == nullptr)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->isEnd = true;
    }
    bool dfs(string word, int depth, TrieNode *node) {
        if (depth == word.size())
            return node->isEnd;
        char ch = word[depth];
        if (ch >= 'a' && ch <= 'z') {
            TrieNode *child = node->child[ch - 'a'];
            if (child != nullptr)
                return dfs(word, depth + 1, child);
        } else if (ch == '.') {
            for (int i = 0; i < node->child.size(); i++) {
                TrieNode *child = node->child[i];
                if (child != nullptr && dfs(word, depth + 1, child))
                    return true;
            }
        }
        return false;
    }
    bool search(string word) { return dfs(word, 0, root); }
};
