class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int count = 1;
        int up = 0; 
        int down = 0; 
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                if(down != 0){
                    up = 0;
                    down = 0;
                }
                up++;
                count += up + 1;
            }
            else if(ratings[i] < ratings[i-1]){
                down++;
                if(up < down) count += down + 1;
                else count += down;
            }
            else{
                count++;
                // we have liberty to maximize or minimize when we encounter the equal elements
                // for later maximizing
                up = 0;
                down = 0;
            }
        }

        return count;
    }
};