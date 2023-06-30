/****************************************************************

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

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead==NULL||secondHead==NULL)return NULL;
    Node* a=firstHead;
    Node* b=secondHead;
    while(a!=b)
    {
        a=a==NULL?secondHead:a->next;
        b=b==NULL?firstHead:b->next;
    }
    return b;
}
