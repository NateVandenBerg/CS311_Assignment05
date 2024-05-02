/**
 * Implementation of BST class.
 */

//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: Nathaniel VandenBerg
// Compiler:  g++
// File type: cpp file BST.cpp
// @brief This class implements a BST search tree
//=======================================================

#include "BST.h"
#include <vector>
#include<iostream>

/**
 * Implement the BST constructor
 */
BST::BST() {
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    deleteTree(&root);
}

void BST::deleteTree(Node** treeRoot) {
    Node* Root = *treeRoot;
    if (Root)
    {
        numElements--;
        deleteTree(&Root->leftChild);
        deleteTree(&Root->rightChild);
        delete Root;
    }
    root = nullptr;
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /*Node* Root = root;
    if (Root == NULL)
        return (0);
    int count = CountNodes(&Root);
    return(count);*/
    return numElements;
}

unsigned int BST::CountNodes(Node** treeRoot) const {
    Node* Root = *treeRoot;
    if(Root == NULL)
        return 0;
    int L = CountNodes(&Root->leftChild);
    int R = CountNodes(&Root->rightChild);
    return(L + R + 1);
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    deleteTree(&root);
}

/**
 * Implement insert() correctly
 */
bool BST::insert(T element) {
        insertRecur(&root, element);
        numElements++;

    return true;
}

void BST::insertRecur(Node** currRoot, T element) {
    Node* currNode = *currRoot;

    if (*currRoot == nullptr) {
        currNode = new Node(element);
    }

    if (element < currNode->data) {
        insertRecur(&currNode->leftChild, element);
        currNode->leftChild->parent = currNode;
    }

    else if (element > currNode->data) {
        insertRecur(&currNode->rightChild, element);
        currNode->rightChild->parent = currNode;
    }
    *currRoot = currNode;
}

/**
 * Implement find() correctly
 */
bool BST::find(const T &query) const {
    if (root == NULL)
        return false;
    if (query == root->data)
        return true;
    Node* treeRoot = root;
    bool search = findRecur(&treeRoot, query);
    if (search == true) {
        return true;
    }        
    else {
        return false;
    }    
}


bool BST::findRecur(Node** currNode, const T& query) const {
    Node* node = *currNode;
    if (node == nullptr)
        return false;
    if (query == node->data)
        return true;
    else if (query < node->data) {
        bool L = findRecur(&node->leftChild, query);
        if (L == true)
            return true;
    }
    else if (query > node->data) {
        bool R = findRecur(&node->rightChild, query);
        if (R == true)
            return true;
    }    
    else {
        return false;
    }
    return false;        
}

/**
 * Implement the height() function correctly
 */
int BST::height() const {
    if (root == nullptr) {
        return -1;
    }
    Node* treeRoot = root;
    int Height = heightRecur(&treeRoot);

    return Height;
}

int BST::heightRecur(Node** currNode) const {
    Node* node = *currNode;

    if (node == nullptr) {
        return -1;
    }
    int leftHeight = 1 + heightRecur(&node->leftChild);
    int rightHeight = 1 + heightRecur(&node->rightChild);
    
    if(leftHeight > rightHeight)
        return (leftHeight);
    else
        return (rightHeight);
}

/**
 * Implement the getRoot() function correctly
 */
BST::Node* BST::getRoot() {
    return root;
}

/**
 * @brief Print the subtree at node using inorder traversal
 * @param node a pointer to node in BST
 */
void BST::printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->leftChild);
    std::cout << node->data << " ";
    printInorder(node->rightChild);
}

/**
* @brief Print the subtree at node using preorder traversal
* @param node a pointer to node in BST
*/
void BST::printPreorder(Node* node) {
    if (node == NULL)
        return;
    std::cout << node->data << " ";
    printPreorder(node->leftChild);
    printPreorder(node->rightChild);
}

/**
* @brief Print the subtree at node using postorder traversal
* @param node a pointer to node in BST
*/
void BST::printPostorder(Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->leftChild);
    printPostorder(node->rightChild);
    std::cout << node->data << " ";
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node *BST::getLeftMostNode() {
    Node* leftMost = root;

    while (leftMost->leftChild != nullptr) {
        leftMost = leftMost->leftChild;
    }

    return leftMost;
}

BST::Node* BST::getLeftMostNode(Node* node) {
    Node* leftMost = node;

    while (leftMost->leftChild != nullptr) {
        leftMost = leftMost->leftChild;
    }

    return leftMost;
}

BST::Node* BST::getRightMostNode() {
    Node* rightMost = root;

    while (rightMost->rightChild != nullptr) {
        rightMost = rightMost->rightChild;
    }

    return rightMost;
}

BST::Node* BST::getRightMostNode(Node* node) {
    Node* rightMost = root;

    while (rightMost->rightChild != nullptr) {
        rightMost = rightMost->rightChild;
    }

    return rightMost;
}

/**
 * Implement the BST successor function correctly
 */
BST::Node *BST::successor(Node *node) {
    if (node == nullptr) {//pointer = NULL
        return nullptr;
    }

    else if (node->parent == nullptr) {//pointer = root
        Node* successor = getLeftMostNode(node->rightChild);
        return successor;
    }
    
    else if (node->leftChild == nullptr && node->rightChild == nullptr) {//both children = NULL
        if (node == getLeftMostNode(root)) {//node = left most node
            Node* successor = node->parent;
            return successor;
        }

        else if (node == getRightMostNode(root)) {//node = right most node
            return nullptr;
        }

        else
            return node->parent;
    }    

    else if ( node->leftChild == nullptr && node->rightChild != nullptr) {//left is NULL & right is not
        Node* successor = getLeftMostNode(node->rightChild);
        return successor;
    }

    else if (node->leftChild != nullptr && node->rightChild == nullptr) {//right is NULL & left is not
        if (node == getRightMostNode(root->leftChild)) {

            return root;
        }
        Node* successor = node->parent->parent;
        return successor;
    }

    else if (node->leftChild != nullptr && node->rightChild != nullptr) {//node has 2 children
        Node* successor = getLeftMostNode(node->rightChild);
        return successor;
    }
    return nullptr;
}

