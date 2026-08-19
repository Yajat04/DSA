class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue <pair<string, int>> q;
        unordered_set <string> st;
        for(auto word : wordList) st.insert(word);

        q.push({beginWord, 1});
        st.insert(beginWord);
        while(!q.empty()){
            auto [word, d] = q.front();
            q.pop();

            if(word == endWord) return d;
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

        return 0;
    }
};