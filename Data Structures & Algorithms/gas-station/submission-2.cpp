class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int minfuel = INT_MAX; int fuel=0; int idx=0;

        for(int i=0; i<n; i++){
            fuel+=gas[i];
            fuel-=cost[i];

            if(fuel<minfuel){minfuel = fuel; idx = i;}
        }
        if(fuel<0){return -1;}
        if(idx+1>=n){return 0;}
        return idx+1;
    }
};
