
#pragma once

#include <iostream>
#include <vector>
class stack{
public:
  bool push(int num);
  int pop();
  int top();
  bool isEmpty();
private:
  std::vector<int> data;  
};

