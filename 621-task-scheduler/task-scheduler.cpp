class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector <int> freq(26, 0);
        for(int i = 0; i < tasks.size(); i++) freq[tasks[i] - 'A']++;

        priority_queue <int> pq;
        for(int i = 0; i < 26; i++) if(freq[i] != 0) pq.push(freq[i]);

        int intervals = 0;
        while(!pq.empty()){
            vector <int> temp;

            for(int i = 0; i < n+1; i++){
                int fr = pq.top();
                pq.pop();
                fr--;

                temp.push_back(fr);
                if(pq.empty()) break;
            }

            for(int &f : temp) if(f != 0) pq.push(f);

            if(pq.empty()) intervals += temp.size();
            else intervals += n+1;
        }

        return intervals;
    }
};