#pragma once
#include <vector>
class ListNode{
public:
  ListNode *next;
  std::vector<float> vec;

  void initalizeList(const int n, const int m);
  void copyData(ListNode *data, const int n, const int m);
};
