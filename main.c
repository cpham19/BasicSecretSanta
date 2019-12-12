#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

int main(int argc, char** argv) {

    int num_of_people;
    printf("Please enter the number of people: ");
    scanf("%d", &num_of_people);
    int num = num_of_people;

    char *names_of_gifters[num_of_people];
    char *names_of_giftees[num_of_people];

    getUserInput(names_of_gifters, names_of_giftees, num_of_people);

    struct person *people = (struct person *) malloc(num_of_people * sizeof (struct person));

    for (int x = 0; x < num; x++) {
        int n_gifter = rand() % num_of_people;
        int n_giftee = rand() % num_of_people;
        //  if the gifter is not the same person as the giftee
        while (strcmp(names_of_gifters[n_gifter], names_of_giftees[n_giftee]) == 0) {
            n_giftee = rand() % num_of_people;
        }

        people[x].gifter_name = (char *) malloc(sizeof (names_of_gifters[n_gifter]) + 1);
        people[x].giftee_name = (char *) malloc(sizeof (names_of_giftees[n_giftee]) + 1);
        strcpy(people[x].gifter_name, names_of_gifters[n_gifter]);
        strcpy(people[x].giftee_name, names_of_giftees[n_giftee]);
        removeFromList(names_of_gifters, names_of_giftees, n_gifter, n_giftee, num_of_people);
        num_of_people--;
    }

    printf("\n");

    for (int x = 0; x < num; x++) {
        printf("%s gives something to %s\n", people[x].gifter_name, people[x].giftee_name);
    }
    
    return (EXIT_SUCCESS);
}

// User Input
void getUserInput(char **array, char **array2, int num) {
    for (int x = 0; x <  num; x++) {
        char name[100];
        printf("Enter Person #%d's name: ", x + 1);
        scanf("%s", name);
        array[x] = malloc(strlen(name) + 1);
        array2[x] = malloc(strlen(name) + 1);
        strcpy(array[x], name);
        strcpy(array2[x], name);
    }
}

void removeFromList(char **array_of_gifters, char **array_of_giftees, int num_of_gifter, int num_of_giftee, int number_of_people) {
    for (int i = num_of_gifter; i < number_of_people - 1; i++) {
        array_of_gifters[i] = array_of_gifters[i + 1];
    }

    for (int i = num_of_giftee; i < number_of_people - 1; i++) {
        array_of_giftees[i] = array_of_giftees[i + 1];
    }
}

