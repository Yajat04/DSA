class Solution {
    //Positive number
    //Two ends
    //Maximize sum
    //All these point towards greedy + two ptr

    //Greedy fails due to non uniformity
    //Can we apply dp?
    //No, as if you wanna make states it would be on basis of left, right, k
    //3D dp with size = n * n * k but TC would be 10^5 * 10^5 >> 10^8 as the three states are dependent (like either of the ptr moves)
    //But still TC is hitting TLE

    //two ptr is used
    //Hence try sliding window, put window for t in between the two ends
    //the rest n - t = k will be the chosen cards on ends, acc to question 

public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int t = n - k;
        int left = 0;
        int right = t - 1;

        int totSum = 0;
        for(int i = 0; i < n; i++) totSum += cardPoints[i];

        //Now minimize t window sum to maximize k slits sum
        int sum = 0;
        for(int i = 0; i < t; i++) sum += cardPoints[i];
        int mini = sum; //not intmin as we start with the fixed window
        while(right < n-1){
            sum -= cardPoints[left++];
            sum += cardPoints[++right];

            mini = min(mini, sum);
        }

        return totSum - mini;
    }
};