#include <iostream>
#include <limits>

struct node {
    int val;
    node* left;
    node* right;
    node(int val = 0, node* left = nullptr, node* right = nullptr) : val(val), left(left), right(right) {};
};

void insert(node*& root, int val) {
    if (!root) {
        root = new node(val);
        return;
    }
    if (root->val > val) {
        insert(root->left, val);
    }
    else {
        insert(root->right, val);
    }
}

void deletetree(node* root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        delete root;
        return;
    }
    deletetree(root->left);
    deletetree(root->right);
    delete root;
}

bool isBST(node* root, int& temp){
    if(!root){
       return true;
    }
    if(!isBST(root->left, temp)) return false;
    if (temp < root->val){
        temp = root->val;
    }
    else {
	return false;
    }
    if(!isBST(root->right, temp)) return false;
    return true;
}
int main() {
    
    node* root2 = new node(7);
    root2->right = new node(10);
    root2->left = new node(5);
    root2->right->left = new node(8);
    int temp = std::numeric_limits<int>::min();
    std::cout<<isBST(root2, temp);

    node* root = nullptr;
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    temp = std::numeric_limits<int>::min();
    std::cout<<isBST(root, temp);
    deletetree(root);

}
