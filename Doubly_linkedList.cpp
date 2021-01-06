//Doubly linked list using template class - generic programming
#include <bits/stdc++.h>
using namespace std;

template <class T>
//creating struct node with data and two pointers, next and prev
struct node
{
    T data;
    node<T> *next;
    node<T> *prev;
};

template <class T>
//ceating class named linkedlist
class linkedlist
{
private:
    //initializing the head and tail pointer
    node<T> *head;
    node<T> *tail;

public:
    //using constructor to assigning head to NULL
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    // function to get the size of the doubly linked list
    int size()
    {
        node<T> *temp = head;
        int s = 0;
        while (temp)
        {
            s++;
            temp = temp->next;
        }
        return s;
    }
    //function to create the doubly linked list
    node<T> *create_ll(T val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            head->prev = head->next = NULL;
            temp = NULL;
        }
        // if it has one or multiple nodes
        else
        {
            tail->next = temp;
            temp->prev = tail;
            temp->next = NULL;
            tail = temp;
            temp = NULL;
        }
        return head;
    }
    //function to insert a node at the beginning of the doubly linked list
    void insert_beg(T val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;
        temp->prev = NULL;
        //if the linked list is empty
        if (head == NULL)
        {
            temp->next = NULL;
            tail = temp;
        }
        //if it has one or multiple nodes
        else
        {
            temp->next = head;
            head->prev = temp;
        }
        head = temp;
    }
    //function to insert a node at the end of the doubly linked list
    void insert_end(T val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;
        temp->next = NULL;
        //if the linked list is empty
        if (head == NULL)
        {
            temp->prev = NULL;
            tail = temp;
            head = temp;
        }
        //if it has one or multiple nodes
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    //function to insert a node at the given position in the doubly linked list
    void insert_pos(T val, int pos)
    {
        node<T> *temp = new node<T>();
        temp->data = val;

        node<T> *p = head;
        //if the linked list is empty
        if (head == NULL)
        {
            cout << "The linked list is empty" << endl;
        }
        //if the given position is equal to zero
        else if (pos == 0)
        {
            insert_beg(val);
        }
        //if the given position is equal to size of the linked list
        else if (pos == size())
        {
            insert_end(val);
        }
        //if the position is less than the size of the linked list
        else if (pos < size())
        {
            int i = 0;
            while (i != pos - 1)
            {
                p = p->next;
                i++;
            }
            p->next->prev = temp;
            temp->next = p->next;
            p->next = temp;
            temp->prev = p;
        }

        else
            cout << "Position not found!!";
    }

    //function to delete a node from the beginning of the doubly linked list
    void delete_beg()
    {
        //if the linked list is empty
        if (head == NULL)
        {
            cout << "There is no Element to delete" << endl;
        }

        //if the linked list has one or multiple nodes
        else
        {
            node<T> *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }

    //function to delete a node from the ending of the doubly linked list
    void delete_end()
    {
        //if the linked list is empty
        if (head == NULL)
        {
            cout << "The linked list is empty" << endl;
        }
        //if the linked list has only one node
        else if (tail == head)
        {
            node<T> *temp = head;
            head = NULL;
            tail = NULL;
            free(temp);
        }
        //if the linked list has multiple nodes
        else
        {
            node<T> *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            tail = temp;
            node<T> *p = temp->next;
            temp->next = NULL;
            free(p);
        }
    }

    //function to delete a node from the given position of the doubly linked list
    void delete_pos(int pos)
    {
        node<T> *temp = head;
        //if the linked list is empty
        if (head == NULL)
        {
            cout << "There is no Element to delete" << endl;
        }

        s //if the given position is equal to zero
            else if (pos == 0)
        {
            delete_beg();
        }
        //if the position is less than the size of the linked list
        else if (pos < size())
        {
            int i = 0;
            while (i != pos)
            {
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }

        //if the given position is equal to size of the linked list
        else if (pos == size())
        {
            delete_end();
        }

        else cout << "position not found";
    }

    //function to search a node in the Doubly linked list
    void search_ll(T val)
    {
        //if the linked list is  empty
        if (head == NULL)
            cout << "The linked list is empty" << endl;
        node<T> *temp = head;
        int pos = 0, flag = 0;
        while (temp)
        {
            if (temp->data == val)
            {
                flag = 0;
                cout << "\nThe node is at " << pos + 1 << " position" << endl;
                break;
            }
            else
                flag = 1;
            pos++;
            temp = temp->next;
        }
        if (flag == 1)
            cout << "Element not found" << endl;
    }

    //function to print the nodes of the doubly linked list
    void print_ll()
    {
        //if the linked list is empty
        if (head == NULL)
        {
            cout << "The linked list is empty" << endl;
        }

        //if it has one or multiple nodes
        else
        {
            node<T> *temp = head;
            while (temp != NULL)
            {
                cout << temp->data;
                if (temp->next != NULL)
                    cout << "<=>";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    //function to print the nodes of the doubly linked list in reverse order
    void reverse_display()
    {
        //if the linked list is empty
        if (tail == NULL)
        {
            cout << "The linked list is empty" << endl;
        }
        //if it has one or multiple nodes
        else
        {
            node<T> *temp = tail;
            while (temp != NULL)
            {
                cout << temp->data;
                if (temp->prev != NULL)
                    cout << "<=>";
                temp = temp->prev;
            }
        }
    }
};

int main()
{
    //creating the object of the linkedlist,ll
    linkedlist<int> ll;

    //Taken this part of code from my friend, Shubham's github, skcshubham 
    int loopTime = 10;

    cout << "1: Create a linked list.\n2: Display the linked list.\n3: Insert a node at the beginning of the linked list.";
    cout << "\n4: Insert a node in the specific position of the linked list.\n5: Insert a node at the end of the linked list.";
    cout << "\n6: Delete a node from the beginning of the linked list.\n7: Delete the node from the specified position in the linked list.";
    cout << "\n8: Delete a node from the end of the linked list.\n9: Search a node in the linked list.";

    int option;
    while (loopTime)
    {
        cout << "Enter your Choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            --loopTime;
            int flag = 0;
            cout << "Type 0 to exit the linked list" << endl;
            cin >> flag;

            // creating linked list

            while (flag != 0)
            {
                ll.create_ll(flag);
                cin >> flag;
            }
            ll.print_ll();
            break;
        }

        case 2:
        {
            --loopTime;
            // displaying linked list

            ll.print_ll();

            break;
        }

        case 3:
        {
            --loopTime;
            // inserting at the beginning

            int value;
            cout << "\nEnter the value that you want to insert:  ";
            cin >> value;
            ll.insert_beg(value);
            ll.print_ll();

            break;
        }

        case 4:
        {
            --loopTime;
            // inserting at specific position

            int value1, position1;
            cout << "Enter the value that you want to insert: ";
            cin >> value1;
            cout << "\nEnter the position in which you want to insert: ";
            cin >> position1;

            ll.insert_pos(value1, position1);
            ll.print_ll();

            break;
        }

        case 5:
        {
            --loopTime;
            // inserting at the end

            int value2;
            cout << "\nEnter the value that you want to insert: ";
            cin >> value2;

            ll.insert_end(value2);
            ll.print_ll();

            break;
        }

        case 6:
        {
            --loopTime;
            // deleting the first node

            ll.delete_beg();
            ll.print_ll();

            break;
        }

        case 7:
        {
            --loopTime;
            // deleting the node at specified position

            int position2;
            cout << "\nEnter the position where you want to delete: ";
            cin >> position2;

            ll.delete_pos(position2);
            ll.print_ll();

            break;
        }

        case 8:
        {
            --loopTime;
            // deleting node from the end

            ll.delete_end();
            ll.print_ll();

            break;
        }

        case 9:
        {
            --loopTime;
            // searching a node in the linked list
            int num;
            cout << "\nEnter the value that you want to search: ";
            cin >> num;

            ll.search_ll(num);
            break;
        }

        default:
        {
            loopTime = 0;
            cout << "Wrong Choice !!";
        }

        } // end of switch
    }     // end of while loop

    // linkedlist <char> ll;
    // ll.print_ll();
    // ll.create_ll('u');
    // ll.create_ll('s');
    // ll.insert_beg('a');
    // ll.print_ll();
    // ll.insert_end('h');
    // ll.print_ll();
    // ll.insert_pos('n', 4);
    // ll.insert_pos('R', 0);
    // ll.insert_pos('a', 5);
    // ll.print_ll();
    // ll.delete_beg();
    // ll.delete_end();
    // ll.print_ll();
    // ll.delete_pos(0);
    // ll.delete_pos(4);
    // ll.print_ll();

    // ll.delete_pos(1);
    // ll.print_ll();

    return 0;
}
