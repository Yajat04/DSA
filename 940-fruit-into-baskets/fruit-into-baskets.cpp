class Solution {
    //Talking about left right
    //Continous pickup, ie pick up fruits which is present in either of basket , therefore substring
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int lastB1 = 0;
        int lastB2 = 0;
        int left = 0;

        int last_typeB1 = fruits[0];
        int last_typeB2 = -1;


        int maxLen = 0;
        for(int right = 0; right < n; right++){
            if(fruits[right] == last_typeB1){
                lastB1 = right;
            }

            else if(last_typeB2 == -1 || fruits[right] == last_typeB2){
                lastB2 = right;
                last_typeB2 = fruits[right];
            }

            else if(lastB1 < lastB2){
                left = lastB1 + 1;
                lastB1 = right;
                last_typeB1 = fruits[right];
            }

            else{
                left = lastB2 + 1;
                lastB2 = right;
                last_typeB2 = fruits[right];
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};