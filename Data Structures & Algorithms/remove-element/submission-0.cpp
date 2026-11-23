class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0; int n = nums.size(); int idx = 0;
        for(int i=0; i<n; i++){if(nums[i]==val){idx=i; l=i;break;}}

        int e = 0;
        for(int i=idx; i<n; i++){
            if(nums[i]!=val){
                swap(nums[i],nums[l++]);
            }
            else{e++;}
        }
        return n-e;
    }
};