class Solution {
public:
int n;vector<vector<string>> ans;
    void helper1(vector<string>&board, int x, int y){
        for(int i = 0; i<n; i++){
            if(i!=x){board[i][y] = '.';}
            if(i!=y){board[x][i] = '.';}
        }
        int tempx = x-1; int tempy = y-1;
        while(tempx>=0 && tempy >=0){board[tempx--][tempy--] = '.';}
        tempx = x+1; tempy = y-1;
        while(tempx<n && tempy >=0){board[tempx++][tempy--] = '.';}
        tempx = x+1; tempy = y+1;
        while(tempx<n && tempy<n){board[tempx++][tempy++] = '.';}
        tempx = x-1; tempy = y+1;
        while(tempx>=0 && tempy <n){board[tempx--][tempy++]= '.';}
        return;
    }

    void helper(vector<string>&board, int x, int y, int queens){
        // cout<<"x:"<<x<<"  y:"<<y<<"  queens:"<<queens<<endl;
        if(queens == n){return; }
        if(x<0 || x>=n || y<0 || y>=n){return;}
        if(board[x][y]=='.'){return;}
        

        board[x][y] = 'Q';
        helper1(board,x,y);
        queens++;
        int oldqueens = queens;
        vector<string> oldboard = board;


        for(int i = 0; i<n; i++){
            queens = oldqueens; board = oldboard;
            helper(board, x+1, i, queens);
            if(queens == n){ans.push_back(board);return;}
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n_) {
        n = n_;
        
        

        for(int i = 0; i<n; i++){
            int queens = 0;
            vector<string> board(n,string(n,'0'));
            // for(string s:board){for(char i:s){cout<<i<<" ";}cout<<endl;}
            helper(board, 0, i, queens);

            // if(queens == n){cout<<"LOOOOOOOOOl   ";ans.push_back(board);}
        }

        // n=5;
        // vector<string> board(5,"00000");
        // helper1(board,2,2);
        // for(string s:board){for(char i:s){cout<<i<<" ";}cout<<endl;}
        return ans;
    }
};
