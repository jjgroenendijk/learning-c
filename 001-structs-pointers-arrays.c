/*
    Practice assignment.

    Create a program that reads in data for a group of students and stores it in an array of structs.
    Each struct should represent a student and have the following fields:

        Name (a string of up to 50 characters)
        ID (an integer)
        Scores (an array of 5 integers)

    Your program should prompt the user to enter the number of students, allocate memory for the array of structs dynamically using malloc, and then prompt the user to enter the data for each student.

    Once all the data has been entered, your program should calculate and display the average score for each student,
    as well as the class average for each test.
*/

#include <stdio.h>
#include <stdlib.h> // Used for malloc()
#include <string.h> // Used for strcpy()

typedef struct
{
    char *studentName;
    int studentID;
    int scores[5];
} student_t;

void promptAmountStudents(int *amountStudents);

int main()
{
    // Prompt for the amount of students
    int amountStudents;
    promptAmountStudents(&amountStudents);

    // create an array of student structs
    student_t *students = (student_t *)malloc(amountStudents * sizeof(student_t));

    if (students != NULL)
    {

        // Prompt to enter student data
        int i;
        for (i = 0; i < amountStudents; i++)
        {
            // Allocate memory for student name
            students[i].studentName = (char *)malloc(100 * sizeof(char));

            if (students[i].studentName != NULL)
            {
                // prompt for student name
                printf("Enter student name (%03d):", (i + 1));
                scanf("%s", students[i].studentName);

                // prompt for student ID
                printf("Enter student ID (%03d):", (i + 1));
                scanf("%d", &students[i].studentID);

                // prompt for student grades
                int gradesAmount = sizeof(students[i].scores) / sizeof(students[i].scores[0]);
                int y;
                for (y = 0; y < gradesAmount; y++)
                {
                    printf("Enter grade %02d for student %02d:", (y + 1), (i + 1));
                    scanf("%d", &students[i].scores[y]);
                }
            }
        }

        // Print all student data
        for (i = 0; i < amountStudents; i++)
        {
            int averageScore = 0;
            int tmp = 0;
            int arraySize = (sizeof(students[i].scores) / sizeof(students[i].scores[0]));

            // Add everything in array to tmp
            for (int x = 0; x < arraySize; x++)
            {
                tmp += students[i].scores[x];
            }

            // Divide total sum of array by amount of array indexes.
            averageScore = tmp / arraySize;

            // Print student data
            printf("student counter: %02d\tstudent ID: %03d\tstudent name: %s\tavg score: %02d\n", (i + 1), students[i].studentID, students[i].studentName, averageScore);
        }

        // Free allocated memory
        for (i = 0; i < amountStudents; i++)
        {
            free(students[i].studentName);
        }
        free(students);
    }
    // All is well if we've come this far
    return 0;
}

void promptAmountStudents(int *amountStudents)
{
    printf("Please enter the amount of students:");
    scanf("%d", amountStudents);
}