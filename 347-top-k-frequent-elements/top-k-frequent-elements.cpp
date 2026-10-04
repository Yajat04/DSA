class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int &num: nums) freq[num]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto &[num, fr] : freq) pq.push({fr, num});

        vector<int> ans;
        for(int i = 0; i < k; i++){
            auto [fr, num] = pq.top();
            pq.pop();

            ans.push_back(num);
        }

        return ans;
    }
};