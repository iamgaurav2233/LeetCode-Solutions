class Solution {
public:
struct Node {
    Node *links[26];
    bool flag = false;
    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
};
int minExtraChar(string s, vector<string>& d) {
Trie t;
for (int i = 0;i < d.size(); i++) {
   t.insert(d[i]);
}
int n = s.size();
vector<vector<int>> dp(n + 2, vector<int> (n + 2, 1e9));
for (int sze = 1;sze <= n; sze++) {
   for (int i = 1;i <= n - sze + 1; i++) {
      int j = i + sze - 1;
      if (t.search(s.substr(i - 1, j - i + 1)))
         dp[i][j] = 0;
      else dp[i][j] = j - i + 1;
      for (int k = i; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }
   }
}
return dp[1][n];
}
};
