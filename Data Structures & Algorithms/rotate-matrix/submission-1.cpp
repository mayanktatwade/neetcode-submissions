class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = m;
        int temp;
        // for(vector<int>v:matrix){for(int i:v){cout<<i<<" ";}cout<<endl;}cout<<endl;
        if(m%2==0){
        for(int i = 0; i<m/2; i++){
            for(int j = 0; j<m/2; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[m-1-j][i];
                matrix[m-1-j][i] = matrix[m-1-i][m-1-j];
                matrix[m-1-i][m-1-j] = matrix[j][m-1-i];
                matrix[j][m-1-i] = temp;
            }
        }}
        if(m%2==1){
        for(int i = 0; i<m/2; i++){
            for(int j = 0; j<=m/2; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[m-1-j][i];
                matrix[m-1-j][i] = matrix[m-1-i][m-1-j];
                matrix[m-1-i][m-1-j] = matrix[j][m-1-i];
                matrix[j][m-1-i] = temp;
            }
        }}

        // for(vector<int>v:matrix){for(int i:v){cout<<i<<" ";}cout<<endl;}
        return;
    }
};
