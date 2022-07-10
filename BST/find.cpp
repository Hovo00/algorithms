#include <iostream>

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
void print_inorder(const node* root){
     if(!root) {
	 return;
     }
     print_inorder(root->left);
     std::cout<<root->val<<" ";
     print_inorder(root->right);
}

node* find(node* root, int val){
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (root->val < val){
	return find(root->right, val);
    }
    else{
	return find(root->left, val);
    }
}

int main() {

    node* root = nullptr;
    insert(root, 8);
    insert(root, 7);
    insert(root, 10);
    insert(root, 9);
    insert(root, 12);
    insert(root, 15);


    print_inorder(root);
    node* nodik = find(root,10);
    std::cout<<"nodik - "<<nodik->val<<std::endl;
    deletetree(root);

}
