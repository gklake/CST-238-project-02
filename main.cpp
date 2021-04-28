#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {

    //Append Test:
    LinkedList lla;
    lla.display();
    lla.append(1);
    lla.append(2);
    lla.append(3);
    lla.display();

    //Search Test:
    cout << "Is 2 in the linked list? (should be true): ";
    cout << boolalpha << lla.search(2) << endl; 
    cout << "Is 3 in the linked list? (should be true): ";
    cout << boolalpha << lla.search(3) << endl; 
    cout << "Is 5 in the linked list? (should be false): ";
    cout << boolalpha << lla.search(5) << endl;
    cout << endl;

    //InsertAfter Test: 
    cout << "inserting 4 after 2 (should be true): ";
    cout << boolalpha << lla.insertAfter(2, 4) << endl;
    cout << "inserting 6 after 3 (should be true): ";
    cout << boolalpha << lla.insertAfter(3, 6) << endl;
    cout << "inserting 8 after 7 (should be false): ";
    cout << boolalpha << lla.insertAfter(7, 8) << endl;
    lla.display();
    cout << endl;

    //Remove Test:
    cout << "removing 4 (should  be true): ";
    cout << boolalpha << lla.remove(4) << endl;
    cout << "removing 6 (should  be true): ";
    cout << boolalpha << lla.remove(6) << endl;
    cout << "removing 7 (should  be false): ";
    cout << boolalpha << lla.remove(7) << endl;    
		lla.display();
    cout << endl;

    LinkedList llb (lla);
    lla.display();
    llb.display();
    cout << "changing the second linked list" <<endl;
    llb.append(4);
    llb.remove(3);
    lla.display();
    llb.display();
    cout << endl;


    LinkedList llc;
    llc.append(10);
    llc.append(100);
    llc.append(1000);
    lla.display();
    llc.display();
    cout << "reassigning the second linked list to the first" <<endl;
    llc = lla;
    lla.display();
    llc.display();    
    cout << "changing the second linked list" <<endl;
    llc.remove(2);
    llc.insertAfter(1, 10);
    lla.display();
    llc.display();  

}