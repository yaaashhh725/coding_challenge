//Problem:

/*
Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
Output: 52
Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.
Constraints:
1 <= arr.size() <= 105
-104 <= arr[i] <= 104
*/

//Solution:

class day15 {

    // a: input array
    // n: size of array
    // Function to find maximum circular subarray sum.
    static int subSum(int arr[]){
        int ans = arr[0];
        int curr = arr[0];
        for(int i=1;i<arr.length;i++){
            curr = Math.max(curr+arr[i],arr[i]);
            ans = Math.max(ans,curr);
        }
        return ans;
    }
    public int circularSubarraySum(int arr[]) {

        // Your code here
        int ans1 = subSum(arr);
        int total = 0;
        
        for(int i=0;i<arr.length;i++){
            total += arr[i];
            arr[i]=(-1)*arr[i];
        }
        int ans2 = total + subSum(arr);
        return Math.max(ans1,ans2);
    }
    
}
