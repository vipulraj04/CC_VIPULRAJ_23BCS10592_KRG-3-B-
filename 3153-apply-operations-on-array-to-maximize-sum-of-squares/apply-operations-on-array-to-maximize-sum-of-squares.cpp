class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9+7;
        vector<int> count(32,0);

        for(int num : nums){
            for(int i=0;i<32;i++){
                if(num & (1<<i)){
                    count[i]++;
                }
            }
        }

        long long ans = 0;

        for(int i=0;i<k;i++){
            long long x = 0;

            for(int bit=0;bit<32;bit++){
                if(count[bit] > 0){
                    x |= (1LL<<bit);
                    count[bit]--;
                }
            }

            ans = (ans + (x*x)%MOD) % MOD;
        }

        return ans;
    }
};