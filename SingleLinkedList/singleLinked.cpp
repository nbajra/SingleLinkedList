#include "singleLinkedList.h"


//Default constructor
singleLinkedList::singleLinkedList()
{
    start = NULL;
}
//Destructor
singleLinkedList::~singleLinkedList()
{
    while(start != NULL)
        popFront();
    
    
}
// Create a new node with node* temp whose data is set to certain value 
 nodePtr singleLinkedList::createNode(double val)
{
    nodePtr temp;
    temp = new node;
    temp->data = val;
    temp->next = NULL;
    return temp;
    
}
//Inserts a node with data at the front of the list
 void singleLinkedList::pushFront(double val)
{
    nodePtr temp, n;
    temp = createNode(val);
     
     //check if list is empty; if empty temp otherwise insert n 
     if(start == NULL)
    {
        start = temp;
        start->next = NULL; //set next to null
    }
    else
    {
        n = start;
        start = temp;
        start ->next = n; //update next to n
        
    }
}
//Inserts a node with data at the back of the list
void singleLinkedList::pushBack(double val)
{
    nodePtr temp, m;
    temp = createNode(val);
    //check if the list is empty
    if(start == NULL)
    {
        start = temp;
        start ->next = NULL; //set next to NULl
    }
    else
    {
        m = start;
        while(m->next != NULL)
        {
            m = m->next; //update m 
        }
        temp->next = NULL;
        m->next = temp; //update m to temp
    }
}
//Delete front element
void singleLinkedList::popFront()
{
    nodePtr m;
    if(start != NULL)
    {
        m = start;
        start = start->next;
        delete m; //delete node 
    }
}
//Delete element front back of the list
void singleLinkedList::popBack()
{
    nodePtr m;
    //check if start node is null
    if(start != NULL)
    {
        if(start->next == NULL) //check if its start next is null
        {
            delete start; 
            start = NULL;  
            return;
        }
        m = start;
        while(m->next->next != NULL) 
        {
            m = m->next; 
        }
        delete m->next;
        m->next =  NULL;
    }
}
//Insert element at the specified position.
void singleLinkedList::insert(int pos, double val)
{
    int counter = size();
    nodePtr temp, m, ptr;
    temp = createNode(val);
    //if position is 0, start points to temporary node; else points to ptr or 
    //else if check the specified position using for loop and points to m
    if(pos == 0)
    {
        if(start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }

else if(0 < pos && pos < counter)
{
    ptr = start;
    m = start->next;
    for(int i = 1; i < pos; i++)
    {
        ptr = m;
        m = m->next;
    }
    ptr->next = temp;
    temp->next = m;
}   
}
//Delete duplicate node if there are any copies of given node.
void singleLinkedList::deleteDuplicates(double val)
{
    nodePtr ptr, m;
    ptr = NULL;
    m = start;
    while(m)
    {   //check if given value equals to data of node and delete it
        if(m->data == val)
        {
            nodePtr tmp = m;
            if(ptr == NULL)
                start = start->next;
            else
                ptr->next = m->next;
                
            m= m->next;
            delete tmp;
        }
        else
        {
            ptr = m;
            m = m->next;
        }
    }
}
//Place m to the Last Element
double singleLinkedList::mtoLastElement(int pos)
{
    int startPos = size()-1-pos;
    double ret = 0.0;
    if(startPos == 0)
    {
        if(start != NULL)
            ret = start->data;
    }
    else if(0 < startPos && startPos < size())
    {
        nodePtr m = start;
        for(int i = 0; i < startPos; i++)
            m = m->next;
            
            ret = m->data;
    }
    return ret;
    
}
//returns size with node pointer to next and increase counter
int singleLinkedList::size()
{
    int counter = 0;
    nodePtr m;
    m = start;
    while(m != NULL)
    {
        m=m->next;
        counter++;
    }
    return counter;
}
//reverse the list by creating 3 node pointer which each node pointing to next node
void singleLinkedList::reverseList()
{   //create  3 node
    nodePtr ptr1, ptr2, ptr3;
    if(start == NULL)
        return;
        
    if(start->next == NULL)
        return;
        
        ptr1 = start;
        ptr2 = ptr1->next;
        ptr2 = ptr2->next;
        ptr1->next = NULL;
        ptr2->next = ptr1;
        while(ptr3 != NULL)
        {
            ptr1 = ptr2;
            ptr2 = ptr3;
            ptr3 = ptr3->next;
            ptr2->next = ptr1;
        }
        start = ptr2;
}



