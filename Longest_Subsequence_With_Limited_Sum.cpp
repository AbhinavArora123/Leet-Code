class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    vector<int> x;
    sort(nums.begin(), nums.end());
    for(int j=0 ; j < queries.size() ; j++){
        int tempsize=0;
        int cursum=0;
        for(int k=0 ; k < nums.size() ; k++){
            cursum+=nums[k];
            if (cursum>queries[j]){
                break;
            }
            else if(cursum==queries[j]){
                tempsize++;
                break;
            }
            tempsize++;
        }
        x.push_back(tempsize);
    }
    return x;
    }
};