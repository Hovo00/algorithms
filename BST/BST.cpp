#include <iostream>
#include <stack>
#include <limits>

struct node {
    int val;
    node* left;
    node* right;
    node(int val = 0, node* left = nullptr, node* right = nullptr) : val(val), left(left), right(right) {};
};

class BST{
     public:
     BST(node* root = nullptr): root_m(root){};
     public:
     void insert(int);
     node* find(int);
     void deletetree();
     void print_inorder();
     void print_postorder();
     void print_preorder();
     void pre_order_stack();
     private:
     //support functions for recursion
     void insert_m(node*& root, int val);
     void print_inorder_m(node* root);
     void print_postorder_m(node* root);
     void print_preorder_m(node* root);
     void deletetree_m(node* root);
     node* find_m(node* root, int);

     node* root_m;
        
};

//function get numeric_limits::min() as second param.
bool isBST(node*, int&);


int main() {

    node* root = nullptr;
    BST tree(root);
    tree.insert(8);
    tree.insert(7);
    tree.insert(10);
    tree.insert(9);
    tree.insert(12);
    tree.insert(15);

    tree.print_inorder();
    std::cout<<std::endl;
    tree.print_preorder();
    std::cout<<std::endl;    
    tree.print_postorder();
    std::cout<<std::endl;    
    
    tree.pre_order_stack();
    std::cout<<std::endl;
    std::cout<<tree.find(9)<<std::endl;

    int a = std::numeric_limits<int>::min();
    std::cout<<std::endl;    
    std::cout<<isBST(root, a)<<std::endl;
    tree.deletetree();

}

void BST::insert(int val){
     insert_m(root_m, val);
}

void BST::deletetree(){
     deletetree_m(root_m);
}

void BST::print_inorder(){
     print_inorder_m(root_m);
}
void BST::print_postorder(){
     print_postorder_m(root_m);
}
void BST::print_preorder(){
     print_preorder_m(root_m);
}

node* BST::find(int val){
     return find_m(root_m, val);
}
void BST::insert_m(node*& root, int val) {
    if (!root) {
        root = new node(val);
        return;
    }
    if (root->val > val) {
        insert_m(root->left, val);
    }
    else {
        insert_m(root->right, val);
    }
}

void BST::deletetree_m(node* root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        delete root;
        return;
    }
    deletetree_m(root->left);
    deletetree_m(root->right);
    delete root;
}

void BST::print_inorder_m(node* root){
     if(!root) {
         return;
     }
     print_inorder_m(root->left);
     std::cout<<root->val<<" ";
     print_inorder_m(root->right);
}

node* BST::find_m(node* root ,int val){
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (root->val < val){
        return find_m(root->right, val);
    }
    else{
        return find_m(root->left, val);
    }
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

void BST::pre_order_stack(){
    if(!root_m) return;
    std::stack<node*> mystack;
    node* temp = nullptr;
    mystack.push(root_m);
    while(!mystack.empty()){
         std::cout<<mystack.top()->val<<" ";
         temp = mystack.top();
         mystack.pop();
         if(temp->right) mystack.push(temp->right);
         if(temp->left) mystack.push(temp->left);
    }
}

void BST::print_postorder_m(node* root){
    if (!root) return;
    print_postorder_m(root->left);
    print_postorder_m(root->right);
    std::cout<<root->val<<" ";
}

void BST::print_preorder_m(node* root){
    if (!root) return;
       std::cout<<root->val<<" ";
       print_preorder_m(root->left);
       print_preorder_m(root->right);
}
