//Recursion
class Solution {
private:
    int carry(ListNode *head){
        if(!head){
            return 0 ;
        }
        int num=2*head->val+carry(head->next) ;
        head->val=num%10 ;
        return num/10 ;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int add=carry(head) ;
        if(add){
            ListNode *node = new ListNode(add,head) ;
            head=node ;
        }

        return head ;
    }
};

//Using for but without any reverse or without using any extra space
ListNode* doubleIt(ListNode* head) {
      if (head->val > 4)
          head = new ListNode(0, head);
      for(ListNode* node = head; node; node = node->next) {
          node->val = (node->val * 2) % 10;
          if (node->next && node->next->val > 4)
              node->val++;
      }
      return head;
  }
