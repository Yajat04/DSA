class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        for(int i = 0; i < nums1.size(); i++){
            bool flag = false;
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]) flag = true;
                if(flag == true && nums2[j] > nums1[i] ){
                    ans.push_back(nums2[j]);
                    flag = false;
                    break;
                }
            }
            if(flag == true) ans.push_back(-1);
        }

        return ans;
    }
};