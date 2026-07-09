class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> L(n + 1), R(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            int sumL = 0, sumR = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sumL += left[i];
                    sumR += right[i];
                }
            }

            L[cnt].push_back(sumL);
            R[cnt].push_back(sumR);
        }

        for (int i = 0; i <= n; i++)
            sort(R[i].begin(), R[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            for (int s1 : L[k]) {
                int need = n - k;

                auto &vec = R[need];

                int target = total / 2 - s1;

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
    
};