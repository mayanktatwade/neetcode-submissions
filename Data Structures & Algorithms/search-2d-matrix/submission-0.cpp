class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col  = matrix[0].size();

        vector<int>temp;

        for(int i= 0; i<rows; i++){
            for(int j=0; j<col; j++){
                temp.push_back(matrix[i][j]);
            }
        }

        int l =0; int r = (rows*col)-1;

        while(l<=r){
            int mid = (r+l)/2;

            if(temp[mid]==target) return true;
            else if(temp[mid]<target) l = mid+1;
            else r =mid-1;
        }
        return false;
        
    }
};
