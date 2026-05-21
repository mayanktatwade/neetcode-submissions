class Solution {
public:
    bool check_square(vector<vector<char>> square){
        unordered_set<char>s;
        for(vector<char> i:square){
            for(char j:i){
                if(s.count(j)){return false;}
                if(j!='.'){
                s.insert(j);}
            }
        }
        return true;
    }
    bool check_line(vector<char>line){
        unordered_set<char>s;
        for(char j:line){
            if(s.count(j)){return false;}
            if(j!='.'){
            s.insert(j);}
        }
        return true;
    }    

    bool isValidSudoku(vector<vector<char>>& board) {
        for(vector<char> i:board ){
            if(check_line(i)!=true){return false;}
        }

        for(int i=0; i<9; i=i+3){

            for(int j=0; j<9; j=j+3){
                vector<vector<char>>sq;

                sq.push_back({board[i][j],board[i][j+1],board[i][j+2]});
                sq.push_back({board[i+1][j],board[i+1][j+1],board[i+1][j+2]});
                sq.push_back({board[i+2][j],board[i+2][j+1],board[i+2][j+2]});
                
                if(check_square(sq)!=true){return false;}
            }
            
        }

        for(int j=0;j<9;j++){
            vector<char>col;
            for(int i = 0; i<9 ; i++){
                col.push_back(board[i][j]);
            }
            if(check_line(col)!=true){return false;}
        }
        return true;
    }
};