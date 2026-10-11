class Solution {
    //To find out x being largest in the subarr -> pge and nge
    //To find out x being smallest in the subarr -> pse and nse
    //init ans = 0 -> then largest ones are added and the smallest ones are subtracted
    void make_smallest(vector<int> &pse, vector<int> &nse, vector<int>& arr){
        int n = arr.size();
        stack<int> s1;
        stack<int> s2;

        for(int i = n-1; i >= 0; i--){
            while(!s1.empty() && arr[s1.top()] >= arr[i]) s1.pop();
            nse[i] = s1.empty() ? n : s1.top();
            s1.push(i);
        }

        for(int i = 0; i < n; i++){
            while(!s2.empty() && arr[s2.top()] > arr[i]) s2.pop();
            pse[i] = s2.empty() ? -1 : s2.top();
            s2.push(i);
        }
    }

    void make_largest(vector<int> &pge, vector<int> &nge, vector<int>& arr){
        int n = arr.size();
        stack<int> s1;
        stack<int> s2;

        for(int i = n-1; i >= 0; i--){
            while(!s1.empty() && arr[s1.top()] <= arr[i]) s1.pop();
            nge[i] = s1.empty() ? n : s1.top();
            s1.push(i);
        }

        for(int i = 0; i < n; i++){
            while(!s2.empty() && arr[s2.top()] < arr[i]) s2.pop();
            pge[i] = s2.empty() ? -1 : s2.top();
            s2.push(i);
        }
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n), pge(n), nse(n), pse(n);
        make_smallest(pse, nse, nums);
        make_largest(pge, nge, nums);

        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long largest = 1LL * (i - pge[i]) * (nge[i] - i) * nums[i];
            long long smallest = 1LL * (i - pse[i]) * (nse[i] - i) * nums[i];

            sum += largest;
            sum -= smallest;
        }

        return sum;
    }
};