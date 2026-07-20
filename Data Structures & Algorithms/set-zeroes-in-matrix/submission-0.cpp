class Solution {
public:
    void helper1(vector<vector<int>>& matrix,int row){
        for(int j = 0; j<matrix[0].size(); j++){
            matrix[row][j] = 0;
        }
        return;
    }
    void helper2(vector<vector<int>>& matrix,int col){
        for(int j = 0; j<matrix.size(); j++){
            matrix[j][col] = 0;
        }
        return;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>columns(100);vector<int>rows(100); 
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    rows[i]=1;columns[j]=1;
                    // helper1(matrix,i);
                    // helper2(matrix,j);
                }
            }
        }

        for(int i = 0; i<matrix.size(); i++){
            if(rows[i]==1){helper1(matrix,i);}
        }
        for(int j = 0; j<matrix[0].size(); j++){
            if(columns[j]==1){
                helper2(matrix,j);
            }
        }

        return;
    }
};
