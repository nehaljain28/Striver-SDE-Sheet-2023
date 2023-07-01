//brute
#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    map<LinkedListNode<int>*,LinkedListNode<int>*>mp;
    LinkedListNode<int>* temp=head;
    while(temp){
        LinkedListNode<int>* n=new LinkedListNode<int>(temp->data);
        mp[temp]=n;
        temp=temp->next;
    }
    LinkedListNode<int> *t=head;
    while(t){
        mp[t]->next=(t->next)?t->next:NULL;
        mp[t]->random=(t->random)?t->random:NULL;
        t=t->next;
    }
    return mp[head];
    // Write your code here.
}


//optimized s->O(1)

#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(!head)return NULL;
    LinkedListNode<int>* temp=head;
    LinkedListNode<int>* fwd=head;
    while(temp){
        fwd=temp->next;
        temp->next =new LinkedListNode<int>(temp->data);
        temp->next->next=fwd;
        temp=fwd;
    }
    LinkedListNode<int> *t=head;
    while(t){
        t->next->random=(t->random)?t->random->next:NULL;
        t=t->next->next;
    }
    LinkedListNode<int>* dum=new LinkedListNode<int>(0);
    temp=head;
    fwd=head;
    t=dum;
    while(temp){
        fwd=temp->next->next;
        t->next=temp->next;
        temp->next=fwd;
        temp=temp->next;
        t=t->next;
    }
    return dum->next;
    // Write your code here.
}

