//Singly linked list using template class - generic programming

#include <bits/stdc++.h>
using namespace std;

template <class T>
//creating struct node with data and two pointers, next and prev
struct node
{
    T data;
    node<T> *next;
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

    // function to get the size of the Circular singly linked list
    int size()
    {
        node<T> *temp = new node<T>();
        temp = head;
        int s = 0;
        while (temp != NULL)
        {
            ++s;
            temp = temp->next;
        }
        return s;
    }

    //function to create the singly linked list
    node<T> *create_ll(int val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;
        temp->next = NULL;
        // if the linked list is empty
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        //if it has one or multiple nodes
        else
        {
            tail->next = temp;
            tail = temp;
        }
        return head;
    }

    //function to print the nodes of the singly linked list
    void print_ll()
    {
        // if the linked list is empty
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
                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }
            cout << endl;
        }
    }

    //function to insert a node at the beginning of the singly linked list
    void insert_beg(T val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;

        // if the linked list is empty
        if (head == NULL)
        {
            temp->next = NULL;
            tail = temp;
        }

        //if it has one or multiple nodes
        else
        {
            temp->next = head;
        }

        head = temp;
    }

    //function to insert a node at the end of the singly linked list
    void insert_end(T val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;
        temp->next = NULL;

        // if the linked list is empty
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }

        //if it has one or multiple nodes
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    //function to insert a node at the given position in the singly linked list
    void insert_pos(T val, int pos)
    {
        node<T> *temp = new node<T>();
        temp->data = val;
        node<T> *p = head;

        // if the linked list is empty
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
            p->next = temp;
        }

        else
            cout << "\n Position not found" << endl;
    }

    //function to delete a node from the beginning of the singly linked list
    void delete_beg()
    {
        // if the linked list is empty
        if (head == NULL)
            cout << "The linked list is empty" << endl;

        //if it has one or multiple nodes
        else
        {
            node<T> *temp = head;
            head = head->next;
            free(temp);
        }
    }

    //function to delete a node from the ending of the singly linked list
    void delete_end()
    {
        // if the linked list is empty
        if (head == NULL)
            cout << "The linked list is empty" << endl;

        //if it has one nodes
        else if (head == tail)
        {
            node<T> *temp = head;
            head = NULL;
            tail = NULL;
            free(temp);
        }

        //if it has multiple nodes
        else
        {
            node<T> *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            tail = temp;
            free(temp->next);
            temp->next = NULL;
        }
    }

    //function to delete a node from the given position of the singly linked list
    void delete_pos(int pos)
    {
        node<T> *temp = head;

        // if the linked list is empty
        if (head == NULL)
            cout << "The linked list is empty" << endl;

        //if the given position is equal to zero
        else if (pos == 0)
        {
            delete_beg();
        }

        //if the given position is equal to size of the linked list
        else if (pos == size())
        {
            delete_end();
        }

        // if it has multiple nodes
        else if (pos < size())
        {
            int i = 0;
            while (i != pos - 1)
            {
                temp = temp->next;
                i++;
            }
            node<T> *next = temp->next->next;
            free(temp->next);
            temp->next = next;
        }

        else
            cout << "\nPosition not found";
    }

    //function to search a node in the singly linked list
    void search_ll(int val)
    {
        // if the linked list is empty
        if (head == NULL)
            cout << "The linked list is empty" << endl;

        // if it has one or multiple nodes
        else
        {
            node<T> *temp = head;
            int pos = 0, flag = 0;
            while (temp)
            {
                if (temp->data == val)
                {
                    flag = 0;
                    cout << "The node is at " << pos + 1 << " position" << endl;
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

    // linkedlist<char> ll;
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
