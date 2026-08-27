class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n<=2){return 0;}

        int l1 = 0;
        int l2 = n-1;
        int water = 0;
        
        while(l1+1<n){
            if(height[l1+1]>=height[l1]){l1++;continue;}
            break;
        }
        while(l2-1>=0){
            if(height[l2-1]>=height[l2]){l2--;continue;}
            break;
        }
        
        if(l1==l2){return 0;}
        cout<<l1<<l2;
        int temp; int temp2; int h;
        
        while(l1<l2){
            temp = l1+1;
            while(temp<l2){
                if(height[temp]>=height[l1]){break;}
                temp++;
            } 
            if(temp == l2){break;}
            h = min(height[l1],height[temp]);
            temp2 = temp-1;
            while(temp2>l1){water+= h - height[temp2--];}
            l1 = temp;
        }
        while(l1<l2){
            temp = l2-1;
            while(temp>l1){
                if(height[temp]>=height[l2]){break;}
                temp--;
            } 
            // if(temp == l1){break;}
            h = min(height[l2],height[temp]);
            temp2 = temp+1;
            while(temp2<l2){water+= h - height[temp2++];}
            l2 = temp;
        }

        return water;
    }
};
