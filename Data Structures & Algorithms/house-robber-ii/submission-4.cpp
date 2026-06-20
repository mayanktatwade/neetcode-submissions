class Solution {
public:
    int helper(vector<int>arr){
        if(arr.size()==1){return arr[0];}
        if(arr.size()==2){return max(arr[0],arr[1]);}

        int max_0 = arr[0]; int max_1 = max(arr[0],arr[1]);
        int max_f;

        for(int i=2; i<arr.size(); i++){
            max_f = max(arr[i]+max_0,max_1);
            int temp = max_1;
            max_1 = max_f;
            max_0 = temp;
        }
        return max_f;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        if(nums.size()==2){return max(nums[0],nums[1]);}
        vector<int> temp(nums.begin(), nums.end() - 1);
        int a = helper(temp);
        vector<int> temp1(nums.begin()+1,nums.end());
        int b = helper(temp1);

        return max(a,b);
    }
};
