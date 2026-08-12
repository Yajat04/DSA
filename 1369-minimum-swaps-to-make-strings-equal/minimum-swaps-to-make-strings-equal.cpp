class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        int xy = 0; int yx = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] == s2[i]) continue;
            if(s1[i] == 'x') xy++; //if above cond failed hten it means they are diff and if 1 is x then other is automatically y
            else yx++;
        }

        if((xy + yx) % 2 != 0) return -1;
        return xy/2 + yx/2 + (xy % 2) * 2;
    }
};