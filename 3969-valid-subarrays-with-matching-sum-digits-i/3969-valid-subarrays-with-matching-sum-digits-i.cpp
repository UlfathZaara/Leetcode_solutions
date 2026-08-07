class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int valid_count = 0;
        for (int i =0; i<n; ++i){
            long long current_sum =0;
            for(int j =i; j<n; ++j){
                current_sum += nums[j];
                if(current_sum % 10 == x){
                    long long temp = current_sum;
                    while(temp >= 10){
                        temp /= 10;
                    }
                    if (temp == x){
                        valid_count++;
                    }
                }
            }
        }
        return valid_count;
    }
};