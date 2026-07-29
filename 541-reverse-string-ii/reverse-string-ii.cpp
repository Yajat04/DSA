class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        //Jumping 2k steps, such that bracket of i to i + 2k is not touched after k el reversal
        for(int i = 0; i < n; i += 2*k){
            int left = i;
            int right = min(i + k - 1, n -1);
            //only thing matter is that reversal is from i to i + k
            //satisfies if num of element b/w i and i + 2k are >=k
            //if they are less then k it means we reach the end of array

            //reverse first k el in curr bracket
            while(left < right){
                swap(s[left], s[right]);
                left++;
                right--;
            }

        }

        return s;
    }
};