#include<iostream>
#include "stacks_queues.h"

bool stack::push(int num){
  data.push_back(num);
  return true;
}

int stack::pop(){
  if(isEmpty()) return -1;
  int val = data.back();
  data.pop_back();
  return val; 
}

int stack::top(){
  if(isEmpty()) return -1;
  return data.back();
}

bool stack::isEmpty(){
  return data.empty();
}

int main(int argc, char *argv[]){
  stack s;
  std::cout << "Stack Implementation Test";
  std::cout << "Enter commands: \n 1 -- Enter Element \n 2 -- Pop Element \n 3 -- View Top Element \n 4 -- Exit \n";
  int input=0;
  int tempNum = 0;
  std::cin >> input;
  while(input > 0 && input <=3){
    if(input == 1){
      std::cout << "Enter the value to add to the stack " << std::endl;
      std::cin >> tempNum;
      s.push(tempNum);
    }else if(input == 2){
      std::cout << "Popping out an element out of stack" << std::endl;
      tempNum = s.pop();
      std::cout << tempNum << std::endl;
    }else if(input == 3){   
      std::cout << "Top Element: \t" << s.top() << std::endl;
    }else if(input == 4){
      std::cout << "Exiting" << std::endl;
      break;
    }
    std::cout << "Enter commands: \n 1 -- Enter Element \n 2 -- Pop Element \n 3 -- View Top Element 4 -- Exit \n";
    std::cin >> input;
  }
  std::cout << "exiting the program" << std::endl;              
}




