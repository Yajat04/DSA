class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue <pair<long long, int>, 
                        vector<pair<long long, int>>, greater<pair<long long, int>>> pq; //{Finish, id} 
        // Finish will matter(is significant) till the server gets poped out (becomes available)

        set <int> st; // stores the increasing order of ids available
        for(int i = 0; i < k; i++) st.insert(i);

        vector <int> cnt(k, 0);
        for(int i = 0; i < arrival.size(); i++){
            while(!pq.empty() && arrival[i] >= pq.top().first){ 
                // runs atmost n times in total, as it wont pop unless the top is smaller than arrival
                // one server once pops in one iterationn of arrival will be used in the other arrival instance
                // the servers can be used at most n times (no. of requests)
                st.insert(pq.top().second);
                pq.pop();
            }

            if(st.empty()) continue;

            int id = i%k;
            auto find = st.lower_bound(id);

            auto it = st.begin();
            if(find != st.end()) it = find;

            pq.push({arrival[i] + load[i], *it});
            cnt[*it]++;
            st.erase(it);
        }

        int maxi = INT_MIN;
        vector <int> ans;
        for(int i = 0; i < k; i++){
            if(cnt[i] > maxi){
                ans.clear();
                ans.push_back(i);
                maxi = cnt[i];
            }
            else if(cnt[i] == maxi) ans.push_back(i);
        }

        return ans;


    }
};