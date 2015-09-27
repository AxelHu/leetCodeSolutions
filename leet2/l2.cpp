// "l2.cpp" -*- C++ -*-

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x)
    : val(x), next(NULL){}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
  int temp = l1->val + l2->val;
  ListNode* position = new ListNode(temp%10);
  int plusOne = 0;
  if(temp/10 == 1)
    plusOne = 1;
  ListNode* head = position;
  l1 = l1->next;
  l2 = l2->next;

  while(l1 != NULL || l2 != NULL)
    {
      if(l1 != NULL && l2 != NULL)
	temp = l1->val + l2->val;
      else if(l1 == NULL)
	temp = l2->val;
      else if(l2 == NULL)
	temp = l1->val;
      position->next = new ListNode((temp + plusOne)%10);
      position = position->next;
      if((temp + plusOne)/10 == 1)
	plusOne = 1;
      else
	plusOne = 0;
      if(l1 != NULL && l2 != NULL)
	{
	  l1 = l1->next;
	  l2 = l2->next;
	}
      else if(l1 == NULL)
	l2 = l2->next;
      else if(l2 == NULL)
	l1 = l1->next;
    }
  if(plusOne != 0)
    position->next = new ListNode(plusOne);
  return head;
}
