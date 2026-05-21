class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<pair<int,int>>nums2;
        for(int i =0; i<nums.size();i++){
            nums2.push_back({nums[i],i});
        }
        sort(nums2.begin(),nums2.end());

        int l =0; int r = nums.size()-1;

        while(l<=r){
            int mid = (l+r)/2;
            if(nums2[mid].first==target){return nums2[mid].second; }
            else if(nums2[mid].first<target){
                l = mid+1;
            }
            else{
                r =mid-1;
            }
        }
        return -1;
    }
};
