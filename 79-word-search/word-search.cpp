class Solution {
public:

    void dfs(int index, int row, int col, vector<vector<char>>& board, string word,bool &ans)
    {
        if(row <0 || row >= board.size() || col < 0 || col >= board[0].size() || word[index] != board[row][col])
        {
            return;
        }

        if(index == word.size()-1)
        {
            ans = true;
            return;
        }

        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};

        char temp = board[row][col];
        board[row][col] = '#';

        for(int i=0;i<4;i++)
        {
            int nrow = row + dy[i];
            int ncol = col + dx[i];

            dfs(index+1,nrow,ncol,board,word,ans);
        }
        board[row][col] = temp;

    }

    bool exist(vector<vector<char>>& board, string word) {

        bool ans = false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    dfs(0,i,j,board,word,ans);
                    if(ans)
                    {
                        return ans;
                    }
                }
            }
        }
        
        return ans;
    }
};