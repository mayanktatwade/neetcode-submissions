class Solution {
public:
bool ans = false; string word_;
    bool check_board(vector<vector<int>> arr, int i, int j){
        for(vector<int> k:arr){
            if(k[0]==i && k[1]==j){return true;}
        }
        return false;
    }
    void helper(vector<vector<char>>& board, int idx, int i, int j, string& temp,vector<vector<int>>& arr){
        if(temp.size()==word_.size()){ans = true; return;}

        for(char t:temp){cout<<t<<" ";}cout<<endl;
        if(i>=0 && i<board.size() && j+1>=0 && j+1<board[0].size()){
            if(board[i][j+1]==word_[idx]){
                if(check_board(arr,i,j+1)==false){
                    temp.push_back(word_[idx]);
                    arr.push_back({i,j+1});
                    helper(board,idx+1,i,j+1,temp,arr);
                    if(ans){return;}
                    arr.pop_back();
                    temp.pop_back();
                }
            }
        }
        if(i+1>=0 && i+1<board.size() && j>=0 && j<board[0].size()){
            if(board[i+1][j]==word_[idx]){
                if(check_board(arr,i+1,j)==false){
                    temp.push_back(word_[idx]);
                    arr.push_back({i+1,j});
                    helper(board,idx+1,i+1,j,temp,arr);
                    if(ans){return;}
                    arr.pop_back();
                    temp.pop_back();
                }
            }
        }
        
        if(i-1>=0 && i-1<board.size() && j>=0 && j<board[0].size()){
            if(board[i-1][j]==word_[idx]){
                if(check_board(arr,i-1,j)==false){
                    temp.push_back(word_[idx]);
                    arr.push_back({i-1,j});
                    helper(board,idx+1,i-1,j,temp,arr);
                    if(ans){return;}
                    arr.pop_back();
                    temp.pop_back();
                }
            }
        }
        if(i>=0 && i<board.size() && j-1>=0 && j-1<board[0].size()){
            if(board[i][j-1]==word_[idx]){
                if(check_board(arr,i,j-1)==false){
                    temp.push_back(word_[idx]);
                    arr.push_back({i,j-1});
                    helper(board,idx+1,i,j-1,temp,arr);
                    if(ans){return;}
                    arr.pop_back();
                    temp.pop_back();
                }
            }
        }
        return;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        string temp; vector<vector<int>> arr; word_ = word;

        temp.push_back(word[0]);

        for(char t:temp){cout<<t<<" 111";}cout<<endl;
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(word.size()==1){return true;}
                    else{
                    arr.push_back({i,j});
                    helper(board,1,i,j,temp,arr);
                    if(ans){return true;}
                    }
                }
                temp = "";temp+=word[0];arr = {};
            }
        }
        return false;
    }
};
