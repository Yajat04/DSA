class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return arr;
        
        priority_queue <pair< int, int>, vector<pair< int, int>>, 
            greater<pair< int, int>>> pq;
        for(int i = 0; i < n; i++) pq.push({arr[i], i});

        int rank = 1;
        int last_pop = pq.top().first;
        arr[pq.top().second] = rank;
        pq.pop();

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            if(last_pop == top.first) arr[top.second] = rank;
            else arr[top.second] = ++rank;
            last_pop = top.first;
        }
        return arr;
    }
};