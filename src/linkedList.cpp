#include <linkedList.hpp>

void ListNode::initalizeList(const int n, const int m)
{
  ListNode *root = this;
  
  for(int i = 0; i < n; i++)
  {
    root->vec.resize(m, 0);
    root->next = new ListNode();
    root = root->next;
  }
}

//copys the data of an n * m linkedList data to an n * m linkedList "this"
void ListNode::copyData(ListNode *data, const int n, const int m)
{
  ListNode *ptr = this;
  for(int i = 0; i < n; i++, ptr = ptr->next, data = data->next)
  {
    for(int j = 0; j < m; j++)
    {
      ptr->vec[j] = data->vec[j];
    }
  }
}
