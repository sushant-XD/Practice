#include<iostream>
using namespace std;

struct Node{
  int value;
  Node* left;
  Node* right;
  Node(int val){
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};

void insertNode(Node* node, Node* rootNode){
  if(node == nullptr) return;
  if(rootNode == nullptr) return;
  // we need to assume that rootNode is not null (at least the root node exists)
  if(node->value < rootNode->value) {
    if(rootNode->left == nullptr){
      rootNode->left = node;
      return;
    }
    insertNode(node, rootNode->left);
  }
  if(node->value > rootNode->value){
    if(rootNode->right == nullptr){
      rootNode->right = node;
      return;
    }
    insertNode(node, rootNode->right);
  }
}  

Node* searchNode(Node* rootNode, int value){
  if(rootNode == nullptr) return nullptr;
  Node* foundptrref;
  if(rootNode->value > value){
    foundptrref = searchNode(rootNode->left, value);
  }
  else if(rootNode->value < value){
    foundptrref = searchNode(rootNode->right, value);
  }else {
    // found the value
    return rootNode;
  }
  return foundptrref;
}

void InOrderTraversal(Node* rootNode){
  if(rootNode == nullptr) return;
  InOrderTraversal(rootNode->left);
  cout<<rootNode->value<<endl;
  InOrderTraversal(rootNode->right);
}


int findMin(Node* rootNode){
  while(rootNode->left != nullptr){
    rootNode = rootNode->left;
  }
  return rootNode->value;
}

Node* RemoveValue(Node* rootNode, int value){
  if(rootNode == nullptr) return nullptr;
  if(value > rootNode->value){
    rootNode->right = RemoveValue(rootNode->right, value);
  } else if(value < rootNode->value){
    rootNode->left = RemoveValue(rootNode->left, value);
  } else{
    if(rootNode->left == nullptr && rootNode->right == nullptr){
      delete rootNode;
      rootNode = nullptr;
    }else if(rootNode->left == nullptr){
      Node* tempNode = rootNode;
      rootNode = rootNode->right;
      delete tempNode;
    }else if(rootNode->right == nullptr){
      Node* tempNode = rootNode;
      rootNode = rootNode->left;
      delete tempNode; 
    }else{
      //find the minimum value from the right sub-tree
      int val = findMin(rootNode->right);
      rootNode->value = val;
      rootNode->right = RemoveValue(rootNode->right, val);
    }
  }
  return rootNode;
}

int main(){
  cout<<"Binary Search Trees" << endl;
  Node* rootNode = new Node(4);
  Node* leftNode1 = new Node(3);
  Node* rightNode1 = new Node(6);
  Node* leftNode1left2 = new Node(1);
  Node* leftNode1right2 = new Node(2);
  Node* rightNode1left2 = new Node(5);
  Node* rightNode1right2 = new Node(7);
  insertNode(leftNode1, rootNode);
  insertNode(rightNode1, rootNode);
  insertNode(leftNode1left2, rootNode);
  insertNode(leftNode1right2, rootNode);
  insertNode(rightNode1left2, rootNode);
  insertNode(rightNode1right2, rootNode);
  cout<<"In order traversal of the binary search tree" << endl;
  InOrderTraversal(rootNode);
  cout << "Enter an element to search in the node" << endl;
  int inputNum;
  cin >> inputNum;
  Node* foundNode = searchNode(rootNode, inputNum);
  if(foundNode){
    cout<<"Found Value" << foundNode->value<<endl;
  }else{
    cout << "Value not in the tree" << endl;
  }
  cout << "Enter value to remove from the node" << endl;
  cin >> inputNum;
  rootNode = RemoveValue(rootNode, inputNum);
  cout << "After deleting the value" << endl;
  InOrderTraversal(rootNode);
}
