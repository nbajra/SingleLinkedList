
#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include<ostream>
using namespace std;

/*
 * Node Declaration with data type double and nodePtr for singly linked list.
 */
typedef struct node{
    double data;
    node* next;
}* nodePtr;  //prefix to create a struct node*

class singleLinkedList
{
public:
    singleLinkedList();
    ~singleLinkedList();
    
    //funtion prototype
    void pushFront(double val); //adds element to the front of the list
    void pushBack(double val);  //adds element to back of the list
    void popFront(); //deletes front element
    void popBack(); //deletes back element
    void insert(int pos, double val); //inserts a new node at given position
    void deleteDuplicates(double val); //deletes a given node and all its copies
    double mtoLastElement(int pos); //returns Mth to the last element of a list
    int  size(); //returns size of the list
    void reverseList(); // reverses a linked list 
    //overload put operator
    friend ostream& operator<<(ostream& out,const singleLinkedList& singleList)
    {
        if(singleList.start == NULL)
        {
            out << "Empty";
        }
        else
        {
            nodePtr s = singleList.start;
            while(s)
            {
                out << s->data << ", ";
                s = s->next;
            }
        }
        out << "\n";
        return out;
    }
    nodePtr createNode(double); //creates new node
    nodePtr start; //head pointer
};




#endif /* SINGLELINKEDLIST_H */

