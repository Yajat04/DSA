class StockSpanner {
    stack <pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int idx;
        int span;
        if(st.empty()){
            st.push({price, 0});
            return 1;
        }
        else idx = st.top().second + 1;

        while(!st.empty() && st.top().first <= price) st.pop();
        if(st.empty()) span = idx+1;
        else span = idx - st.top().second;
        st.push({price, idx});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */