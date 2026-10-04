class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(groupSize > n) return false;

        unordered_map <int, int> freq;
        for(int i = 0; i < n; i++) freq[hand[i]]++;

        sort(hand.begin(), hand.end());
        for(int &num : hand){
            if(freq[num] == 0) continue;
            else{
                for(int i = 0; i < groupSize; i++){
                    if(freq[num+i] == 0) return false;
                    freq[num+i]--;
                }
            }
        }

        return true;
    }
};