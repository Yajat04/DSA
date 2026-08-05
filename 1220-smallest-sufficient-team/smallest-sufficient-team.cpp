class Solution {
    int target_mask;
    vector <int> result;
    unordered_map<string, int> dp;
    void solve(int idx, int m, vector <int> &people_skills, vector <int> temp, int mask){
        if(mask == target_mask){ 
        //If already completed taking all reqskills then no need to go further, temp for this would be updated and will get dtored in result
        //if(idx == m) not required here as it is the valid path or accepted path
            if(result.size() == 0 || (result.size() > temp.size())) result = temp;
            return;
        }

        if(idx == m) return; //if path isnt valid and it hits the end of vector

        //prune using results
        if(result.size() != 0 && result.size() <= temp.size()) return;

        //Prune using dp
        string key = to_string(idx) + "_" + to_string(mask);
        if(dp.find(key) != dp.end()){
            if(dp[key] <= temp.size()) return;
        }

        dp[key] = temp.size();

        //not_take
        solve(idx + 1, m, people_skills, temp, mask);

        //take
        if(mask | people_skills[idx] != mask){ //means p[idx] isnt empty and have some skills o/w it wont make any sense to take it, also if it do have skills and it wont update the mask as it already covers the same skills earlier, there isnt any need to take it
            temp.push_back(idx);
            solve(idx + 1, m, people_skills, temp, (mask | people_skills[idx]));
            temp.pop_back();
        }
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int m = people.size();

        //Tranform re_skills in bits
        unordered_map <string, int> skills;
        for(int i = 0; i < n; i++){
            skills[req_skills[i]] = i;
        }

        vector <int> people_skills;
        for(const auto &p : people){
            int p_mask = 0;
            for(const auto &s : p){
                p_mask = p_mask | (1 << skills[s]);
            }
            people_skills.push_back(p_mask);
        }

        vector <int> temp;
        target_mask = pow(2, n) - 1;
        solve(0, m, people_skills, temp, 0);

        return result;
    }
};