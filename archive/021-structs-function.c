/*
 * 1. create a patient struct.
 * 2. create a function patient struct sort.
 *
 *
 */

#include <stdio.h>

typedef struct 
{
    char *name;
    int age;
    double weight;
} patient_t;

//void sort_patients(

void printPatients(patient_t patients[], int numPatients);

int main()
{
    patient_t patients[] = {
        { "fred", 27, 80 },
        { "alice", 28, 81 },
        { "bob", 26, 82 },
    };

    int numPatients = sizeof(patients)/sizeof(patients[0]);

    printPatients(patients, numPatients);

    return 0;
}

void printPatients(patient_t patients[], int numPatients)
{
    int i;

    printf("number of patients: %d\n", numPatients);

    for (i = 0; i < numPatients; i++)
    {
        printf("name: %s\t\tage: %d\t\tweight: %.0lf\n", patients[i].name, patients[i].age, patients[i].weight);
    }
}
