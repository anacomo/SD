#include "PairingHeap.cpp"

int main()
{
/*    PairingHeap pheap(3);
    cout << pheap.getSize();
    cout << pheap.getMin();
    pheap.insert(2);
    cout << pheap.getMin();
    pheap.insert(5);
    pheap.insert(6);
    pheap.insert(1);
    cout << pheap.getMin();*/
    PairingHeap pheap(0);
    //vector <int> vct = {4, 6};
    //pheap.heapify(vct);
    int choice, val, pos;
    bool cont = true;
    while(cont)
    {
        cout << "Possible operations on Pairing Heap\n";
        cout << "1. Insert element\n";
        cout << "2. Delete min\n";
        cout << "3. Delete val\n";
        cout << "4. Quit\n\n";
        cout << "Your choice: ";
        cin >> choice;
        cout << '\n';
        switch (choice)
        {
        case 1:
            cout << "Enter the number you want to insert: ";
            cin >> val;
            pheap.insert(val);
            cout << "\nYou inserted " << val << '\n';
            break;
        case 2:
            cout << "You deleted the minimum " << pheap.getMin() << '\n';
            pheap.deleteMin();
            break;
        case 3:
            cout << "Enter the value you want to delete: ";
            cin >> val;
            cout << "You deleted the value " << val << '\n';
            pheap.deleteVal(val);
            break;
        case 4:
            cont = false;
            break;
        default:
            cout << "Please choose a valid choice\n";
            break;
        }
    cout << '\n';
    }
}