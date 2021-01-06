//Circular singly linked list using template class - generic programming

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
    //initializing the head pointer
    node<T> *head;

public:
    //using constructor to assigning head to NULL
    linkedlist()
    {
        head = NULL;
    }

// function to get the size of the Circular singly linked list
    int size()
    {
        node<T> *temp = head;
        T count = 0;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        return count + 1;
    }

//function to create the Circular singly linked list
    node<T> *create_ll(T val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;
        temp->next = NULL;
        // if the linked list is empty
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }

        // if it has one or multiple nodes
        else
        {
            node<T> *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
        }
        return head;
    }

//function to print the nodes of the Circular singly linked list
    void print_ll()
    {
        //if the linked list is empty
        if (head == NULL)
            cout << "\nThe linked list is empty" << endl;
        
        //if it has one or multiple nodes 
        else
        {
            node<T> *temp = head;
            do
            {
                cout << temp->data;
                if (temp->next != head)
                    cout << " -> ";
                temp = temp->next;
            } while (temp != head);

            cout << endl;
        }
    }

//function to insert a node at the beginning of the Circular singly linked list
    void insert_beg(T val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;

        //if the linked list is empty
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }

        //if it has one or multiple nodes
        else
        {
            node<T> *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
            head = temp;
        }
    }

//function to insert a node at the end of the Circular singly linked list
    void insert_end(T val)
    {
        node<T> *temp = new node<T>();
        temp->data = val;

        //if the linked list is empty
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }

        //if it has one or multiple nodes
        else
        {
            node<T> *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
        }
    }

//function to insert a node at the given position in the Circular singly linked list
    void insert_pos(T val, int pos)
    {
        node<T> *temp = new node<T>();
        temp->data = val;
        //if the linked list is empty
        if (head == NULL)
        {
            cout << "The linkedlist is empty\n";
        }

        //if the given position is equal to zero
        else if (pos == 0)
        {
            insert_beg(val);
        }

        //if the position is less than the size of the linked list
        else if (pos < size())
        {
            node<T> *p = head;
            T i = 0;
            while (i != pos - 1)
            {
                p = p->next;
                i++;
            }
            temp->next = p->next;
            p->next = temp;
        }

        //if the given position is equal to size of the linked list
        else if (pos == size())
            insert_end(val);

        else
        {
            cout << "position not found";
        }
    }

//function to delete a node from the beginning of the Circular singly linked list
    void delete_beg()
    {
        //if the linked list is empty
        if (head == NULL)
            cout << "\nThere is no nodes in linked list to delete!!" << endl;
        
        //if the linked list has one or multiple nodes
        else
        {
            node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }

            free(temp->next);
            temp->next = temp->next->next;
            head = temp->next;
        }
    }

//function to delete a node from the ending of the Circular singly linked list
    void delete_end()
    {
        //if the linked list is empty
        if (head == NULL)
            cout << "\nThere is no nodes in linked list to delete!!" << endl;

        //if the linked list has one or multiple nodes
        else
        {
            node<T> *temp = head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }

            free(temp->next);
            temp->next = temp->next->next;
        }
    }

//function to delete a node from the given position of the Circular singly linked list
    void delete_pos(int pos)
    {
        node<T> *temp = head;

         //if the linked list is empty
        if (head == NULL)
            cout << "\nThere is no nodes in linked list to delete!!" << endl;

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
            while (i != pos - 1)
            {
                temp = temp->next;
                i++;
            }
            free(temp->next);
            temp->next = temp->next->next;
        }

        else
            cout << "\nposition not found!!";
    }

//function to search a node in the Circular singly linked list
    void search_ll(T val)
    {
        //if the linked list is  empty
        if (head == NULL)
            cout << "There is no nodes in the linked list to search over!!" << endl;

        else
        {
            node<T> *temp = head;
            T pos = 0, flag = 0;
            while (temp->next != head)
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