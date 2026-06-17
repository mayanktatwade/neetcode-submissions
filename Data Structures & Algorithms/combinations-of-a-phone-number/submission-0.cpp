class Solution {
public:
    void helper(vector<string> alphabets,vector<string>& ans,int idx,string temp, string digits){
        if(temp.size()==digits.size()){ans.push_back(temp);return;}

        // for(int i=idx; i<digits.size();i++){
            int x = digits[idx] - '2';
            for(char j:alphabets[x]){
                temp.push_back(j);
                helper(alphabets, ans, idx+1,temp, digits);
                temp.pop_back();
            }
        // }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){return {};}
        vector<string> ans;string temp;
        vector<string> alphabets={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(alphabets, ans, 0,temp, digits);
 
        return ans;
    }
};
