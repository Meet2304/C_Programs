#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Node
{
    char City[100];
    int X_Coordinate;
    int Y_Coordinate;
    struct Node* Next;
};

void Print( struct Node* list)
{
    while(list != NULL)
    {
        printf("City Name: %s\n", list->City);
        printf("X Coordinate: %d\n", list->X_Coordinate);
        printf("Y Coordinate: %d\n", list->Y_Coordinate);
        list = list->Next;
    }
}

void Insert(struct Node** Start, char c[100], int x, int y )
{
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(NewNode->City, c);
    NewNode->X_Coordinate = x;
    NewNode->Y_Coordinate = y;
    NewNode->Next = *Start;
    *Start = NewNode;
}

void SearchCity(struct Node* list, char c[100])
{
    while(list!=NULL)
    {
        if(strcmp(list->City, c) == 0)
        {
            printf("City Name: %s\n", list->City);
            printf("X Coordinate: %d\n", list->X_Coordinate);
            printf("Y Coordinate: %d\n", list->Y_Coordinate);
        }
        list = list->Next;
    }
}

void SearchCoord(struct Node* list, int x, int y)
{
    while(list!=NULL)
    {
        if(list->X_Coordinate==x && list->Y_Coordinate==y)
        {
            printf("City Name: %s\n", list->City);
            printf("X Coordinate: %d\n", list->X_Coordinate);
            printf("Y Coordinate: %d\n", list->Y_Coordinate);
        }
        list = list->Next;
    }
}

void DeleteCity(struct Node* list, char c[100])
{
    struct Node* current = list;
    struct Node* prev = NULL;

    //struct Node* current2 = current->Next;
    while(current!= NULL)
    {
        if(strcmp(current->City, c)==0)
        {
            // If the node to be deleted is the first node
            if (prev == NULL)
            {
                list = current->Next;
            }
            else
            {
                // Update the Next pointer of the previous node to skip the target node
                prev->Next = current->Next;
            }
            printf("Value Deletion Successful!\n");
        }
        prev = current;
        current = current->Next;
    }
}

void DeleteCoord(struct Node** list, int x, int y)
{
    struct Node* current = *list;
    struct Node* prev = NULL;

    while(current!= NULL)
    {
        if(current->X_Coordinate==x && current->Y_Coordinate==y)
        {
            // If the node to be deleted is the first node
            if (prev == NULL)
            {
                *list = current->Next;
            }
            else
            {
                // Update the Next pointer of the previous node to skip the target node
                prev->Next = current->Next;
            }
            printf("Value Deletion Successful!\n");
            free(current);
            return;
        }
        prev = current;
        current = current->Next;
    }
}

void RecordsatDist(struct Node* list, int distx, int disty, int dist)
{
    while(list!=NULL)
    {
        int distance = sqrt(pow((list->X_Coordinate - distx), 2) + pow((list->Y_Coordinate - disty), 2));
        if(distance<=dist)
        {
            printf("City Name:%s | X:%d | Y:%d\n", list->City, list->X_Coordinate, list->Y_Coordinate);
        }
        list = list->Next;
    }
}

void main()
{
    int num;
    //Initializing Database linked list
    struct Node* Database = NULL;
    // Take input of the number of entries
    printf("Enter the number of entries in database: ");
    scanf("%d", &num);

    getchar();

    // Loop for inserting data

    for(int i=0; i<num; i++)
    {
        char city[100];
        int x, y;
        printf("%dth ENTRY: \n", i+1);
        printf("Enter the City: ");
        scanf("%s", city);
        printf("Enter the X coordinate: ");
        scanf("%d", &x);
        printf("Enter the Y coordinate: ");
        scanf("%d", &y);
        Insert(&Database, city, x, y);
    }

    // Printing the liked list
    printf("Linked List: \n");
    Print(Database);

    // Searching a City by String
    char searchCity[100];
    printf("Enter the name of the city to be searched: ");
    scanf("%s", searchCity);
    SearchCity(Database, searchCity);

    // Searching a City by Coordinate
    int searchx, searchy;
    printf("Enter the X Coordinate of the city to be searched: ");
    scanf("%d", &searchx);
    printf("Enter the Y Coordinate of the city to be searched: ");
    scanf("%d", &searchy);
    SearchCoord(Database, searchx, searchy);

    // Deleting an entry by City Name
    char Del[100];
    printf("Enter the name of the city to be deleted: ");
    scanf("%s", Del);
    DeleteCity(Database, Del);

    // Deleting a City by Coordinate
    int delx, dely;
    printf("Enter the X Coordinate of the city to be deleted: ");
    scanf("%d", &delx);
    printf("Enter the Y Coordinate of the city to be deleted: ");
    scanf("%d", &dely);
    DeleteCoord(&Database, delx, dely);

    // Records from a given point
    int distx, disty, dist;
    printf("Enter the X coordinate of the point: ");
    scanf("%d", &distx);
    printf("Enter the Y coordinate of the point: ");
    scanf("%d", &disty);
    printf("Enter the distance from the point: ");
    scanf("%d", &dist);
    RecordsatDist(Database, distx, disty, dist);
}
