#include "iostream" // Include the iostream library for input and output operations

// Define a structure for the nodes of the queue
struct node {
    int data; // Data part of the node
    struct node *next; // Pointer to the next node in the queue
};

// Initialize frontIndex and rearIndex to NULL, representing the front and rear of the queue
struct node* frontIndex = NULL;
struct node* rearIndex = NULL;
struct node* temp; // Temporary pointer used for various operations

// Function to insert an element into the queue
void Insert() {
    int value; // Variable to store the value to be inserted
    std::cout << "Insert element into queue: " << std::endl;
    std::cin >> value; // Take input from the user

    // Check if the queue is empty (rearIndex is NULL)
    if (rearIndex == NULL) {
        // Allocate memory for a new node and assign it to rearIndex
        rearIndex = (struct node *) malloc(sizeof(struct node));
        rearIndex->next = NULL; // Set the next pointer of the new node to NULL
        rearIndex->data = value; // Set the data of the new node to the input value
        frontIndex = rearIndex; // Set frontIndex to point to the same node as rearIndex (since it's the only node)
    } else {
        // If the queue is not empty, allocate memory for a new node
        temp = (struct node *) malloc(sizeof(struct node));
        rearIndex->next = temp; // Link the new node to the end of the queue
        temp->data = value; // Set the data of the new node to the input value
        temp->next = NULL; // Set the next pointer of the new node to NULL
        rearIndex = temp; // Update rearIndex to point to the new node
    }
}

// Function to delete an element from the queue
void Delete() {
    temp = frontIndex; // Set temp to the front of the queue

    // Check if the queue is empty (frontIndex is NULL)
    if (frontIndex == NULL) {
        std::cout << "Underflow" << std::endl; // Print underflow message if the queue is empty
        return;
    } else {
        // If there is more than one node in the queue
        if (temp->next != NULL) {
            temp = temp->next; // Move temp to the next node
            std::cout << "Element deleted from queue is: " << frontIndex->data << std::endl;
            free(frontIndex); // Free the memory of the old front node
            frontIndex = temp; // Update frontIndex to point to the next node
        } else {
            // If there is only one node in the queue
            std::cout << "Element deleted from queue is: " << frontIndex->data << std::endl;
            free(frontIndex); // Free the memory of the front node
            frontIndex = NULL; // Set frontIndex to NULL as the queue is now empty
            rearIndex = NULL; // Set rearIndex to NULL as the queue is now empty
        }
    }
}

// Function to display all elements in the queue
void Display() {
    temp = frontIndex; // Start from the front of the queue

    // Check if the queue is empty
    if ((frontIndex == NULL) && (rearIndex == NULL)) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    std::cout << "Queue elements are: ";
    while (temp != NULL) { // Traverse the queue until the end
        std::cout << temp->data << " "; // Print the data of each node
        temp = temp->next; // Move to the next node
    }
    std::cout << std::endl;
}

// Main function to demonstrate the queue operations
int main() {
    int choice; // Variable to store user's menu choice

    // Display menu options to the user
    std::cout << "1) Insert element into queue\n"
                 "2) Delete element from queue\n"
                 "3) Display all the elements of queue\n"
                 "4) Exit" << std::endl;

    // Loop until the user chooses to exit
    do {
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> choice; // Get the user's choice

        // Perform action based on user's choice
        switch (choice) {
            case 1: Insert(); // Call Insert function to add an element to the queue
                break;
            case 2: Delete(); // Call Delete function to remove an element from the queue
                break;
            case 3: Display(); // Call Display function to show all elements in the queue
                break;
            case 4: std::cout << "Exit" << std::endl; // Exit the loop and program
                break;
            default: std::cout << "Invalid choice" << std::endl; // Handle invalid input
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0; // Return 0 to indicate successful program execution
}
