#include <iostream>
#include <stack>

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

void pre_order_stack(node* root){
    if(!root) return;
    std::stack<node*> mystack;
    node* temp = nullptr;
    mystack.push(root);
    while(!mystack.empty()){
	 std::cout<<mystack.top()->val<<" ";
	 temp = mystack.top();
	 mystack.pop();
	 if(temp->right) mystack.push(temp->right);
	 if(temp->left) mystack.push(temp->left);
    }
}
int main() {

    node* root = nullptr;
    insert(root, 7);
    insert(root, 10);
    insert(root, 5);
    insert(root, 22);
    insert(root, 9);
    insert(root, 8);
    insert(root, 14);
    print_inorder(root);
    std::cout<<std::endl;
    pre_order_stack(root);
    deletetree(root);
}
