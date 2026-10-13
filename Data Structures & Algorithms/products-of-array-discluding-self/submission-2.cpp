class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
int n =nums.size();
vector<int>a(n);
vector<int>b(n);
int j=n-1;
int ap=1;int bp=1;
for(int i=0;i<n;i++){
ap*=nums[i];
a[i]=ap;
bp*=nums[j-i];
b[j-i]=bp;
}
vector<int>ans(n);
ans[0]=b[1];ans[n-1]=a[n-2];
for(int i=1;i<n-1;i++){
ans[i]=a[i-1]*b[i+1];
}
return ans;

    }
};
