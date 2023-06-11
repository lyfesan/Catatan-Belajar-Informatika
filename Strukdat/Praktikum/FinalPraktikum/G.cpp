#include<bits/stdc++.h>
using namespace std;

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

struct BST {
    BSTNode *_root;
    unsigned int _size;

    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void traverseInorder(int &cnt, int target) {
        if(target>_size) {cout<<-1; return;}
        __inorder(_root, cnt, target);
    }

    int getLevel(int data){
        return getLevelUtil(_root, data, 1);
    }

    void track(int data){
        __track(_root, data);
        cout<<"S\n";
    }

private:
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    void __inorder(BSTNode *root, int &cnt, int target) {
        if (root) {
            __inorder(root->left, cnt, target);
            cnt++;
            if(cnt==target) {cout<<root->key<<"\n"; return;}
            __inorder(root->right, cnt, target);
        }
    }

    int getLevelUtil(BSTNode *node, int data, int level){
        if (node == NULL) return 0;
        if (node->key == data)
            return level;
        int downlevel = getLevelUtil(node->left, data, level + 1);
        if (downlevel != 0) return downlevel;
        downlevel = getLevelUtil(node->right, data, level + 1);
        return downlevel;
    }

    void __track(BSTNode *root, int val){
         while (root != NULL) {
            if (val < root->key){
                root = root->left;
                cout<<"L";
            }   
            else if (val > root->key){
                root = root->right;
                cout<<"R";
            }
            else return;
        }
        return;
    }
};



int main(int argc, char const *argv[])
{
    BST set;
    set.init();
    int x,cnt;
    string s;
    while(true){
        cin>>s;
        if(s=="STOP"){
            cout<<"done\n";
            return 0;
        }
        else if(s=="IN"){
            cin>>x;
            set.insert(x);
        }
        else if(s=="FD"){
            cin>>x;
            if(set.find(x)) cout<<"on level "<<set.getLevel(x)<<"\n";
            else cout<<"no "<<x<<"\n";
        }
        else if(s=="RK"){
            cin>>x;
            cnt=0;
            set.traverseInorder(cnt,x);
        }
        else if(s=="PH"){
            cin>>x;
            if(set.find(x)) set.track(x);
            else cout<<"no "<<x<<"\n";
        }
        cout<<flush;
    }
}