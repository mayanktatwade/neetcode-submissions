class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int ans = 0; int rescued = 0;
        int l=0; int r = n -1;

        while(rescued<n){
            if(people[r]==limit){ans++;rescued++;r--;}
            else if(people[r]+people[l]>limit){ans++;rescued++;r--;}
            else{ans++;rescued+=2;r--;l++;}
        }

        return ans;

    }
};