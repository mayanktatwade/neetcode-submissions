class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>gettrust(n+1);vector<int>givetrust(n+1);
        int m = trust.size();

        for(int i = 0; i<m ; i++){
            vector<int>t = trust[i];
            gettrust[t[1]]++;
            givetrust[t[0]]++;
        }

        int ans = -1; bool found = false;
        for(int i=1; i<n+1; i++){
            if(gettrust[i]==n-1){
                if(found){return -1;}
                if(givetrust[i]!=0){return -1;}
                ans = i; found = true;
            }
        }
        return ans;
    }
};