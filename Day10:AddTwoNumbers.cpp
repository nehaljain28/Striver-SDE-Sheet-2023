/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* curr=new Node();
    Node* curr2=curr;
    int car=0;
    int sum=0;
    while(num1||num2||car)
    {
        sum=0;
        if(num1)
        {
            sum+=num1->data;
            num1=num1->next;
        }
        if(num2)
        {
            sum+=num2->data;
            num2=num2->next;
        }
        sum+=car;
        car=sum/10;
        Node* dig= new Node(sum%10);
        curr2->next=dig;
        curr2=curr2->next;
    }
    return curr->next;
    // Write your code here.
}
