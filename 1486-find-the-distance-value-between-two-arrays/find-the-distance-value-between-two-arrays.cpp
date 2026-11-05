class Solution {
    // |a-b| <= d => -d <= a-b <= d, which further translates to
    // a-d <= b <= a + d 
    // left part used to find lowerbound (b) and right part to validadte that b ( the smallest possible b is found using lb therefore if it is not valid then others def wont be)
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int count = 0;
        for(int i = 0; i < arr1.size(); i++){
            auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i] - d);

            if(it != arr2.end() && *it <= arr1[i] + d) continue;

            count++;
        }

        return count;
    }
};