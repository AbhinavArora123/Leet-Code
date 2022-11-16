class Solution {
public:
    int firstOccurence(vector<int>& nums, int target){
        int start = 0;
        int res = -1;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target==nums[mid]){
                res = mid;
                end = mid-1;
            }
            else if(target<nums[mid])
                end = mid-1;
            else 
                start = mid+1;
        }
        return res;
    }
    int lastOccurence(vector<int>& nums, int target){
        int start = 0;
        int res = -1;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target==nums[mid]){
                res = mid;
                start = mid+1;
            }
            else if(target<nums[mid])
                end = mid-1;
            else 
                start = mid+1;
        }
        return res;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int first = firstOccurence(nums, target);
        int last = lastOccurence(nums, target);
        if(first!=-1 && last!=-1){
        for(int i=first; i<=last; i++)
            result.push_back(i);}
        return result;
    }
};