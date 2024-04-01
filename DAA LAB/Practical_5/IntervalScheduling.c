#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
struct Node
{
    char name[100];
    int startTime;
    int endTime;
    struct Node *next;
};

// Function to print the linked list
void Print(struct Node *list)
{
    while (list != NULL)
    {
        printf("Process Name: %s | Process Start Time: %d | Process End Time: %d\n", list->name, list->startTime, list->endTime);
        list = list->next;
    }
}

// Function to swap the contents of two nodes
void swap(struct Node *a, struct Node *b)
{
    // Temporary variables to store values during the swap
    char tempName[100];
    int tempStartTime;
    int tempEndTime;

    // Copy values from node a to temporary variables
    strcpy(tempName, a->name);
    tempStartTime = a->startTime;
    tempEndTime = a->endTime;

    // Copy values from node b to node a
    strcpy(a->name, b->name);
    a->startTime = b->startTime;
    a->endTime = b->endTime;

    // Copy values from temporary variables to node b
    strcpy(b->name, tempName);
    b->startTime = tempStartTime;
    b->endTime = tempEndTime;
}

// Function to perform bubble sort on the linked list based on end time
void bubbleSort(struct Node *start)




{
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    // Create a copy of the list for sorting
    struct Node *copy = NULL;
    struct Node *current = start;

    // Copy the elements to the new list in reverse order
    while (current != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->name, current->name);
        newNode->startTime = current->startTime;
        newNode->endTime = current->endTime;
        newNode->next = copy;
        copy = newNode;

        current = current->next;
    }

    if (copy == NULL)
        return;

    // Perform bubble sort on the copied list
    do
    {
        swapped = 0;
        ptr1 = copy;

        while (ptr1->next != lptr)
        {
            if (ptr1->endTime > ptr1->next->endTime)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    // Copy the sorted list back to the original list
    current = start;
    ptr1 = copy;

    while (current != NULL && ptr1 != NULL)
    {
        strcpy(current->name, ptr1->name);
        current->startTime = ptr1->startTime;
        current->endTime = ptr1->endTime;

        current = current->next;
        ptr1 = ptr1->next;
    }

    // Free memory for the sorted copy
    while (copy != NULL)
    {
        struct Node *temp = copy;
        copy = copy->next;
        free(temp);
    }
}

// Function to perform interval scheduling on the linked list
struct Node *intervalScheduling(struct Node *list)
{
    struct Node *scheduledList = NULL;
    struct Node *current = list;
    struct Node *lastScheduled = NULL;

    // Iterate through the original list
    while (current != NULL)
    {
        // Check if the current process can be scheduled
        if (lastScheduled == NULL || current->startTime >= lastScheduled->endTime)
        {
            // Create a new node for the scheduled list
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            strcpy(newNode->name, current->name);
            newNode->startTime = current->startTime;
            newNode->endTime = current->endTime;
            newNode->next = NULL;

            // Update the scheduled list and the last scheduled node
            if (scheduledList == NULL)
            {
                scheduledList = newNode;
                lastScheduled = newNode;
            }
            else
            {
                lastScheduled->next = newNode;
                lastScheduled = newNode;
            }
        }

        current = current->next;
    }

    return scheduledList;
}

int main()
{
    // Initialize variables
    int num, start, end;
    char name[100];
    struct Node *head = NULL;

    // Get the number of processes from the user
    printf("Enter the total number of Processes:");
    scanf("%d", &num);

    // Input details for each process and create nodes in the linked list
    for (int i = 0; i < num; i++)
    {
        printf("Enter the Name of the Process: ");
        scanf("%s", name);
        printf("Enter the Start Time of the Process: ");
        scanf("%d", &start);
        printf("Enter the End Time of the Process: ");
        scanf("%d", &end);

        // Create a new node and add it to the beginning of the linked list
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->name, name);
        newNode->startTime = start;
        newNode->endTime = end;
        newNode->next = head;
        head = newNode;
    }

    // Display the original linked list
    printf("Original Linked List: \n");
    Print(head);

    // Sort the list using bubbleSort without modifying the original list
    bubbleSort(head);

    // Display the sorted linked list
    printf("Sorted Linked List: \n");
    Print(head);

    // Perform interval scheduling and display the scheduled linked list
    struct Node *scheduledList = intervalScheduling(head);
    printf("Scheduled Linked List: \n");
    Print(scheduledList);

    // Free allocated memory for the linked lists
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    while (scheduledList != NULL)
    {
        struct Node *temp = scheduledList;
        scheduledList = scheduledList->next;
        free(temp);
    }

    return 0;
}
