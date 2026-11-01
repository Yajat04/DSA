class Solution {
    //We dont know the ceiling till which vaue all will equate at , and we reach there by iincreasing n-1 el on each step
    //Therefore we use reverse approach as we know the floor(minVal) and  at each step we gonna decrease "one" element at each step (inc n-1 by 1-> dec 1 by 1) 
    //This will eventually lead to making each element reach min hence directly cal the diff and add to totmoves
public:
    int minMoves(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int moves = 0;

        for (int num : nums) {
            moves += (num - minVal);
        }

        return moves;
    }
};