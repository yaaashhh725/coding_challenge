//problem:
/*
Allocate minimum pages (binary search)
*/

//solution

class Solution {
  public:
    

    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size() < k) return -1;
        int high = 0;
        int low = 0;
        for(auto it:arr){
            if(it > low){
                low = it;
            }
            high += it;
        }
        
        int res=INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            int students = 0;
            int pages = 0;
            for(int i=0;i<arr.size();i++){
                if(pages+arr[i]>mid){
                    students++;
                    pages=arr[i];
                }
                else{
                    pages += arr[i];
                }
            }
            if(students < k){
                high = mid-1;
                res = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};
