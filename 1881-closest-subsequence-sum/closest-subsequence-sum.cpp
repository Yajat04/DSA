class Solution {
    int lowerBound(vector <long long> &sumB, long long remaining){
        int low = 0;
        int high = sumB.size();

        while(low < high){
            int mid = low + (high - low)/2;
            if(sumB[mid] < remaining) low = mid + 1;
            else high = mid;
        }

        //Lower bound means the index of first element which is >= to target
        //low == 0 means all elements are >= remain
        //low = size-1 means all elements are < remain
        return low;
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n/2;
        int n2 = n - n1;

        //Here 1 << n1 works as n = 40 and n1 = 20, otherwise 1LL << n1 used for larger n1 sizes
        //And hence the data type of low, high, mid, fetch is chosen
        vector <long long> sumA(1LL << n1); 
        for(int mask = 0; mask < (1 << n1); mask++){
            long long sum = 0;
            for(int i = 0; i < n1; i++){
                if(mask & (1 << i)) sum += nums[i];
            }
            sumA[mask] = sum;
        }

        vector <long long> sumB(1 << n2);
        for(int mask = 0; mask < (1 << n2); mask++){
            long long sum = 0;
            for(int i = 0; i < n2; i++){
                if(mask & (1 << i)) sum += nums[n1 + i];
            }
            sumB[mask] = sum;
        }

        sort(sumB.begin(), sumB.end());

        long long mini = LLONG_MAX;
        for(auto sum : sumA){
            long long need = goal - sum;
            int low = lowerBound(sumB, need); //for manual LB
            //int low = lower_bound(begin(sumB), end(sumB), need) - begin(sumB); 
            //lower_bound built in ft returns ptr, therefore "-begin" for index

            if(low < sumB.size()){ //Important check if LB not done manually as, if lb not found(all el < tar) using the builtin LB ft then it returns "end - begin" ie size of sumB
                long long totsum = sum + sumB[low];
                mini = min(mini, abs(goal - totsum));
            }

            if(low > 0){ //Check if low-1 el is more closer if the "need" lies between low and low-1, since low gives the first > tar if tar not found, and since we need absolute diff b/w goal and negative numbers are present therefore we do the comparison for low and low -1 here and not in the LB function
                long long totsum = sum + sumB[low-1];
                mini = min(mini, llabs(goal - totsum));
            }
        }

        return (int)mini;

    }
};