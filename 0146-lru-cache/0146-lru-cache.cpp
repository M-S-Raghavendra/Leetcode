class LRUCache {
private:
    class Node {
        public:
            int key;
            int value;
            Node* next;
            Node* prev;
            Node(int key, int value) {
                this->key = key;
                this->value = value;
                next = prev = NULL;
            }
    };
    
    unordered_map<int,Node*> m;
    int n;
    
    Node* head = new Node(0,0);     // dummy node
    Node* tail = new Node(0,0);     // dummy node
    
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        
        prev->next = next;
        next->prev = prev;
        
        m.erase(node->key);
        delete node;
    }
    
    void insertFront(int key, int value) {
        Node* newnode = new Node(key,value);
        newnode->next = head->next;
        head->next->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
        
        m[key] = newnode;
    }
    
    void deleteLRU() {
        Node* node = tail->prev;
        deleteNode(node);
    }
    
public:
    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) != m.end())
        {
            int value = m[key]->value;
            
            deleteNode(m[key]);
            insertFront(key,value);
            
            return value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            deleteNode(m[key]);
            insertFront(key,value);
        }
        else {
            if(m.size() < n)
            {
                insertFront(key,value);
            }
            else {                              // m.size() == n
                deleteLRU();
                insertFront(key,value);
            }
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */