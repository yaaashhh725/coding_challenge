//Problem:

/*
You are given two strings s1 and s2 of the equal length, both containing only lowercase English alphabets. You can assign shift values (non negative integers) to each lowercase English letter before performing any operation. You need to perform the following operation on each character of s1 exactly once:
If the assigned integer to the character is x, then the character must be transformed into the character which is x positions ahead of it, or x positions behind it in the English alphabet in cyclic order. For example, if the assigned integer to the character 'a' is 1, then it can be transformed into 'b' or 'z'.
Return true if it is possible to transform s1 into s2, otherwise return false.
Examples:
Input: s1 = "geeksforgeeks", s2 = "geeksforgeeks"
Output: true
Explanation: Assign shift value of 0 to all the letters in s1. So, s1 will be transformed into s2.
Input: s1= "abab", s2 = "fdfz"
Output: true
Explanation: Assign shift value of 5 to 'a' and 2 to 'b'. Possible transformations 'a' -> ('f', 'v') and 'b' -> ('d', 'z').
Input: s1= "abab", s2 = "adfz"
Output: false
Explanation: It is impossible to transform s1 into s2 as 'a' can't be transformed into both 'a' and 'f'.
Constraints:
1 ≤ |s1| = |s2| ≤ 106
*/

//Solution:
class Solution{
  public:
    bool canTransform(string &s1, string &s2) {
        // code here
        vector<int>values(26,-1);
        for(int i=0;i<s1.length();i++){
            
            if(values[s1[i]-'a']==-1){
                //not assigned any shift value yet
                values[s1[i]-'a']=abs(s1[i]-s2[i]);
            }
            else if(values[s1[i]-'a']!=abs(s1[i]-s2[i]) and 26-values[s1[i]-'a']!=abs(s1[i]-s2[i]))
                return false;
        }
        
        return true;
    }
};
