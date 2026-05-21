class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        set<int> s;
        for (int i : nums) {
            s.insert(i);
        }

        for (int x : s) {
            cout << x << " ";
        }

        int longest = 1;
        int current = 1;
        int idx = 0;
        int last;
        for (int i : s) {
            if (idx == 0) {
                last = i;
                idx++;
                continue;
            }

            if (i - last == 1) {
                current++;
                longest = max(longest, current);
                last = i;
            } else {
                current = 1;
                last = i;
            }
        }
        return longest;
    }
};
