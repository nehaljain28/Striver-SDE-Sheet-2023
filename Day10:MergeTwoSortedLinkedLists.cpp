#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first)return second;
    if(!second)return first;
    

       
        Node<int>* res = new Node<int>(-1);
        Node<int>* curr=res;
        
        while(second&&first)
        {
            if(first->data<=second->data)
            {
                res->next=first;
                first=first->next;
            }
            else
            {
                res->next=second;
                second=second->next;
            }
            res=res->next;
        }
        while(first)
        {
            res->next=first;
            first=first->next;
            res=res->next;
        }
        while(second)
        {
            res->next=second;
            second=second->next;
            res=res->next;
        }
        return curr->next;
    // Write your code here.
}
