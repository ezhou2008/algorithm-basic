/*Binary Tree Serialization

Description
Design an algorithm and write code to serialize and deserialize a binary tree.
Writing the tree to a file is called 'serialization' and reading back from the
file to reconstruct the exact same binary tree is 'deserialization'.

There is no limit of how you deserialize or serialize a binary tree,
you only need to make sure you can serialize a binary tree to a string and deserialize this string to the original structure.

Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

     3
    / \
   9  20
     /  \
    15   7
Our data serialization use bfs traversal.
This is just for when you got wrong answer and want to debug the input.

You can use other method to do serializaiton and deserialization.*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution_BFS {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here

        if (root == NULL) return "{}";

        vector<TreeNode*> node_arr;
        node_arr.push_back(root);

// 将二叉树的个节点按照从上到下、从左到有的存储在queue中
        for (int i=0; i<node_arr.size();i++) {
            TreeNode* pCurNode = node_arr[i];
            if (pCurNode) {
                node_arr.push_back(pCurNode->left);
                node_arr.push_back(pCurNode->right);
            }
        }

// 去除叶子节点的左右孩子，这个孩子是空值
        while (node_arr.size() >0 && node_arr[node_arr.size()-1] == NULL) {
            node_arr.pop_back();
        }
// 换成字符串
        stringstream ss;
        ss << "{";
        for(int i=0; i<node_arr.size();i++){
            if (node_arr[i] == NULL) {
                ss << "#";
            } else {
                ss << node_arr[i]->val;
            }
            ss << ",";
        }
        string ret_str = ss.str();
        ret_str[ret_str.size()-1] = '}';
        return ret_str;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        //split and convert data to vector<TreeNode*>

        if (data == "{}") return NULL;

// 字符串转换成TreeNode*数组
        vector<TreeNode*> node_arr;
        stringstream ss(data.substr(1,data.size()-2));
        string token;
        while (getline(ss, token, ',')) {
            if (token == "#") {
                node_arr.push_back(NULL);
            } else {
                node_arr.push_back( new TreeNode(atoi(token.c_str())) );
            }
        }

// TreeNode*数组转换成tree
        int node_i = 0;
        for(int i=0; i<node_arr.size();i++) {
            // 跳过null节点
            if (node_arr[i]==NULL) {
                continue;
            }
            // 添加左右child
            if (node_i + 1 < node_arr.size()) {
                node_arr[i]->left = node_arr[++node_i];
            }
            if (node_i + 1 < node_arr.size()) {
                node_arr[i]->right = node_arr[++node_i];
            }
        }
        return node_arr[0];
    }
};

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution_preorder {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     *
     * preorder 比较好写些
     */
    string serialize(TreeNode *root) {
        // write your code here
        if (root == NULL) return "{}";

        stringstream ss;
        ss << "{";
        serialize_helper(root, ss);
        ss << "}";
        return ss.str();
    }

    void serialize_helper(TreeNode* root, stringstream& ss) {
        if ( root == NULL ) {
            ss << "#" << ",";
            return;
        } else {
            ss << root->val << ",";
        }
        serialize_helper(root->left, ss);
        serialize_helper(root->right, ss);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        if (data == "{}") {
            return NULL;
        }
        stringstream ss(data.substr(1,data.size()-2));

        TreeNode* root = NULL;
        deserialize_helper(ss, root);
        return root;
    }
    void deserialize_helper(stringstream &ss, TreeNode* &root) {
        string token;
        if (getline(ss, token, ',')) {
            if (token == "#") {
                root = NULL;
                return;
            } else {
                root = new TreeNode( atoi(token.c_str()) );
            }
        }
        deserialize_helper(ss, root->left);
        deserialize_helper(ss, root->right);
    }

};