#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    if(!head)return true;
    // Write your code here.
    stack<int>st;
    LinkedListNode<int>* temp=head;
    while(temp)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    while(head)
    {
        if(head->data!=st.top())return false;
        head=head->next;
        st.pop();
    }
    return true;
    
    
}
