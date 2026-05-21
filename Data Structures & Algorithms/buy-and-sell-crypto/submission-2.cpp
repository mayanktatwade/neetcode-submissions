class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int,int>>temp;

        for(int i = 0 ; i<prices.size() ; i++){
            temp.push_back({prices[i],i});
        }
        int max = 0;

        sort(temp.begin(),temp.end());

        int l = 0; int r = prices.size()-1;

        while(l<r){
            if(max<(temp[r].first - temp[l].first) && temp[r].second > temp[l].second){
                max = temp[r].first - temp[l].first;
            }
            else{ if(l==r-1){
                r--;l=0;
            }
            else{l++;}}
            
        }return max;
    }   
};
