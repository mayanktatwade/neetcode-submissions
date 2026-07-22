class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0; int t = 0; int r = matrix[0].size()-1; int b = matrix.size()-1;
        vector<int>ans;

        int x = 0; int y = 0;
        bool s1 = true; bool s2 = false; bool s3 = false; bool s4 = false;
        while(l<=r && t<=b){
            ans.push_back(matrix[x][y]);

            

            if(y==r && s1 == true){s2 = true; s1 = false; t++; x++; continue;}
            if(x==b && s2 == true){s3 = true; s2 = false; r--; y--; continue;}
            if(y==l && s3 == true){s4 = true; s3 = false; b--; x--; continue;}
            if(x==t && s4 == true){s1 = true; s4 = false; l++; y++; continue;}

            if(s1){y++;}
            if(s2){x++;}
            if(s3){y--;}
            if(s4){x--;}
        }

        return ans;
        
    }
};
