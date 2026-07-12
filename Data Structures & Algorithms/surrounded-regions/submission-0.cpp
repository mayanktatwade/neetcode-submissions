class Solution {
public:
int m; int n; vector<vector<int>>y_map;

    void helper2(vector<vector<char>>& board,int x,int y){
        if(x<0 || y<0 ||x>=m || y>=n){return;}
        if(board[x][y]=='X' || board[x][y]=='Y'){return;}
        
        board[x][y]='X';
        helper2(board,x+1,y);
        helper2(board,x-1,y);
        helper2(board,x,y+1);
        helper2(board,x,y-1);

        return;
    }
    void helper1(vector<vector<char>>& board,int x,int y){
        if(x<0 || y<0 ||x>=m || y>=n){return;}
        if(board[x][y]=='X' || board[x][y]=='Y'){return;}
        
        board[x][y]='Y';y_map.push_back({x,y});
        helper1(board,x+1,y);
        helper1(board,x-1,y);
        helper1(board,x,y+1);
        helper1(board,x,y-1);

        return;
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>mp1;
        vector<vector<int>>mp2;

        m = board.size(); n = board[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='O'){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    mp1.push_back({i,j});
                    continue;
                }
                mp2.push_back({i,j});
                }
            }
        }

        for(vector<int>i:mp1){
            helper1(board,i[0],i[1]);
        }
        for(vector<int>i:mp2){
            helper2(board,i[0],i[1]);
        }
        for(vector<int>i:y_map){
            board[i[0]][i[1]] = 'O';
        }
        
    }
};
