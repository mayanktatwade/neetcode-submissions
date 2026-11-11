class Solution {
public:
int ans = 0;
int n;
    void helper(int x, int y, int&queens, vector<int>&rows, vector<int>&cols,
                vector<int>&dia1,vector<int>&dia2){
        if(x>=n){return;}
        if(rows[x] || cols[y] || dia1[x-y+n-1] || dia2[x+y]){return;}

        rows[x]=1; cols[y] = 1; dia1[x-y+n-1] = 1; dia2[x+y] = 1;
        queens++;
        if(queens==n){ans++; queens--;
        rows[x]=0; cols[y] = 0; dia1[x-y+n-1] = 0; dia2[x+y] = 0;
        return;}

        for(int j=0; j<n; j++){helper(x+1,j,queens,rows,cols,dia1,dia2);}

        rows[x]=0; cols[y] = 0; dia1[x-y+n-1] = 0; dia2[x+y] = 0;
        queens--;

        return;   
    }
    int totalNQueens(int n_) {
        n=n_;

        vector<int>rows(n); vector<int>cols(n);
        vector<int>dia1(2*n-1);vector<int>dia2(2*n-1);
        int queens = 0;
        for(int i=0;i<n;i++){
            helper(0,i,queens,rows,cols,dia1,dia2);
        }
        return ans;

    }
};