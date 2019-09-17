// Lab 6 Program
#include <iostream>

using namespace std;

// a node holds an int value item and points to the next node in the linked list
class node
{
public:
    int item;            // data held in node
    node* next;          // next node pointed to
    node(int x, node* t) // constructor assigns values to item and next
    {
        item = x;
        next = t;
    }
};

typedef node* link; // a link is a pointer to a node

// Removes link that is M nodes next to (after) x from the linked list
void remove(link& x, int M)
{
    for(int i = 1; i < M; i++) // go to next node M times
        x = x->next;
    x->next = x->next->next; // remove Mth node
}

// Inserts new link t after link x in linked list
void insert(link& x, link t)
{
    x = (x->next = t);
}

// Returns items of link x
int item(link& x)
{
    return x->item;
}

// Returns next link of x
link next(link& x)
{
    return x->next;
}

// circularly linked lists
int main()
{
    // i used in for loops. N represents number of nodes (including original) in the linked list.
    // M represents how many links from x we go before removing the Mth link
    int i, N = 1000000, M = 2;
    link t = new node(1, 0); // t is a link whose next node is...
    t->next = t;             // itself, i.e., t is now a circularly linked list. node t is the head
    link x = t;              // x represents the current node in the linked list. x is set to t here

    // Adds nodes to circularly linked list
    for(i = 2; i <= N; i++)
        insert(x, new node(i, t)); // replaces line below
        //x = (x->next = new node(i, t)); // x->next is set to a new node(i, t). Then x is set to x->next

    // Removes nodes from linked list until current node x points to itself
    while(x != x->next) {        // x is not the only member of its circularly linked list
        remove(x,M); // replaces the 3 lines below
        //for(i = 1; i < M; i++)   // for M-1 times....
        //    x = next(x);         // move to next node
        //x->next = x->next->next; // changes current node's next node to its next's next's node... oof
    }
    cout << item(x) << endl; // output data of current node. item(x) replaces x->item

    // Independent testing of my functions...
    // Manually create circularly linked list of size 5 for ease of testing
    link q = new node(8, 0); // placeholder 0...
    link u = new node(2, q);
    link a = new node(5, u);
    link r = new node(6, a);
    link z = new node(4, r);
    q->next = z; // make link q-u-a-r-z a circular linked list

    // link s will be used to traverse the linked list
    link s = z;
    // Use insert function to insert a new function after link q, making the list size 6
    insert(q, new node(7, z));
    // Print entire linked list to confirm all items are linked
    cout << "My linked list pre-remove:" << endl;
    for(i = 0; i < 6; i++) {
        cout << item(s) << endl; // use item() function to print item of current link
        s = next(s);             // use next() function to move to next link in linked list
    }
    // Remove link after 3 after z (i.e. link u/item 2)
    remove(z, 3);
    // Remove link 1 after r (i.e. a/item 5)
    remove(r, 1);
    // Print linked list now of size 4
    cout << "My linked list post-remove:" << endl;
    for(i = 0; i < 6; i++) // still going through circular list 6 times to prove the 2 removed link are gone
    {
        cout << item(s) << endl; // use item() function to print item of current link
        s = next(s);             // use next() function to move to next link in linked list
    }
}
