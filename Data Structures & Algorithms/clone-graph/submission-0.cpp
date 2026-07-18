/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, unordered_map<Node*, Node*>& hash){
        if(!node)
            return NULL;
        
        if(hash.find(node)!=hash.end())
            return hash[node];

        Node* newNode=new Node(node->val);
        hash[node]=newNode;

        for(auto& i:node->neighbors){
            newNode->neighbors.push_back(dfs(i,hash));
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> hash;
        return dfs(node, hash);
        
    }
};
