class StockSpanner {
    vector <int> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int pge = -1;
        int n = prices.size();
        for(int i = 0; i < n; i++) if(prices[i] > price) pge = i;
        prices.push_back(price);

        return n - pge;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */