class Solution {
public:
    int binSearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

    int findMin(vector<int> &nums) {
        if(nums.size()==1){return 0;}

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
            if(nums[mid]>nums[l] && nums[mid]<nums[r]){return l;}
        }
        return mid;
    }
    int search(vector<int>& nums, int target) {
        int idx = findMin(nums);
        cout<<idx;

        if(target==nums[idx]){return idx;}
        if(target<nums[idx]){return -1;}
        cout<<endl<<"yayyy";
        if(target>nums[nums.size()-1]){
            cout<<endl<<binSearch(nums,0,idx-1,target);
            return binSearch(nums,0,idx-1,target);}
        return binSearch(nums,idx+1,nums.size()-1,target);
    }
};
