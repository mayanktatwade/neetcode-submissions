class Solution {
public:
    vector<int>helper(vector<int>nums){
        int n = nums.size();
        if(n==1){return nums;}
        if(n==2){if(nums[0]>nums[1]){return{nums[1],nums[0]};}else{return{nums[0],nums[1]};}}

        vector<int>a = helper(vector<int>(nums.begin(),nums.begin()+n/2));
        vector<int>b = helper(vector<int>(nums.begin()+n/2,nums.end()));

        int l=0; int r=0; vector<int>ans;
        while(l<n/2 && r<n-n/2){
            if(a[l]<b[r]){ans.push_back(a[l++]);}
            else{ans.push_back(b[r++]);}
        } 
        while(l<n/2){
            ans.push_back(a[l++]);
        } 
        while(r<n-n/2){
            ans.push_back(b[r++]);
        } 

        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        // vector<int>v = vector<int>(nums.begin(),nums.begin()+2);

        vector<int>ans = helper(nums);
        
        return ans;
        

    }
};