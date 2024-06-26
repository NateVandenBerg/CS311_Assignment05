//BST class - Binary Search Tree
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: Nathaniel VandenBerg
// Compiler:  g++
// File type: headher file BST.h
// @brief This class defines a BST search tree
//=======================================================

#ifndef ASSIGN_5_BST_H
#define ASSIGN_5_BST_H

// T: element data type
// int for node element typ now, but can be changed to any data type.
typedef int T;

/**
 * Class to implement a Binary Search Tree (BST)
 */
class BST {
public:
    /**
     * Nested helper Node class
     */
    class Node {
    public:
        /**
         * The data stored within a node
         */
        T data;

        /**
         * Pointer to the node's left child
         */
        Node* leftChild;

        /**
         * Pointer to the node's right child
         */
        Node* rightChild;

        /**
         * Pointer to the node's parent
         */
        Node* parent;

        /**
         * Node constructor, which initializes everything
         */
        Node(T d) : data(d), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}

    };

    /**
     * BST Constructor, which should initialize an empty BST
     */
    BST();

    /**
     * BST Destructor, which should deallocate anything dynamic
     */
    ~BST();
	
	void deleteTree(Node** treeRoot);

    /**
     * Insert a new element to this BST
     *
     * @param element The new element to insert
     * @return true if the insertion was successful, otherwise false (e.g. duplicate)
     */
    bool insert(T element);
	
	void insertRecur(Node** currRoot, T element);

    /**
     * Find a query element in this BST
     *
     * @param query The query element to find
     * @return true if query exists in this BST, otherwise false
     */
    bool find(const T & query) const;
	
	bool findRecur(Node** currNode, const T& query) const;

    /**
     * Return pointer to the left-most node in this BST
     *
     * @return The left-most node in this BST
     */
    Node* getLeftMostNode();

    /**
     * Return the left-most node of a subtree rooted at the node
     * @param node
     * @return
     */
    Node* getLeftMostNode(Node* node);
	
	Node* getRightMostNode();
	
	Node* getRightMostNode(Node* node);

    /**
     * Remove all elements from the BST and deallocate all nodes
     */
    void clear();

    /**
     * Return the number of elements in the BST
     *
     * @return The number of elements in the BST
     */
    unsigned int size() const;

	unsigned int CountNodes(Node** treeRoot) const;
    /**
     * @brief Return the maximum height of the BST. Root is at height 0
     * @return The height of the BST
     */
    int height() const;
	
	int heightRecur(Node** node) const;

    /**
     * @brief Return pointer to the root node of the BST
     * @return The root node of the BST. nullptr if the BST is empty
     */
     Node* getRoot();

    /**
     * @brief Print the subtree at the given node using inorder traversal
     * @param node a pointer to node in BST
     */
     void printInorder(Node* node);

    /**
    * @brief Print the subtree at node using preorder traversal
    * @param node a pointer to node in BST
    */
     void printPreorder(Node* node);

    /**
   * @brief Print the subtree at node using postorder traversal
   * @param node a pointer to node in BST
   */
    void printPostorder(Node* node);

    /**
     * Find the successor of this Node in the BST
     * @param node The node to find the successor of
     * @return Node* Pointer to the successor of this Node, or nullptr if none exists
     */
    Node* successor(Node *node);

private:
    /**
     * Pointer to the root node of this BST
     */
    Node* root;


    /**
     * Total number of elements currently in the BST
     */
    unsigned int numElements;

};

#endif //ASSIGN_5_BST_H

