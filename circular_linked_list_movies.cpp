#include <iostream>
using namespace std;

// Node structure for circular doubly linked list
struct node
{
    string movieName;
    int movieID;
    string duration;

    // Pointers for doubly linked list
    node* next;
    node* previous;

    // Default constructor
    node()
    {
        movieName = "";
        movieID = 0;
        duration = "";

        next = nullptr;
        previous = nullptr;
    }
};

// Circular doubly linked list implementation
struct circularLinkedList
{
    node* head;
    node* tail;

    // Constructor - initialize empty list
    circularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Add a new movie to the end of the list
    void addMovie(string name, int id, string time)
    {
        node* n = new node;
        n->movieName = name;
        n->movieID = id;
        n->duration = time;

        // If list is empty, set as first node
        if (!head)
        {
            head = n;
            tail = n;
            n->next = head;
            n->previous = head;
        }
        else
        {
            // Add to end and maintain circular structure
            tail->next = n;
            n->previous = tail;
            tail = n;
            tail->next = head;
            head->previous = tail;
        }
    }

    // Display all movies in forward direction (head to tail)
    void display()
    {
        cout << "Displaying" << endl << endl;

        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node* temp = head;

        // Traverse circular list using do-while
        do
        {
            cout << "Movie Name     :  " << temp->movieName << endl;
            cout << "Movie ID       :  " << temp->movieID << endl;
            cout << "Movie Duration :  " << temp->duration << endl;
            cout << endl;

            temp = temp->next;

        } while (temp != head);

        cout << endl << endl;
    }

    // Display all movies in backward direction (tail to head)
    void displayBackwards()
    {
        cout << "Displaying Backwards" << endl << endl;

        if (!tail)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node* temp = tail;

        // Traverse backwards using previous pointers
        do
        {
            cout << "Movie Name     :  " << temp->movieName << endl;
            cout << "Movie ID       :  " << temp->movieID << endl;
            cout << "Movie Duration :  " << temp->duration << endl;
            cout << endl;

            temp = temp->previous;
        } while (temp != tail);

        cout << endl << endl;
    }

    // Search for a movie by ID
    void search(int id)
    {
        node* temp = head;

        do
        {
            if (temp->movieID == id)
            {
                cout << "Movie Found" << endl;

                cout << "Movie Name     :  " << temp->movieName << endl;
                cout << "Movie ID       :  " << temp->movieID << endl;
                cout << "Movie Duration :  " << temp->duration << endl;

                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Movie Not Found" << endl;
    }

    // Delete a movie by ID
    void deleteMovie(int id)
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node* temp = head;

        do
        {
            if (temp->movieID == id)
            {
                // Case 1: Only one node in the list
                if (head == tail && head == temp)
                {
                    delete temp;
                    head = nullptr;
                    tail = nullptr;

                    cout << "Movie with ID " << id << " Deleted" << endl;
                    return;
                }

                // Case 2: Deleting the head node
                if (temp == head)
                {
                    head = head->next;
                    head->previous = tail;
                    tail->next = head;
                    delete temp;

                    cout << "Movie with ID " << id << " Deleted" << endl;
                    return;
                }

                // Case 3: Deleting the tail node
                if (temp == tail)
                {
                    tail = tail->previous;
                    tail->next = head;
                    head->previous = tail;
                    delete temp;

                    cout << "Movie with ID " << id << " Deleted" << endl;
                    return;
                }

                // Case 4: Deleting a middle node
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete temp;

                cout << "Movie with ID " << id << " Deleted" << endl;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Movie with ID " << id << " not found!" << endl;
    }

};

// Display menu options to user
void menu()
{
    cout << "==================================" << endl;
    cout << "     MOVIE MANAGEMENT SYSTEM      " << endl;
    cout << "==================================" << endl;
    cout << "1. Add Movie" << endl;
    cout << "2. Display Movies (Forward)" << endl;
    cout << "3. Display Movies (Backward)" << endl;
    cout << "4. Search Movie" << endl;
    cout << "5. Delete Movie" << endl;
    cout << "6. Exit" << endl << endl;
}

int main()
{
    circularLinkedList c1;  // Create movie list instance

    // Main program loop
    while (true)
    {
        menu();
        int choice;

        cout << "Choose Option : ";
        cin >> choice;

        // Process user choice
        switch (choice)
        {
        case 1:  // Add new movie
        {
            cout << "Enter Name of Movie : ";
            string x;
            cin >> x;

            cout << "Enter ID of Movie : ";
            int y;
            cin >> y;

            cout << "Enter Duration of Movie : ";
            string z;
            cin >> z;

            c1.addMovie(x, y, z);
            break;
        }

        case 2:  // Display forward
        {
            c1.display();
            break;
        }

        case 3:  // Display backward
        {
            c1.displayBackwards();
            break;
        }

        case 4:  // Search movie
        {
            cout << "Enter ID of Movie to Search : ";
            int y;
            cin >> y;
            c1.search(y);
            break;
        }

        case 5:  // Delete movie
        {
            cout << "Enter Movie Id to Delete : ";
            int y;
            cin >> y;
            c1.deleteMovie(y);
            break;
        }

        case 6:  // Exit program
        {
            cout << "Thank you for using Movie Management System!" << endl;
            return 0;  // Exit program
        }

        default:  // Invalid input
        {
            cout << "Choose Correct Option From the Menu" << endl;
        }
        }
    }

    return 0;
}
