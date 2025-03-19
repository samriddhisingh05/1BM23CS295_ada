/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    struct ListNode *ptr1= head,*ptr2= head;
    struct ListNode *prev =NULL;
    while(ptr1 !=NULL && ptr1->next !=NULL){
        ptr1=ptr1->next->next;
        prev=ptr2;
        ptr2=ptr2->next;
    }
    prev->next=ptr2->next;
    return head;
}
struct ListNode* creatNode(int val) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val=val;
    newNode->next=NULL;
    return newNode;
}
void printList(struct ListNode *head)
{
    struct ListNode *temp=head;
    while(temp !=NULL){
        printf("%d ->",temp->val);
        temp=temp->next;
}
printf("NULL\n");
}
