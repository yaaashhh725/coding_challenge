//problem:

/*
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:

Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.
Input: arr = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.
Input: arr = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
Explanation: The next permutation of the given array is {3, 4, 5, 1, 2}.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
  */

//solution:
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        //find a point after which order of numbers is decreasing lexicographically
        //start from right
        int n = arr.size();
        int point1 = n;
        for(int i=n-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                point1=i;
                break;
            }
            
        }
        if(point1==n){
            //return the sorted list 
            sort(arr.begin(),arr.end());
            return;
        }
        int point2 = n;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>arr[point1]){
                point2=i;
                break;
            }
        }
        
        swap(arr[point1],arr[point2]);
        sort(arr.begin()+point1+1,arr.end());
    }
};
