#include <stdio.h>
using namespace std;
#define MAX 100

struct Student
{
    char name[50];
    float cgpa;
};

struct Student pq[MAX];
int size = 0;
int processed = 0;

void insert()
{
    if (size == MAX)
    {
        printf("Priority Queue is full!\n");
        return;
    }

    struct Student s;
    int i;

    printf("Enter student name: ");
    scanf("%49s", s.name);

    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);

    i = size - 1;

    while (i >= 0 && pq[i].cgpa < s.cgpa)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = s;
    size++;

    printf("Student inserted successfully.\n");
}

void deleteHighest()
{
    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Deleted student: %s (CGPA: %.2f)\n",
           pq[0].name, pq[0].cgpa);

    for (int i = 0; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
    processed++;
}

void display()
{
    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nPriority Queue (Highest CGPA first):\n");
    printf("-----------------------------------\n");
    printf("Name\tCGPA\n");

    for (int i = 0; i < size; i++)
    {
        printf("%s\t%.2f\n", pq[i].name, pq[i].cgpa);
    }

    printf("-----------------------------------\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert Student\n");
        printf("2. Delete Highest CGPA Student\n");
        printf("3. Display Queue\n");
        printf("4. Count Students Processed\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                display();
                break;

            case 2:
                deleteHighest();
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Students processed: %d\n", processed);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
