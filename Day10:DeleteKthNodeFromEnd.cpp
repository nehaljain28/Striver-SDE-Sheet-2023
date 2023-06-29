/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    if(!head)return NULL;
    Node* ans=new Node();
    ans->next=head;
    Node* cur=ans;
    while(K--)
    {
        cur=cur->next;
    }
   
    Node* cur2=ans;
    while(cur->next)
    {
        cur2=cur2->next;
        cur=cur->next;
    }
    cur2->next=cur2->next->next;
    
    return ans->next;
    // Write your code here.
}
