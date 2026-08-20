class Solution {
    void dfs(string word, int level, vector<string> &vec, vector<vector<string>> &ans, string beginWord, unordered_map<string, int> &mp){
        if(word == beginWord){
            reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            reverse(vec.begin(), vec.end());
            return;
        }

        for(int i = 0; i < word.size(); i++){
            string temp = word;
            for(char ch = 'a'; ch <= 'z'; ch++){
                temp[i] = ch;
                if(mp.find(temp) != mp.end() && mp[temp] == level-1){
                    vec.push_back(temp);
                    dfs(temp, level - 1, vec, ans, beginWord, mp);
                    vec.pop_back();
                }
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue <pair<string, int>> q;
        unordered_set <string> st;
        unordered_map<string, int> mp; //To map word with level
        for(auto word : wordList) st.insert(word);

        q.push({beginWord, 0});
        st.erase(beginWord); //If beginWord also happens to be present in thee wordlist
        while(!q.empty()){
            auto [word, d] = q.front();
            mp[word] = d;
            q.pop();

            if(word == endWord) break;
            for(int i = 0; i < word.size(); i++){
                string temp = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;
                    if(st.find(temp) != st.end()){
                        q.push({temp, d + 1});
                        st.erase(temp);
                    }
                }
            }
        }

        vector<vector<string>> ans;
        vector <string> vec;
        vec.push_back(endWord);
        dfs(endWord, mp[endWord], vec, ans, beginWord, mp);
        return ans;
    }
};