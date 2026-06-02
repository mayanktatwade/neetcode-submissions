// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());

//         for(int i = 1; i<nums.size() ; i++){
//             if(nums[i]==nums[i-1]){return nums[i];}
//             cout<<nums[i]<<" ";
//         }
//         return 0 ;
//     }
// };
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find cycle entrance
        int ptr1 = nums[0];
        int ptr2 = slow;

        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
};