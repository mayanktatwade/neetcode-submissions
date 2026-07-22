class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (left <= right && top <= bottom) {

            // Left -> Right
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int l = 0; int t = 0; int r = matrix[0].size()-1; int b = matrix.size()-1;
//         vector<int>ans;

//         int x = 0; int y = 0;
//         bool s1 = true; bool s2 = false; bool s3 = false; bool s4 = false;
//         while(l<=r && t<=b){
//             ans.push_back(matrix[x][y]);

            

//             if(y==r && s1 == true){s2 = true; s1 = false; t++; x++; continue;}
//             if(x==b && s2 == true){s3 = true; s2 = false; r--; y--; continue;}
//             if(y==l && s3 == true){s4 = true; s3 = false; b--; x--; continue;}
//             if(x==t && s4 == true){s1 = true; s4 = false; l++; y++; continue;}

//             if(s1){y++;}
//             if(s2){x++;}
//             if(s3){y--;}
//             if(s4){x--;}
//         }

//         return ans;
        
//     }
// };
