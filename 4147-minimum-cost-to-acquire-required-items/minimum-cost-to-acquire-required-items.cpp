class Solution {
    // DP fails as m*n ~~ 10^18 which is very large
    // Therefore only way trying is greedy
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1 + cost2 <= costBoth) return (1LL * cost1 * need1) + (1LL * cost2 * need2);
        if(need1 > need2){
            if(cost1 < costBoth) return (1LL * cost1 * (need1-need2)) + (1LL * costBoth * need2);
            else return (1LL * costBoth * need1);
        }
        else{
            if(cost2 < costBoth) return (1LL * costBoth * need1) + (1LL * cost2 * (need2-need1));
            else return (1LL * costBoth * need2);
        }

        return -1;
    }
};