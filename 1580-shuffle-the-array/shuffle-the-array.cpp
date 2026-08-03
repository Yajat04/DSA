class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // vector <int> x(n);
        // vector <int> y(n);
        // vector <int> ans;
        // for(int i = 0; i < n; i++){
        //     x[i] = nums[i];
        //     y[i] = nums[n + i];
        // }

        // int ptrx = 0;
        // int ptry = 0;

        // int i = 0;
        // while(ptrx != n && ptry != n){
        //     if(i % 2 == 0) ans.push_back(x[ptrx++]);
        //     else ans.push_back(y[ptry++]);
        //     i++;
        // }

        //Optimal
        vector <int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[n + i]);
        }

        return ans;
    }
};