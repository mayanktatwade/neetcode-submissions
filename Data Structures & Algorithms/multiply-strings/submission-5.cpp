class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = mul + ans[i + j + 1];

                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }

        string res;

        int i = 0;
        while (i < ans.size() && ans[i] == 0)
            i++;

        while (i < ans.size())
            res += ans[i++] + '0';

        return res;
    }
};
// class Solution {
// public:
//     string num2string(int num){
//         string ans;char c;
//         while(num){
//             c = (char)(num%10+(int)'0');
//             ans = c + ans;
//             num/=10;
//         }
//         return ans;
//     }
//     string addition(string num1, string num2){
//         if(num1.size()==0){return num2;}
//         if(num2.size()==0){return num1;}
//         int carry  = 0 ; int i1 = num1.size()-1; int i2 = num2.size()-1;
//         int a; int b; int total; int temp; string ans; char tempchar;
//         while(i1>=0 && i2>=0){
//             a = (int)num1[i1--]-(int)'0';
//             b = (int)num2[i2--]-(int)'0';

//             // cout<<a<<" "<<b<<endl;
//             total = a+b+carry;
//             carry = total/10;
//             temp = total%10;
//             tempchar = (char) (temp + (int)'0');
            

//             ans = tempchar + ans;
//         }
//         while(i1>=0){
//             a = (int)num1[i1--]-(int)'0';
//             // b = (int)num2[i2--];
//             total = a+carry;
//             carry = total/10;
//             temp = total%10;
//             tempchar = (char) (temp + (int)'0');

//             ans = tempchar + ans;
//         }
//         while(i2>=0){
//             // a = (int)num1[i1--];
//             b = (int)num2[i2--]-(int)'0';
//             total = b+carry;
//             carry = total/10;
//             temp = total%10;
//             tempchar = (char) (temp + (int)'0');

//             ans = tempchar + ans;
//         }
//         if(carry!=0){
//             total = carry;
//             carry = total/10;
//             temp = total%10;
//             tempchar = (char) (temp + (int)'0');

//             ans = tempchar + ans;

//         }

//         return ans;
//     }
// map<char,string>dp;
//     string multiplyhelper(string num1, char num2){
//         if(dp.count(num2)){return dp[num2];}
//         int zeros = 0; string ans; int b = (int)num2-(int)'0'; int a;
//         int prod;

//         for(int i = num1.size()-1; i>=0; i--){
//             a = (int)num1[i]-(int)'0';
//             prod = a*b;
//             string temp(zeros++,'0');
//             temp = num2string(prod)+temp;
//             ans = addition(ans,temp);
//         }
//         dp[num2] = ans;
//         return ans;
//     }
//     string multiply(string num1, string num2) {
//         // cout<<(char) (1 + (int)'0');
//         // string ans = addition("0","0");
//         // for(char c:ans){cout<<c;}
//         // string s(1,'0');
//         // for(char c:s){cout<<c;}
//         // string a = num2string(1233333);
//         // for(char c:a){cout<<c;}
//         // string b = multiply("81",'9');
//         // for(char c:b){cout<<c;}
//         if(num1.size()==0){return num2;}
//         if(num2.size()==0){return num1;}
//         string ans = "0"; int zeros = 0; string prod;
//         for(int i = num2.size()-1; i>=0; i--){
//             prod = multiplyhelper(num1,num2[i]);
//             string temp(zeros++,'0');
//             prod+=temp;
//             ans = addition(ans,prod);
//         }
//         while(ans.size()>1){
//             if(ans[0]!='0'){break;}
//             ans.erase(0,1);
//         }
//         return ans;
//     }
// };
