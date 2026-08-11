/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    void helper(TreeNode* root, string& s){
        if(!root){
            s+="N,";
            return;
        }
        s+=to_string(root->val)+",";
        helper(root->left, s);
        helper(root->right,s);
    }

    void stov(string data, vector<string>& v){
        int l=0;
        for(int i=0;i<data.length();++i){
            if(data[i]==','){
                v.push_back(data.substr(l,i-l));
                l=i+1;
            }
        }
    }

    TreeNode* helperd(vector<string> data, int& i){
        if(data[i]=="N"){
            i++;
            return NULL;
        }
        TreeNode* node=new TreeNode(stoi(data[i++]));
        node->left=helperd(data,i);
        node->right=helperd(data,i);
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        helper(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        stov(data, v);
        int i=0;
        return helperd(v,i);
    }
};
