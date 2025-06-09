#include<iostream>

void performPredefinedOperations();

class Node{
public:
  Node(int node_value, Node *next_node){
    value = node_value;
    nxt_node = next_node; 
  }  

  Node(int node_value){
    value = node_value;
    nxt_node = nullptr;
  }
  int value;
  Node *nxt_node;
};

class LinkedList{
public:
  void printNodes(Node *head_node){
    while(head_node != nullptr){
      std::cout << head_node->value << std::endl;
      head_node = head_node->nxt_node;
    }
  }

  Node *insertAtFront(int val, Node *head_node){
    Node *temp_node = new Node(val,head_node);
    return temp_node;
  }

  void insertToBack(int val, Node *head_node){
    while(head_node->nxt_node != nullptr){
      head_node = head_node->nxt_node;
    }
    //arrived at the last node_value
    Node *new_last_node = new Node(val);
    head_node->nxt_node = new_last_node;
  }

  void insertAtIndex(int val, int index, Node *head_node){
    if(index == 0){
      std::cout << "Use insertAtFront() method to insert at index 0" <<std::endl;
      return;
    }
    for(int i=0;i<index-1;i++){
      head_node = head_node->nxt_node;
    }
    Node *tempNode = new Node(val, head_node->nxt_node);
    head_node->nxt_node = tempNode;
  }

   Node *deleteFirstNode(Node *head_node){
    Node *temp_node = head_node;
    head_node = head_node->nxt_node;
    delete temp_node;
    return head_node;
  }

  void deleteNodeByIndex(int index, Node *head_node){
    if(index == 0){
      std::cout << "Use deleteFirstNode() method to delete first node\n";
      return;
    }
    for(int i=0;i<index-1;i++){
      head_node = head_node->nxt_node;
    }
    // now the head points at position just before the index that we want to delete
    Node *tempNode = head_node->nxt_node;
    head_node->nxt_node = head_node->nxt_node->nxt_node;
    delete tempNode;
  }

  int searchValue(int value, Node *head_node){
    int curr_idx = 0;
    while(head_node != nullptr){
      if(head_node->value == value){
        return curr_idx;
      }
      curr_idx++;
      head_node = head_node->nxt_node;
    }
    return -1;
  }

  int getLength(Node *head_node){
    if(head_node == nullptr){
      return 0;
    }
    int length = 0;
    while(head_node != nullptr){
      length++;
      head_node = head_node->nxt_node;
    }
    return length;
  }

  Node *reverse(Node *head_node){
    Node *current = head_node, *next, *previous = nullptr;
    while(current != nullptr){
      next = current->nxt_node;
      
      current->nxt_node = previous;

      previous = current;
      current = next;
    }
    return previous;
  }

  Node *middleNode(Node *head_node){
    Node *fast, *slow;
    fast = head_node;
    slow = head_node;
    while(fast != nullptr && fast->nxt_node != nullptr){
      fast = fast->nxt_node->nxt_node;
      slow = slow->nxt_node;
    }
    return slow;
  }

  Node *sort(Node *head_node){
    int length = getLength(head_node);
    Node *iterCopy = head_node; 
    std::cout << "length of head node:" << length << std::endl;
    for(int i=0;i<length-1;i++){
      for(int j=0;j<length-i-1;j++){
        if(iterCopy->value > iterCopy->nxt_node->value){
          int temp = iterCopy->value;
          iterCopy->value = iterCopy->nxt_node->value;
          iterCopy->nxt_node->value = temp;
        }
        iterCopy = iterCopy->nxt_node;
      }
      iterCopy = head_node;
    }
    return iterCopy;
  }

// Node *divide(){
// 
//}

  ~LinkedList(){
  
  }

  Node *m_head;
};

int main(int argc, char *argv[]){
  int inOption;
  std::cout << "Welcome to Linked List Demonstration\n ";
  std::cout << "Select an option: \n";
  std::cout << "-----------------------------------\n";
  std::cout << "Perform Predefined Operation - 1 \n";
  std::cin >> inOption;
  switch (inOption) {
    case 1:
      performPredefinedOperations();
      break;
    
    default:

      break;
  }
  return 0;
}

void performPredefinedOperations(){
  Node *head_node = new Node(2);
  std::cout << "Welcome to singly linked list demo. Inserting elements 2,3,5 manually into linked list" << std::endl;
  LinkedList ls;
  ls.insertToBack(3, head_node);
  ls.insertToBack(5, head_node);

  std::cout << "Printing the nodes" << std::endl;
  ls.printNodes(head_node);

  std::cout << "Inserting data at the front using in-built function" << std::endl;
  head_node = ls.insertAtFront(1, head_node);
  ls.printNodes(head_node);

  std::cout << "Inserting few elements at back" << std::endl;
  ls.insertToBack(6, head_node);
  ls.insertToBack(7,head_node);
  ls.insertToBack(8,head_node);
  ls.printNodes(head_node);
  
  std::cout << "Inserting element at index 7" << std::endl;
  ls.insertAtIndex(99, 7, head_node);
  ls.printNodes(head_node);
  
  std::cout << "deleting first node\n";
  head_node = ls.deleteFirstNode(head_node);
  ls.printNodes(head_node);

  std::cout << "deleting node at index 2\n";
  ls.deleteNodeByIndex(2, head_node);
  ls.printNodes(head_node);

  std::cout << "Searching for value 99\n";
  int outVal = ls.searchValue(99, head_node);
  std::cout << "Value: (-1 if not found): \n" << outVal << std::endl;

  std::cout << "Searching for value 80\n";
  outVal = ls.searchValue(80, head_node);
  std::cout << "Value: (-1 if not found): \n" << outVal << std::endl;

  std::cout << "finding the length of the list\n";
  int length = ls.getLength(head_node);
  std::cout << length << std::endl;

  std::cout << "Reversing the list\n";
  head_node = ls.reverse(head_node);
  ls.printNodes(head_node);

  std::cout << "Finding the middle node\n";
  Node *middle_node = ls.middleNode(head_node);
  std::cout << middle_node->value << std::endl;

  std::cout << "Sorting the linked list\n";
  head_node = ls.sort(head_node);
  ls.printNodes(head_node);
}






