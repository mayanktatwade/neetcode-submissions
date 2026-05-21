class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){ return 0;}
        map<int,int>mp;

        for(int i = 0; i<nums.size();i++){
            mp[nums[i]]++;
        }

        int longest = 0; int ele ;int temp = 0;

        int idx = 0;
        for (auto &p : mp) {
            if (idx > 0) {
                if(p.first-ele==1){
                    temp++;
                    if(temp>longest){longest = temp;}
                }
                else{
                     temp = 0;}
                
                cout<<ele<<endl;
                ele = p.first;
                
                cout<<longest<<" "<<temp<<endl;

            }
            
            else{
                idx++;
                ele = p.first;}
        }
        return longest+1;
    }
};
