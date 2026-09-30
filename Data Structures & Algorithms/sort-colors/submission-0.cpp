class Solution {
public:
    
    void sortColors(vector<int>& nums) {
            int l = 0; int n = nums.size(); int r = n-1;

            int i = 0;
            while(i<n){
                if(nums[i]==2){
                    while(i<r && nums[r]==2){r--;}
                    if(i<r){
                    nums[i] = nums[r];
                    nums[r] = 2;
                    }
                    else{i++;}
                    // cout<<1;
                }
                else if(nums[i]==0){
                    while(i>l && nums[l]==0){l++;}
                    if(i>l){
                    nums[i] = nums[l];
                    nums[l] = 0;
                    }
                    else{i++;}
                    // cout<<1;
                }
                else{i++;}
            }
            
            return;
          
            
        }
    
};