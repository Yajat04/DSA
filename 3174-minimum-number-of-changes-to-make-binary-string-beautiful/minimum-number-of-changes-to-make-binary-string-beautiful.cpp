class Solution {
    // partitions -> dp , but dp would de extra work
    // since there isnt any restriction on number of partitions we do not care about it
    // any bigger partition can be solved efficiently by breaking into the min possible partition i.e length 2, as even is mandatory
    // ex: 100010 -> 1s = 2, 0s = 4 therefore change 1s to 0s hence minChanges = 2, 
    // but if we do , 10 00 10, for each pair we can easily cal -> 1 + 0 + 1 = 2 (same result) {just like recursion solving subproblems}
public:
    int minChanges(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i += 2){
            if(s[i] != s[i+1]) ans++;
        }

        return ans;
    }
};