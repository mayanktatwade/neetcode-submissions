class Solution {
public:
    void helper(vector<string>& ans,string s,int open,int close,int n){
        if(s.size()==2*n){ans.push_back(s);return;}

        if(open<n){
            s+='(';
            helper(ans,s,open+1,close,n);
            s.pop_back();
        }
        if(close<open){
            s+=')';
            helper(ans,s,open,close+1,n);
            s.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        helper(ans,s,0,0,n);
        return ans;   
    }
};


// class Solution {
// public:
//     int n_ ;
 
//     void helper(vector<string>&ans,string s,int& total){
//         if(s.size()==2*n_){if(total==0){ans.push_back(s);return;}else{return;}}

//         if(total>=0 && total<=n_){

//             s.push_back('(');
//             total++;
//             helper(ans,s,total);
//             s.pop_back();
//             total--;


//             s.push_back(')');
//             total--;
//             helper(ans,s,total);
//             s.pop_back();
//             total++;
            
//         }

//         return;
//     }
//     vector<string> generateParenthesis(int n) {
//         string s;
//         n_ = n; int total = 0;

//         vector<string>ans;
//         helper(ans,s,total);


//         return ans;
//     }
// };
