#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n = value.size();
        long long MOD = 1e9 + 7;
        auto get_count = [&](long long X)-> long long {
            if (X == 0) X=1;
            long long total_selections =0;
            for (int i =0; i<n; ++i){
                if(value[i] >= X){
                    if(decay[i] == 0){
                        total_selections += m;
                    }else{
                        long long max_picks = value[i]/decay[i]+1;
                        long long picks_above_X =(value[i]-X)/decay[i]+1;
                        total_selections += min(max_picks, picks_above_X);
                    }
                    if(total_selections >m) total_selections = m+1;
                }
            }
            return total_selections;
        };
         long long low =1 ,high = 2e9, threshold = 2e9;
        while (low <= high){
            long long mid = low +(high-low)/2;
            if(get_count(mid) <= m){
                threshold = mid;
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        long long total_value =0;
        long long selections_used =0;
        for(int i =0;  i<n; ++i){
            if(value[i] >= threshold){
                long long picks = 0;
                if (decay[i] == 0){
                    picks = m;
                }else{
                    long long max_picks = value[i]/decay[i]+1;
                    long long picks_above_threshold = (value[i]- threshold)/ decay[i] +1;
                    picks = min (max_picks, picks_above_threshold);
                }
                selections_used += picks;
                long long first_term = value[i];
                long long last_term = value[i]-(picks-1)*decay[i];
                long long sum_pool =(picks *(first_term + last_term))/2;
                total_value =(total_value + sum_pool)%MOD;
            }
        }
        if(selections_used > m){
            long long excess = selections_used - m;
            total_value =(total_value -( excess* threshold)% MOD + MOD)%MOD;
        }else if(selections_used < m && threshold>1){
            long long remaining = m- selections_used;
            long long available_next = get_count(threshold -1)- get_count (threshold);
            long long take = min(remaining,available_next);
            total_value =(total_value + (take * (threshold - 1))% MOD)%MOD;
        }
         return total_value;   
    }
};