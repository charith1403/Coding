class Node
{
    public:
    Node* links[26];
    bool flag = false;
    string word = "";

    bool containsKey(char ch)
    {
        if(links[ch - 'a'] == nullptr)
        {
            return false;
        }
        return true;
    }

    void putChar(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }
    Node* getChar(char ch)
    {
        return links[ch - 'a'];
    }

};
class Solution {
public:
    
    void insert(string word, Node* node)
    {
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->putChar(word[i],new Node());
            }
            node = node->getChar(word[i]);
        }
        node->flag = true;
        node->word = word;
    }

    void helper(int row , int col , Node* node, vector<string> &ans, vector<vector<char>>& board)
{
    // Check boundary and if the cell is visited
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '#' 
    || !node->containsKey(board[row][col]))
        return;

    char ch = board[row][col];
    node = node->getChar(ch);

    // Found a word!
    if(node->flag)
    {
        ans.push_back(node->word);
        node->flag = false; // Avoid duplicates
    }

    board[row][col] = '#'; // Mark as visited

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    for(int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        helper(nrow, ncol, node, ans, board);
    }

    board[row][col] = ch; // Unmark
}


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Node* root = new Node();
        vector<string> ans;

        for(auto word : words)
        {
            insert(word,root);
        }


        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(root->containsKey(board[i][j]))
                {
                    helper(i,j,root,ans,board);
                }
                
            }
        }
        
        return ans;
        
    }
};