class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l =0; int r = heights.size()-1;

        while(l<r){
            int temp = (r-l)*min(heights[r],heights[l]);
            cout<<temp<<" r:"<<heights[r]<<" l:"<<heights[l]<<endl;
            res = max(res,temp);

            if(heights[l]<heights[r]){l++;}
            else {r--;}
        }
        return res;
    }
};
