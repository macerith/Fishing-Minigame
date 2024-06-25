#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct{
    char name[50];
    char contest[5];
    int modifier;
    int value;
} fts_t;

int main(){

    FILE *tpointer;

    tpointer = fopen("fishing_tables.csv", "r");
    printf("Accessing Fishing Tables...\n");

    if(tpointer == NULL){
        
        printf("Error: Missing fishing_tables.csv");
        return 0;

    } else{

        printf("Success! Importing Data...\n");

    }

    /*Creating a struct array and initializing variables*/
    fts_t ft[400];
    char buffer[1024];
    int count = 0;
    char name[100];
    char contest[100];
    int modifier;
    int value;

    /*Reading the CSV into the struct*/
    while(fgets(buffer, 1024, tpointer)){
        sscanf(buffer, "%[^,],%[^,],%d,%d", name, contest, &modifier, &value);
        strcpy(ft[count].name, name);
        strcpy(ft[count].contest, contest);
        ft[count].modifier = modifier;
        ft[count].value = value;
        count++;
    }
    
    printf("\nFishing Tables imported successfully.\n\n\n\n\n");

    fclose(tpointer);

    int size = 1;
    int wait;
    int gac;
    int roll;
    time_t t;
    int upgrade;
    srand((unsigned) time(&t));


    /* Printing out the waiting time and determining if there's a bite */
    while(size != 0){
        printf("\nEnter bait size (1 = Light, 2 = Medium, 3 = Heavy. Press 0 to quit): ");
        scanf("%d", &size);

        gac = rand() % 20 + 1;

        if(size == 1){
            wait = rand() % 20 + 1;
            printf("\nYou wait %d minutes...", wait);
        } else if(size == 2){
            wait = rand() % 4 + 1;
            printf("\nYou wait %d0 minutes...", wait);
        } else if(size == 3){
            wait = rand() & 100 + 1;
            printf("\nYou wait %d minutes...", wait);
        } else if(size == 0){
            return 0;
        } else{
            printf("\nInvalid Bait size.");
            continue;
        }


        /* Refreshing the loop if nothing bites */
        if(gac < 10){
            printf("\nNothing bites...\n\n\n");
            continue;
        }


        /* The fun Part */
        if(size == 1){
            roll = rand() % 100;
            if(roll >= 95 && roll <= 100){
                upgrade = 1;
            } else{
                printf(" A %s bites!\nContest: %s\nFish's Bonus: %d\nValue: %dgp\n", ft[roll-1].name, ft[roll-1].contest, ft[roll-1].modifier, ft[roll-1].value);
            }
        }

        if(size == 2 || upgrade == 1){
            roll = rand() % 100 + 100;
            if(roll >= 192 && roll <= 200){
                upgrade = 2;
            } else{
                printf(" A %s bites!\nContest: %s\nFish's Bonus: %d\nValue: %dgp\n", ft[roll-1].name, ft[roll-1].contest, ft[roll-1].modifier, ft[roll-1].value);
            }
        }

        if(size == 3 || upgrade == 2){
            roll = rand() % 100 + 200;
            if(roll >= 275 && roll <= 300){
                upgrade = 3;
            } else{
                printf(" A %s bites!\nContest: %s\nFish's Bonus: %d\nValue: %dgp\n", ft[roll-1].name, ft[roll-1].contest, ft[roll-1].modifier, ft[roll-1].value);
            }
        }

        if(upgrade == 3){
            roll = rand() % 100 + 300;
            printf(" A %s bites!\nContest: %s\nFish's Bonus: %d\nValue: %dgp\n", ft[roll-1].name, ft[roll-1].contest, ft[roll-1].modifier, ft[roll-1].value);
        }

    }
 
    return 0;
    }