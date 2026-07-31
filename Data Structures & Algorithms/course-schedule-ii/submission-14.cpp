class Solution {
public:
set<int>main_set;
bool loop = false;
    void helper(int node,set<int>&mp, vector<vector<int>>&prereq, vector<int>&ans){
        if(main_set.count(node)){return;}
        if(mp.count(node)){loop = true; return;}

        mp.insert(node);

        for(int i:prereq[node]){
            helper(i,mp,prereq,ans);
            if(loop){return;}
        }

        ans.push_back(node); main_set.insert(node);
        return;
        
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>prereq(n); vector<int>ans; 
        for(vector<int>v:prerequisites){
            prereq[v[0]].push_back(v[1]);
        }
        // for(vector<int>v:prereq){for(int i:v){cout<<i<<" ";}cout<<endl;}
        for(int i = 0; i<n; i++){
            set<int>mp;
            helper(i,mp,prereq,ans);
            if(loop){return {};}
        }
        return ans;
    }
};
