class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0; int r = l+k-1; int n = arr.size();
        if(k>=n){return arr;}
        int a = l; int b =r;

        int currmin = INT_MAX;
        int total=0;
        for(int i=0; i<k; i++){
            total += abs(arr[i]-x);
        }
        currmin=total;
        
        l++;r++;
        while(r<n){
            cout<<l<<" "<<r<<" "<<currmin<<endl;
            total += abs(arr[r]-x)-abs(arr[l-1]-x);
            if(currmin>total){a=l;b=r;currmin=total;}
            l++;r++;
        }

        return vector<int>(arr.begin()+a,arr.begin()+b+1);
    }
};