// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         map<char,int>mp1;
//         for(auto s:s1){
//             mp1[s]++;
//         }
        
//         map<char,int>mp2;
//         for(int i=0; i<s2.size()-s1.size()+1;i++){
//             string temp = s2.substr(i,s1.size());
//             for(auto s:temp){
//                 mp2[s]++;
//             }
//             if(mp1==mp2){return true;}
//             mp2.clear();
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size()>s2.size()){return false;}

        vector<int>hash1(26,0);
        vector<int>hash2(26,0);

        int left = 0; int right = 0;
        for(int i = 0; i<s1.size();i++){
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
            right++;
        }
        right--;

        while(right<s2.size()){
            if(hash1 == hash2){
                return true;
            }
            right++;
            if(right != s2.size()){
                hash2[s2[right]-'a']++;
            }
            hash2[s2[left++]-'a']--;
             

        }
        return false;}
};
