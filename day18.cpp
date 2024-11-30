//Problem :

/*
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
Constraints:
1 ≤s1.size(), s2.size()≤ 106
*/

//Solution:

class Solution {
  public:
    string trimzeros(string&s){
        int i=0;
        while(s[i]=='0') i++;
        return s.substr(i,s.length());
    }
    string addBinary(string& s1, string& s2) {
        // your code here
        string ans = "";
        s1 = trimzeros(s1);
        s2 = trimzeros(s2);
        int i = s1.length()-1;
        int j = s2.length()-1;
        
        char carry = '0';
        while(i>=0 and j>=0){
            int temp = int(s1[i])+int(s2[j])+int(carry)-3*int('0');
            if(temp==3){
                carry = '1';
                ans += '1';
            }
            else if(temp==2){
                carry = '1';
                ans += '0';
            }
            else if(temp==1){
                carry = '0';
                ans += '1';
            }
            else{
                carry = '0';
                ans += '0';
            }
            i--;
            j--;
            // if(temp == "111"){
            //     ans += '1';
            //     carry = '1';
            // }
            // else if(temp=="101" || temp=="110" || temp=="011"){
            //     carry='1';
            //     ans += '0';
            // }
            // else if(temp=="100" || temp=="010" || temp=="001"){
            //     carry = '0';
            //     ans += '1';
            // }
            // else{
            //     carry = '0';
            //     ans += '0';
            // }
        }
        while(i>=0){
            int temp = int(s1[i])+int(carry)-2*int('0');
            if(temp==2){
                carry = '1';
                ans += '0';
                
            }
            else if(temp==1){
                carry = '0';
                ans += '1';
                
            }
            else{
                carry = '0';
                ans += '0';
            }
            i--;
            // if(temp=="11"){
            //     carry = '1';
            //     ans += '0';
            // }
            // else if(temp=="10"||temp=="01"){
            //     carry = '0';
            //     ans += '1';
            // }
            // else{
            //     carry = '0';
            //     ans += '0';
            // }
        }
        while(j>=0){
            int temp = int(s2[j])+int(carry)-2*int('0');
            if(temp==2){
                carry = '1';
                ans += '0';
            }
            else if(temp==1){
                carry = '0';
                ans += '1';
            }
            else{
                carry = '0';
                ans += '0';
            }
            j--;
            // if(temp=="11"){
            //     carry = '1';
            //     ans += '0';
            // }
            // else if(temp=="10"||temp=="01"){
            //     carry = '0';
            //     ans += '1';
            // }
            // else{
            //     carry = '0';
            //     ans += '0';
                
            // }
        }
        if(carry=='1'){
            ans += '1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
