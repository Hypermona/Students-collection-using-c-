// Q=> Display the N number of students details using structure get number of students dynamically[using pointers mandatory].
// Answer using pointers and memory allocated dynamically;
#include <stdio.h>
#include <stdlib.h>
typedef struct Student
{
    int rollNumber;
    char name[30];
} student;

int main()
{
    student *stu;
    int size;
    printf("Enter the number of Student\n");
    scanf("%d", &size);
    stu = (student *)malloc(size * sizeof(student));
    printf("Enter the details of %d students.\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter Roll Number and Name\n");
        scanf("%d *[^\n]", &(stu + i)->rollNumber); // or use fseek(stdin,0,SEEK_END);
        fgets((stu + i)->name, sizeof((stu + i)->name), stdin);
    }
    printf("Entered details\n");
    for (int i = 0; i < size; i++)
    {
        printf("Entered Roll Number = %d and Name = %s \n", (stu + i)->rollNumber, (stu + i)->name);
    }
    printf("Do You want to add more students!\n\t1)Yess!!!!\n\t2)NOO:(\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 2)
    {
        free(stu);
        printf("*************************THNKS FOR USING*************************************");
        exit(0);
    }
    else
    {
        int newSize;
        printf("Enter the number of Student\n");
        scanf("%d", &newSize);
        stu = realloc(stu, newSize);
        printf("Enter the details of %d students.\n", size);
        for (int i = 0; i < size; i++)
        {
            printf("Enter Roll Number and Name\n");
            scanf("%d *[^\n]", &(stu + i)->rollNumber); // or use fseek(stdin,0,SEEK_END);
            fgets((stu + i)->name, sizeof((stu + i)->name), stdin);
        }
        printf("Entered details\n");
        for (int i = 0; i < size; i++)
        {
            printf("Entered Roll Number = %d and Name = %s \n", (stu + i)->rollNumber, (stu + i)->name);
        }
    }
    printf("*************************THNKS FOR USING*************************************");
    free(stu);
    return 0;
}