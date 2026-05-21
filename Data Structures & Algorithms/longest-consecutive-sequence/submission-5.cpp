class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for(int x : s){

            // start of sequence
            if(s.count(x - 1) == 0){

                int current = x;
                int length = 1;

                while(s.count(current + 1)){

                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
// class Solution {
//    public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0){return 0;}
//         set<int> s;
//         for (int i : nums) {
//             s.insert(i);
//         }

//         for (int x : s) {
//             cout << x << " ";
//         }

//         int longest = 1;
//         int current = 1;
//         int idx = 0;
//         int last;
//         for (int i : s) {
//             if (idx == 0) {
//                 last = i;
//                 idx++;
//                 continue;
//             }

//             if (i - last == 1) {
//                 current++;
//                 longest = max(longest, current);
//                 last = i;
//             } else {
//                 current = 1;
//                 last = i;
//             }
//         }
//         return longest;
//     }
// };
