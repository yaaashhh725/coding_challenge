//Problem :

/*
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 
Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10
*/

//Solution:

class Solution {
    // Function to find maximum product subarray
    int maxProduct(int[] arr) {
        // code here
        int max_pro = arr[0];
        int min_pro = arr[0];
        int ans = arr[0];
        for(int i=1;i<arr.length;i++){
            if(arr[i]<0){
                int temp = max_pro;
                max_pro = min_pro;
                min_pro = temp;
            }
            max_pro = Math.max(max_pro*arr[i],arr[i]);
            min_pro = Math.min(min_pro*arr[i],arr[i]);
            ans = Math.maxE(ans,max_pro);
        }
        return (ans);
    }
}
