class ProductOfNumbers {
    vector <int> arr; 
    int size;
    int last;
public:
    ProductOfNumbers() {
        size = 0;
        last = -1;
    }
    
    void add(int num) {
        if(num == 0) last = size;
        if(size == 0 || arr[size-1] == 0){
            arr.push_back(num);
            size++;
            return;
        }
        
        int product = arr[size-1] * num;
        arr.push_back(product);
        size++;
    }
    
    int getProduct(int k) {
        int low = size - k;
        if(low <= last) return 0;
        if(low - 1 == last) return arr[size-1];
        return arr[size-1] / arr[low-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */