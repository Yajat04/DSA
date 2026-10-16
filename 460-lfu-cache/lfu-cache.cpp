class LFUCache {
    class Node{
        public:  //If dont want to define in public then use struct (offers implicit public)
            Node *next;
            Node *prev;
            int key;
            int val;
            int freq;

            Node(int key, int val, int freq){
                this-> key = key;
                this-> val = val;
                this-> freq = freq;

                next = NULL;
                prev = NULL;
            }
    };
    
    int cap;

    map <int, pair<Node*, Node*>> freq;
    unordered_map <int, Node*> mp;
public:
    LFUCache(int capacity) {
        cap = capacity;
        mp.clear();
    }

    void insertAfterHead(Node* head, Node *node){
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
        node -> prev = head;
    }
    
    void deleteNode(Node *node){
        node -> next -> prev = node -> prev;
        node -> prev -> next = node -> next;

        //delete node; may be required for replacing positiion therefore cang delete the node, could use the same node
    }

    void make_DoublyLL(Node* node){
        Node* head = new Node(-1, -1, -1);
        Node* tail = new Node(-1, -1, -1);
        head -> next = tail;
        tail -> prev = head;

        freq[node -> freq] = {head, tail};
        insertAfterHead(head, node);
    }
    
    int get(int key) {
        if(mp.count(key) == 0) return -1;  

        Node* temp = mp[key];
        deleteNode(temp);

        int fr = temp -> freq;
        auto head = freq[fr].first;
        auto tail = freq[fr].second;
        if(head -> next == tail){
            delete head;
            delete tail;
            freq.erase(fr);
        }

        temp -> freq = fr+1;
        if(freq.count(fr+1) == 0) make_DoublyLL(temp);
        else insertAfterHead(freq[fr+1].first, temp);
    
        return mp[key] -> val;
    }
    
    void put(int key, int value) {
        if(mp.count(key) == 0){
            if(cap == 0){
                auto [fr, nodes] = *freq.begin();
                auto [head, tail] = nodes;
            
                auto node = tail -> prev;
                deleteNode(node);
                mp.erase(node -> key);
                delete node;

                if(head -> next == tail){
                    delete head;
                    delete tail;
                    freq.erase(fr);
                }

                cap++;
            }

            Node* newNode = new Node(key, value, 1);
            if(freq.count(1) == 0) make_DoublyLL(newNode);
            else insertAfterHead(freq[1].first, newNode);
            mp[key] = newNode;
            cap--;
        }

        else{
            Node* temp = mp[key];
            int fr = temp -> freq;
            deleteNode(temp);

            auto head = freq[fr].first;
            auto tail = freq[fr].second;
            if(head -> next == tail){
                delete head;
                delete tail;
                freq.erase(fr);
            }

            temp -> freq = fr+1;
            temp -> val = value;
            if(freq.count(fr+1) == 0) make_DoublyLL(temp);
            else insertAfterHead(freq[fr+1].first, temp);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */