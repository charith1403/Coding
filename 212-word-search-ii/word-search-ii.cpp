class Node {
public:
    Node* links[26] = {}; // only 26 lowercase letters
    bool flag = false;
    string word = "";

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    Node* getNode(char ch) { return links[ch - 'a']; }
};

class Solution {
public:
    Node* root = new Node();

    void insert(const string& s) {
        Node* node = root;
        for (char c : s) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->getNode(c);
        }
        node->word = s;
        node->flag = true;
    }

    void solve(vector<vector<char>>& board, Node* node, int i, int j,
               vector<string>& ans) {
        char ch = board[i][j];
        if (ch == '#' || !node->containsKey(ch))
            return;

        node = node->getNode(ch);
        if (node->flag) {
            ans.push_back(node->word);
            node->flag = false; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int dir = 0; dir < 4; dir++) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];

            if (ni >= 0 && nj >= 0 && ni < board.size() &&
                nj < board[0].size()) {
                solve(board, node, ni, nj, ans);
            }
        }

        board[i][j] = ch; // restore character
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> ans;

        for (const string& word : words) {
            insert(word);
        }

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                solve(board, root, i, j, ans);
            }
        }

        return ans;
    }
};
