#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<Math.h>

struct Data
{
    char city[100];
    int Xcoor;
    int Ycoor;
};

void Print(struct Data database[], int num)
{
    printf("CITY DATABASE:\n");
    for(int i=0; i<num; i++)
    {
        printf("ENTRY %d \n", i+1);
        printf("City Name: %s | City X Coordinate: %d | City Y Coordinate: %d\n", database[i].city, database[i].Xcoor, database[i].Ycoor);
    }
}

struct Data Database[100];

//Function to Insert an Entry in Database:
void Insert(struct Data database[],int *num, char name[], int x, int y)
{
    strcpy(database[*num].city, name);
    database[*num].Xcoor = x;
    database[*num].Ycoor = y;
    printf("New entry successfully added!\n");
    (*num)++;
}

//Function to Search an Entry by City Name
void SearchName(struct Data database[], int num, char name[])
{
    for(int i=0;i<num;i++)
    {
        if(strcmp(database[i].city, name) == 0)
        {
            printf("City Name: %s | City X Coordinate: %d | City Y Coordinate: %d\n", database[i].city, database[i].Xcoor, database[i].Ycoor);
        }
    }
}

//Function to Search an Entry by City Coordinates
void SearchCoord(struct Data database[], int num, int x, int y)
{
    for(int i=0;i<num;i++)
    {
        if(database[i].Xcoor == x && database[i].Ycoor == y)
        {
            printf("City Name: %s | City X Coordinate: %d | City Y Coordinate: %d\n", database[i].city, database[i].Xcoor, database[i].Ycoor);
        }
    }
}

//Function to Delete an Entry by City Name
void DeleteName(struct Data database[], int *num, char name[])
{
    for(int i=0;i<*num;i++)
    {
        if(strcmp(database[i].city, name) == 0)
        {
            database[i] = database[i+1];
            (*num)--;
            printf("Entry Deletion Successful!\n");
            return;
        }
    }
    printf("Entry not found");
}

//Function to Delete an Entry by City Coordinates
void DeleteCoord(struct Data database[], int *num, int x, int y)
{
    for(int i=0;i<*num;i++)
    {
        if(database[i].Xcoor == x && database[i].Ycoor == y)
        {
            database[i] = database[i+1];
            (*num)--;
            printf("Entry Deletion Successful!\n");
            return;
        }
    }
    printf("Entry not found");

}

//Function to Return Entries with a certain range of a given point
void RecordsatDist(struct Data database[], int num, int distx, int disty, int dist)
{
    for(int i=0; i<num; i++)
    {
        int distance = sqrt(pow((database[i].Xcoor - distx), 2) + pow((database[i].Ycoor - disty), 2));
        if(distance<=dist)
        {
            printf("City Name: %s | City X Coordinate: %d | City Y Coordinate: %d\n", database[i].city, database[i].Xcoor, database[i].Ycoor);
        }
    }
}

void main()
{
    int  num;
    char searchcity[100];
    int searchx, searchy;
    printf("Enter the total number of entries in Database: ");
    scanf("%d", &num);
    for(int i=0; i<num; i++)
    {
        printf("ENTRY %d \n", i+1);
        printf("Enter the name of the City:");
        scanf("%s", Database[i].city);
        printf("Enter the X Coordinate of the city: ");
        scanf("%d", &Database[i].Xcoor);
        printf("Enter the Y Coordinate of the city: ");
        scanf("%d", &Database[i].Ycoor);
    }
    Print(Database, num);

    // Entering a new record
    char newname[100];
    int newx, newy;
    printf("Enter the name of the new city: ");
    scanf("%s", newname);
    printf("Enter the X Coordinate of the new city: ");
    scanf("%d", &newx);
    printf("Enter the Y Coordinate of the new city: ");
    scanf("%d", &newy);
    Insert(Database, &num, newname, newx, newy);


    // Searching by City Name
    printf("Enter the name of the city to be searched: ");
    scanf("%s", searchcity);
    SearchName(Database, num, searchcity);

    // Searching by City Coordinate
    printf("Enter the X Coordinate of the city to be searched: ");
    scanf("%d", &searchx);
    printf("Enter the Y Coordinate of the city to be searched: ");
    scanf("%d", &searchy);
    SearchCoord(Database, num, searchx, searchy);

    // Deleting by City Name
    char Del[100];
    printf("Enter the name of the city to be deleted: ");
    scanf("%s", Del);
    DeleteName(Database, &num, Del);
    Print(Database, num);

    // Deleting by City Coordinate
    int delx, dely;
    printf("Enter the X Coordinate of the city to be deleted: ");
    scanf("%d", &delx);
    printf("Enter the Y Coordinate of the city to be deleted: ");
    scanf("%d", &dely);
    DeleteCoord(Database, &num, delx, dely);
    Print(Database, num);

    // Records from a given point
    int distx, disty, dist;
    printf("Enter the X coordinate of the point: ");
    scanf("%d", &distx);
    printf("Enter the Y coordinate of the point: ");
    scanf("%d", &disty);
    printf("Enter the distance from the point: ");
    scanf("%d", &dist);
    RecordsatDist(Database, num, distx, disty, dist);

}
