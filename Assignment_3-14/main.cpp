#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <string>

using namespace std;

template <class T> void printList(const list<T>& lst, string s)
{
    cout << s << ":  ";
    for(typename list<T>::const_iterator i = lst.begin(); i != lst.end(); i++)
        cout << *i << ' ';
    cout << endl;
}

int main()
{
    list<int> lst1;
    printList(lst1, "lst1");
    list<int> lst2(3, 7);
    printList(lst2, "lst2");
    for(int j = 1; j <= 5; j++)
        lst1.push_back(j);
    list<int>::iterator i1 = lst1.begin(), i2 = i1, i3;
    i2++;
    i2++;
    i2++;
    list<int> lst3(++i1, i2);
    printList(lst3, "lst3");
    list<int> lst4(lst1);
    printList(lst4, "lst4");
    i1 = lst4.begin();
    lst4.splice(++i1, lst2);
    printList(lst2, "lst2");
    printList(lst4, "lst4");
    lst2 = lst1;
    printList(lst2, "lst2");
    i2 = lst2.begin();
    lst4.splice(i1, lst2, ++i2);
    printList(lst2, "lst2");
    printList(lst4, "lst4");
    i2 = lst2.begin();
    i3 = i2;
    lst4.splice(i1, lst2, i2, ++i3);
    printList(lst2, "lst2");
    printList(lst4, "lst4");
    lst4.remove(1);
    printList(lst4, "lst4");
    lst4.sort();
    printList(lst4, "lst4");
    lst4.unique();
    printList(lst4, "lst4");
    lst1.merge(lst2);
    printList(lst1, "lst1");
    printList(lst2, "lst2");
    lst3.reverse();
    printList(lst3, "lst3");
    lst4.reverse();
    printList(lst4, "lst4");
    lst3.merge(lst4, greater<int>());
    printList(lst3, "lst3");
    printList(lst4, "lst4");
    lst3.remove_if(bind2nd(not_equal_to<int>(), 3));
    printList(lst3, "lst3");
    lst3.unique(not_equal_to<int>());
    printList(lst3, "lst3");
    return 0;
}