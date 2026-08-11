class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k,int v):key(k),val(v),prev(NULL),next(NULL){}
};

class LRUCache {
public:
    int cap=0;
    Node* left;
    Node* right;
    unordered_map<int,Node*> hash;

    void insert(Node* node){
        node->next=right;
        node->prev=right->prev;
        right->prev=node;
        node->prev->next=node;
    }

    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    LRUCache(int capacity) {
        cap=capacity;
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end()){
            Node* temp=hash[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            remove(hash[key]);
        }
        Node* node=new Node(key,value);
        hash[key]=node;
        insert(node);

        if(hash.size()>cap){
            Node* lru=left->next;
            hash.erase(lru->key);
            remove(lru);
            delete lru;
        }
    }
};
