class Solution {
public:
    int majorityElement(vector<int> &num) {
    for (int i = 1, j = 1; j < num.size(); i++){
        if (num[i] == num[i - 1]){
            while (j < num.size() && num[j] == num[i]){
                j++;
            }
            if (j < num.size()){
                num[i] ^= num[j] ^= num[i] ^= num[j];
            }
        }else{
            j++;
        }
    }
    return num[num.size() - 1];
}
};