template <typename T>
class bstNode {
    public:
        T data;
        bstNode* left;
        bstNode* right;

        bstNode(T val) : data(val), left(nullptr), right(nullptr) {}
};


template <typename T>
class BinarySearchTree {
    private:
        bstNode<T>* root;

        void recursiveDestroy(bstNode* node) {
            if (node != nullptr){
                recursiveDestroy(node->left);
                recursiveDestroy(node->right);
                delete node;
            }
        }

        ~BinarySearchTree () {
            recursiveDestroy(root);
        }
    
    public:
        BinarySearchTree() : root(nullptr) {};
        
        void insert(auto&& val){
            bstNode<T>* checkingNode = root;
            if (root == nullptr) {
                root = new bstNode<T>(val);
                return;
            }

            while (checkingNode != nullptr){
                if (val < checkingNode->data) {
                    if (checkingNode->left == nullptr) {
                        checkingNode->left = new bstNode<T>(val);
                        return;
                    }
                    checkingNode = checkingNode->left;
                } else if (val > checkingNode->data) {
                    if (checkingNode->right == nullptr) {
                        checkingNode->right = new bstNode<T>(val);
                        return;
                    }
                    checkingNode = checkingNode->right;
                } else {
                    return;
                }
            }
        }  




        int lookup(auto&& val) {
            bstNode<T>* checkingNode = root;
            if (checkingNode == nullptr) {
                return 0;
            }

            while(checkingNode != nullptr) {
                if (val == checkingNode->data) {
                    return 1;
                } else if (val < checkingNode->data) {
                    checkingNode = checkingNode->left;
                } else if (val > checkingNode->data) {
                    checkingNode = checkingNode->right;
                } 
            }
            return 0;
        }


// This is a bastard of a function to implement. Maybe come back later when you are a bit more advanced
        void remove(auto&& val) {
            if (root == nullptr) {
                return;
            }

            bstNode<T>* previousNode = root;
            bstNode<T>* currentNode = root;
            bstNode<T>* childLeft = nullptr;
            bstNode<T>* childRight = nullptr;
            
            int direction = 0;
            

            while (currentNode != nullptr){
                if (val < currentNode->data) {
                    previousNode = currentNode;
                    currentNode = currentNode->left
                    direction = 0;
                } else if (val > currentNode->data) {
                    previousNode = currentNode;
                    currentNode = currentNode->right
                    direction = 1;
                } else {
                    if (checkingNode->left != nullptr && checkingNode->right != nullptr){
                        bstNode<T>* successorParent = currentNode;
                        bstNode<T>* successor = currentNode->right;


                    }

                    
                }
            }
        }
};