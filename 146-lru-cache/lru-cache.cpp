class LRUCache { //Using nested class
    class Node{
        public: 
            Node *next;
            Node *prev;
            int key;
            int val;
            Node(int key, int val){
                this-> key = key;
                this-> val = val;
                next = NULL;
                prev = NULL;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;

    unordered_map <int, Node*> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
        mp.clear();
    }

    void insertAfterHead(Node *node){
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

    int get(int key) {
        if(mp.count(key) == 0) return -1;
        
        deleteNode(mp[key]);
        insertAfterHead(mp[key]);
        return mp[key] -> val;
    }
    
    void put(int key, int value) {
        if(mp.count(key) > 0){
            deleteNode(mp[key]);
            insertAfterHead(mp[key]);
            mp[key] -> val = value;
        }

        else if(cap == 0){
            Node* newNode = new Node(key, value);

            Node* lru = tail -> prev;
            deleteNode(lru);
            mp.erase(lru -> key);
            delete lru;
        
            insertAfterHead(newNode);
            mp[key] = newNode;
        }

        else{
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mp[key] = newNode;
            cap--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */