class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto &p:strs){
            // int size = p.size();
            s.append(to_string(p.size())+"#");
            s.append(p);
        }
        return s;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;
        string length; string temp;int len;
        while(i<s.size()){
            if(isdigit(s[i])){
                length.push_back(s[i]);
                i++;
            }
            else{
                i++;
                len = stoi(length);
                temp=s.substr(i,len);
                result.push_back(temp);
                i += len;
                length.clear();
;
            }
        }
        return result;
    }
};
