class Solution {
public:
    void helper(vector<int>&position, vector<int>&ans){
        for(int i=0; i<ans.size(); i++){
            position[ans[i]]=i;
        }
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>dependency(numCourses);
        vector<int>ans(numCourses);
        vector<int>position(numCourses);

        for(vector v:prerequisites){
            dependency[v[0]].push_back(v[1]);
        }
        for(int i = 0; i<numCourses; i++){ans[i]=i;position[i]=i;}


        // int idx = 0;
        // for(vector v:dependency){cout<<idx++<<": ";for(int i:v){cout<<i<<" ";}cout<<endl;}


        for(int i = 0;i<numCourses; i++){
            if(dependency[i].size()==0){
                ans.erase(ans.begin()+position[i]);
                ans.insert(ans.begin(),i);
                helper(position,ans);
            }
        }
        for(int i:ans){cout<<i<<" ";}cout<<endl;
        // cout<<"position:"<<endl;
        // for(int i=0 ;i<position.size(); i++){cout<<"i:"<<i<<" posi:"<<position[i]<<"    ";}cout<<endl;


        for(int i = 0; i<numCourses; i++){
            int maxidx = -1;
            for(int j:dependency[i]){
                maxidx = max(maxidx,position[j]);
            }
            if(maxidx>position[i]){
                ans.insert(ans.begin()+maxidx+1,i);
                ans.erase(ans.begin()+position[i]);
                helper(position,ans);
            }
        }
                for(int i = 0; i<numCourses; i++){
            int maxidx = -1;
            for(int j:dependency[i]){
                maxidx = max(maxidx,position[j]);
            }
            if(maxidx>position[i]){
                ans.insert(ans.begin()+maxidx+1,i);
                ans.erase(ans.begin()+position[i]);
                helper(position,ans);
            }
        }
        for(int i:ans){cout<<i<<" ";}cout<<endl;
        for(int i = 0; i<numCourses; i++){
            int maxidx = -1;
            for(int j:dependency[i]){
                maxidx = max(maxidx,position[j]);
            }
            if(maxidx>position[i]){
                cout<<i;
                return {};
            }
        }
        return ans;
    }
};
