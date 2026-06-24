class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){return 0;}
        int ans; map<int,int>mp; int temp1; int temp2;
        for(int i = 0; i<s.size();i++){
            temp1 = 1;temp2=0;
            if(i+1<s.size() && s[i+1]=='0'){
                if(!(s[i]=='1'||s[i]=='2')){return 0;}
                if(i-1>=0){temp1 = mp[i-1];}
                // else{temp = 0;}

                ans = temp1;
                mp[i] = ans;
                cout<<mp[i]<<"i...   "<<i<<endl;
                i++;mp[i] = ans;cout<<mp[i]<<"i...   "<<i<<endl;
            }
            else{
                if(s[i]=='0'){return 0;}
                if(mp.count(i-1)&&mp.count(i-2)){
                    if(i-1>=0 && s[i-1]!='0' && stoi(s.substr(i-1, 2)) <=26 && stoi(s.substr(i-1, 2))>=1){
                        temp2 = mp[i-2];
                    }else{temp2 = 0;}
                    temp1 = mp[i-1];
                    ans = temp1+temp2;
                    mp[i] = ans;
                }
                else{
                    temp1 = 1;
                    if(i-1>=0){cout<<stoi(s.substr(i-1, 2))<<endl;}
                    if(i-1>=0 && s[i-1]!='0' && stoi(s.substr(i-1, 2)) <=26 && stoi(s.substr(i-1, 2))>=1){
                        temp2 = 1; 
                    }else{temp2 = 0;}
                    ans = temp1+temp2;
                    mp[i] = ans;
                }
            }
            cout<<i<<" " <<mp[i]<<endl;
        } 
        return mp[s.size()-1];  
    }
};
