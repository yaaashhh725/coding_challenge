//problem: 

/*
You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

Note: The answer should be returned in an increasing format.

Examples:

Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: no candidate occur more than n/3 times.
Constraint:
1 <= arr.size() <= 106
-109 <= arr[i] <= 109
*/

//solution:

class Solution {
  public:
    // Function to find the majority elements in the array
    
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        if(arr.size() < 3){
            return arr;
        }
        int can1=INT_MAX;
        int can2=INT_MAX;
        int v1=0;
        int v2=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==can1){
                v1++;
            }
            else if(arr[i]==can2){
                v2++;
            }
            else if(v1==0){
                can1=arr[i];
                v1=1;
            }
            else if(v2==0){
                can2=arr[i];
                v2=1;
            }
            else{
                v1--;
                v2--;
            }
             
        }
        int n = arr.size();
        v1=0;
        v2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==can1) v1++;
            else if(arr[i]==can2) v2++;
        }
        if(v1 > n/3 and v2 > n/3){
            if(can1 > can2){
                return {can2,can1};   
            }
            else return {can1,can2};
        }
        else if(v1 > n/3) return {can1};
        else if(v2 > n/3) return {can2};
        else return {};
        
    }
};
