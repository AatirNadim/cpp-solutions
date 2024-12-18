/*
    problem link --> https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
    class CustomNode {
        public:
        int key;
        int val;
        CustomNode* prev, *next;
        CustomNode(int key, int val) {
            this->key = key;
            this->val = val;
            prev = nullptr, next = nullptr;
        }
    };
    
    
    void addNode(CustomNode* temp) {
        head->prev->next = temp;
        temp->prev = head->prev;
        head->prev = temp;
        temp->next = head;
    }
    
    void removeNode(CustomNode* temp) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = nullptr;
        temp->prev = nullptr;
    }
    
public:
    unordered_map<int, CustomNode*> mp;
    CustomNode* head = nullptr, *tail = nullptr;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head = new CustomNode(-1, -1);
        tail = new CustomNode(-1, -1);
        head->prev = tail;
        tail->next = head;
    }
    
    int get(int key) {
        CustomNode* temp = mp[key];
        if(!temp) return -1;
        removeNode(temp);
        addNode(temp);
        return head->prev->val;
    }
    
    void put(int key, int value) {
        CustomNode* temp = mp[key];
        if(!temp) {
            temp = new CustomNode(key, value);
            addNode(temp);
            cap--;
            mp[key] = temp;
        }
        else {
            removeNode(temp);
            addNode(temp);
            head->prev->val = value;
        }
        if(cap < 0) {
            mp[tail->next->key] = nullptr;
            removeNode(tail->next);
            cap++;
        }
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */