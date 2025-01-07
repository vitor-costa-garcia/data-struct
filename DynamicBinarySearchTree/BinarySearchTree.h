#ifndef BINARY_TREE
#define BINARY_TREE

namespace bt
{
    template<typename T>
    struct Node{
        Node<T>* l;
        Node<T>* r;
        T val;
    };

    template<typename T>
    class BinaryTree{
        public:
            BinaryTree(T value, Node<T>* left = nullptr, Node<T>* right = nullptr){
                root = new Node<T>{left, right, value};
            };

            void insert(T value);
            void pop(T value);
            bool find(T value);
            int find_depth(Node<T>* node, int depth);
            int get_depth();
            void show();
            ~BinaryTree();

            int get_size(){
                return n_nodes;
            };

        private:
            int n_nodes = 0;
            Node<T>* root = nullptr;

            Node<T>* get_successor(Node<T>* node);
            Node<T>* rFind(Node<T>* node, T value);
            void rDeleteNode(Node<T>* node);
            void rShow(Node<T>* node, T* arr, int currIndex);
            Node<T>* recursiveDeletion(Node<T>* node, T value);
    };
}

#endif
