#include<iostream>
#include<queue>

using namespace std;

struct Node {
  int value;
  Node*left;
  Node* right;
};

Node *createNode(int value){
  Node *newNode = new Node();
  newNode->value = value;
  newNode->left = nullptr;
  newNode->right = nullptr;  
  return newNode; 
}

void printNodesPreOrder(Node* rootNode){
  if(rootNode == nullptr) return;
  cout << rootNode->value << endl;
  printNodesPreOrder(rootNode->left);
  printNodesPreOrder(rootNode->right);
}

void printNodesInOrder(Node* rootNode){
  if(rootNode == nullptr) return;
  printNodesInOrder(rootNode->left);
  cout << rootNode->value << endl;
  printNodesInOrder(rootNode->right);
}

void printNodesPostOrder(Node* rootNode){
  if(rootNode == nullptr) return;
  printNodesPostOrder(rootNode->left);
  printNodesPostOrder(rootNode->right);
  cout << rootNode->value << endl;
}

void printNodesLevelOrder(Node* rootNode){
  queue<Node*> nodeQueue;
  if(rootNode == nullptr) return;
  nodeQueue.push(rootNode);
  while(true){
    if(nodeQueue.empty()){
      break;
    }
    Node* tempNode = nodeQueue.front();
    nodeQueue.pop();
    cout<<tempNode->value<<endl;
    if(tempNode->left != nullptr){
      nodeQueue.push(tempNode->left);
    }
    if(tempNode->right != nullptr){
      nodeQueue.push(tempNode->right);
    }
  }
}

int main(){
  Node* rootNode = createNode(1);
  Node* left1 = createNode(2);
  Node* right1 = createNode(3);
  
  Node* left1left2 = createNode(4);
  Node* left1right2 = createNode(5);

  Node* right1left2 = createNode(6);
  Node* right1right2 = createNode(7);

  Node* left1right2left3 = createNode(9);
  Node* right1right2left3 = createNode(15);
  // level 1
  rootNode->left = left1;
  rootNode->right = right1;
  
  // level 2
  left1->left = left1left2;
  left1->right = left1right2;

  right1->left = right1left2;
  right1->right = right1right2;

  // level 3
  left1right2->left = left1right2left3;
  right1right2->left = right1right2left3;
  // currently, our tree looks like this:
  //
  //                1
  //               / \
  //              /   \
  //             2     3
  //            / \   / \
  //           4   5  6  7
  //               /    / 
  //              9    15

  cout<<"Performing Depth First Search" << endl;
  cout<<"Preorder Traversal" << endl;
  printNodesPreOrder(rootNode);
  cout<<"Inorder Traversal" << endl;
  printNodesInOrder(rootNode);
  cout<<"Postorder Traversal" << endl;
  printNodesPostOrder(rootNode);

  cout<< "-------------------------------------------------------------" <<endl;
  cout<<"Performing Breadth First Search" <<endl;
  printNodesLevelOrder(rootNode);
  return 1;
}
