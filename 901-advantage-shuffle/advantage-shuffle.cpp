class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector <pair <int, int>> num2Sort;
        for(int i = 0; i < nums2.size(); i++){
            num2Sort.push_back({nums2[i], i});
        }

        vector<int> ans(nums1.size());

        sort(num2Sort.begin(), num2Sort.end());
        sort(nums1.begin(), nums1.end());

        int left = 0;
        int right = num2Sort.size() - 1;

        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] > num2Sort[left].first) ans[num2Sort[left++].second] = nums1[i];
            else ans[num2Sort[right--].second] = nums1[i];
        }

        return ans;
    }
};