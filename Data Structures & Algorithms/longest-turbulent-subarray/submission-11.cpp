class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        char last = 'e'; char curr = 'e';
        int ans = 1; int n = arr.size(); int len = 0;

        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){curr='i';}
            else if(arr[i]<arr[i-1]){curr='d';}
            else{curr = 'e';}

            if(curr=='e'){len=0;last = curr; continue;}
            if(curr==last){len=1; last = curr;continue;}
            len++;
            ans = max(ans, len+1);
            last = curr;
        }
        return ans;

    }
};