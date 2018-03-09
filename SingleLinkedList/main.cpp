
#include <cstdlib>
#include "singleLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
        int choice, pos, s;
        double val;
        double ret;
        singleLinkedList singleList;
        while(true)
        {
            cout << endl << ".................................." << endl;
            cout << endl << "Operations for Singly Linked List" <<endl;
            cout << endl << ".................................." << endl;
            cout << "1. Insert node at the front." << endl;
            cout << "2. Insert node at the back." << endl;
            cout << "3. Delete  the front node." <<endl;
            cout << "4. Delete the back node." << endl;
            cout << "5. Insert node at specified position." <<endl;
            cout << "6. Delete duplicate nodes." << endl;
            cout << "7. Place mth to the last element." << endl;
            cout << "8. Size." << endl;
            cout << "9. Reverse the element" << endl;
            cout << "0. Exit." << endl;
            cout << "> ";
            
            cin>>choice;
            
                switch(choice)
                {
                    case 1:
                        cout << "Inserting Node at the front: " <<endl;
                        cin >> val;
                        singleList.pushFront(val);
                        cout << "List : " << singleList << endl << endl;
                        break;
                        
                    case 2:
                        cout << "Inserting Node at the back: " <<endl;
                        cin >> val;
                        singleList.pushBack(val);
                         cout << "List : " << singleList << endl << endl;
                        break;
                    
                    case 3:
                        cout << "Deleting Node from the front: " <<endl;
                        singleList.popFront();
                        cout << "List : " << singleList << endl << endl;
                        break;
                    
                    case 4:
                        cout << "Deleting Node from the back: " <<endl;
                        singleList.popBack();
                        cout << "List : " << singleList << endl << endl;
                        break;
                    
                    case 5:
                        cout << "Inserting Node at the given position: " <<endl;
                        cout << "Value: ";
                        cin >> val;
                        cout << "Position: ";
                        cin >> pos;
                        singleList.insert(pos, val);
                        cout << "List : " << singleList << endl << endl;
                        break;
                        
                    case 6:
                        cout << "Deleting duplicate node: " <<endl;
                        cin >> val;
                        singleList.deleteDuplicates(val);
                        cout << "List : " << singleList << endl << endl;
                        break;
                    
                    case 7:
                        cout << "Replacing  m Node at the last element : " <<endl;
                        cin >> pos;
                        ret = singleList.mtoLastElement(pos);
                        cout << "List : " << ret << endl << endl;
                        break;
                    
                    case 8:
                        cout << "Finding the node size: " <<endl;
                         s = singleList.size();
                         cout << "Size : " << s << endl << endl;
                        break;
                    
                    case 9:
                        cout << "Reverse List: " <<endl;
                        singleList.reverseList();
                        cout << "List : " << singleList << endl;
                        break;
                    
                    case 0:
                        cout << "Exiting..." << endl;
                    
                    default:
                        cout << "***Wrong input***" << endl;
                }
                
            }
}


