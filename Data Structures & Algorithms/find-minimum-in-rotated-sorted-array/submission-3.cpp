class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==1){return nums[0];}

        int l = 0; int r = nums.size()-1; int mid = l+ (r-l)/2;;

        while(l<r){
            

            if(nums[mid]>=nums[l] && nums[mid]>nums[r]){
                l = mid+1;
                mid = l+ (r-l)/2;
                continue;
            }
            if(nums[mid]<=nums[l] && nums[mid]<nums[r]){
                r = mid;
                mid = l+ (r-l)/2;
                continue;
            }
            if(nums[mid]>nums[l] && nums[mid]<nums[r]){return nums[l];}
        }
        return nums[mid];
    }
};
