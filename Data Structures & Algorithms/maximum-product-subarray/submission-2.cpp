class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0]; int maxProd = nums[0]; int ans = nums[0];

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<0) swap(minProd,maxProd);
            minProd = min(nums[i],nums[i]*minProd);
            maxProd = max(nums[i],nums[i]*maxProd);

            ans = max(ans,maxProd);
        }
        return ans;
    }
};


// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//        int negidx = -1;int  negProd = 1;  int ans = INT_MIN; int prod=1; bool zero = false; 

//        for(int i = 0; i<nums.size(); i++){
//             if(nums[i]==0){zero = true; prod=1; negidx = -1; negProd = 1;continue;}
//             prod *= nums[i];
//             if(nums[i]<0 && negidx == -1 ){negidx = i; negProd = prod;}

//             ans = max(ans,prod);
//             if(nums[i]>0 && prod<0){ans = max(ans,prod/negProd);}
//        }

//        if (ans<0 && zero){return 0;}
//        return ans;
//     }
// };
