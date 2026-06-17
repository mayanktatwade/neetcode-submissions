class Solution {
public:
    int n_ ;
 
    void helper(vector<string>&ans,string s,int& total){
        if(s.size()==2*n_){if(total==0){ans.push_back(s);return;}else{return;}}

        if(total>=0 && total<=n_){

            s.push_back('(');
            total++;
            helper(ans,s,total);
            s.pop_back();
            total--;


            s.push_back(')');
            total--;
            helper(ans,s,total);
            s.pop_back();
            total++;
            
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        string s;
        n_ = n; int total = 0;

        vector<string>ans;
        helper(ans,s,total);


        return ans;
    }
};
