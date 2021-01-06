
//Circular doubly linked list using template class - generic programming
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
    //initializing the head pointer
    node<T> *head;

public:
    //using constructor to assigning head to NULL
    linkedlist()
    {
        head = NULL;
    }

    // function to get the size of the Circular doubly linked list
    int size()
    {
        node<T> *temp = head;
        int s = 0;
        do
        {
            temp = temp->next;
            s++;
        } while (temp != head);
        return s;
    }

    //function to create the Circular doubly linked list
    node<T> *create_ll(T val)
    {
        node<T> *temp = new node<T>();
        node<T> *p = head;
        temp->data = val;

        if (head == NULL)
        {
            head = temp;
            head->next = head->prev = head;
        }
        // if it has one or multiple nodes
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->prev = p;
            temp->next = head;
            head->prev = temp;
        }
        return head;
    }

    //function to insert a node at the beginning of the Circular doubly linked list
    void insert_beg(T val)
    {
        node<T> *temp = new node<T>();
        node<T> *p = head;
        temp->data = val;

        //if the linked list is empty
        if (head == NULL)
        {
            head = temp;
            head->next = head->prev = head;
        }

        //if it has one or multiple nodes
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->prev = p;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    //function to insert a node at the end of the Circular doubly linked list
    void insert_end(T val)
    {
        node<T> *temp = new node<T>();
        node<T> *p = head;
        temp->data = val;
        //if the linked list is empty
        if (head == NULL)
        {
            head = temp;
            head->next = head->prev = head;
        }
        //if it has one or multiple nodes
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->prev = p;
            temp->next = head;
            head->prev = temp;
        }
    }

    //function to insert a node at the given position in the Circular doubly linked list
    void insert_pos(T val, int pos)
    {
        node<T> *temp = new node<T>();
        node<T> *p = head;
        temp->data = val;
        //if the linked list is empty
        if (head == NULL)
        {
            head = temp;
            head->next = head->prev = head;
        }
        //if the given position is equal to zero
        if (pos == 0)
            insert_beg(val);

        //if the given position is equal to size of the linked list
        else if (pos == size())
            insert_end(val);

        //if the position is less than the size of the linked list
        else if (pos < size())
        {
            int i = 0;
            while (i != pos - 1)
            {
                p = p->next;
                i++;
            }
            temp->next = p->next;
            p->next->prev = temp;
            p->next = temp;
            temp->prev = p;
        }
        else
        {
            cout << "\nthe position does not exist";
        }
    }

    //function to delete a node from the beginning of the Circular doubly linked list
    void delete_beg()
    {
        node<T> *temp = head;
        //if the linked list is empty
        if (head == NULL)
        {
            "There is no elements in linked list to delete!!";
        }
        //if the linked list has only one node
        else if (head->next == head)
        {
            head = NULL;
            free(head);
        }
        //if the linked list has multiple nodes
        else
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            head->next->prev = temp;
            free(head);
            head = temp->next;
        }
    }

    //function to delete a node from the ending of the Circular doubly linked list
    void delete_end()
    {
        node<T> *temp = head;
        //if the linked list is empty
        if (head == NULL)
        {
            "There is no elements in linked list to delete!!";
        }
        //if the linked list has only one node
        else if (temp->next == head)
        {
            head = NULL;
            free(head);
        }
        //if the linked list has multiple nodes
        else
        {
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            node<T> *p = temp->next;
            temp->next = p->next;
            temp->prev = temp;
            free(p);
        }
    }

    //function to delete a node from the given position of the Circular doubly linked list
    void delete_pos(int pos)
    {
        node<T> *temp = head;
        //if the linked list is empty
        if (head == NULL)
        {
            "There is no elements in linked list to delete!!";
        }
        //if it has only one nodes
        else if (temp->next == head)
        {
            head = NULL;
            free(head);
        }
        //if the given position is equal to zero
        else if (pos == 0)
            delete_beg();

        //if the given position is equal to size of the linked list
        else if (pos == size())
            delete_end();
        //if the position is less than the size of the linked list
        else if (pos < size())
        {
            int i = 0;
            node<T> *p;
            while (i != pos - 1)
            {
                temp = temp->next;
                i++;
            }
            p = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            free(p);
        }
    }

    //function to print the nodes of the Circular doubly linked list
    void print_ll()
    {
        //if the linked list is empty
        if (head == NULL)
            cout << "\nThe linkedlist is empty";

        //if it has one or multiple nodes
        else
        {
            node<T> *temp = head;
            do
            {
                cout << temp->data;
                if (temp->next != head)
                    cout << "<=>";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
};

int main()
{
    //creating the object of  the linkedlist,ll
    linkedlist<int> ll;

    //Taken this part of code from my friend, Shubham's github repository, skcshubham
    int loopTime = 10;

    cout << "1: Create a linked list.\n2: Display the linked list.\n3: Insert a node at the beginning of the linked list.";
    cout << "\n4: Insert a node in the specific position of the linked list.\n5: Insert a node at the end of the linked list.";
    cout << "\n6: Delete a node from the beginning of the linked list.\n7: Delete the node from the specified position in the linked list.";
    cout << "\n8: Delete a node from the end of the linked list.";

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