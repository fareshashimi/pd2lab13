#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int stdNum;
    char name[20];
    char surname[20];
    char depName[50];
}student;

student *addStd(FILE *mp){
    student std;

    printf("Number: ");
    scanf("%d", &std.stdNum);
    printf("Name: ");
    scanf("%s", std.name);
    printf("Surname: ");
    scanf("%s", std.surname);
    printf("Department's name: ");
    scanf("%s", std.depName);

    fseek(mp, (std.stdNum - 1)*sizeof(std), SEEK_SET);
    fread(&std, sizeof(std), 1, mp);

    printf("\n\n Student added successfully.\n\n");
}

student *searchStdNum(FILE *mp){
    int stdNum;
    student std;

    printf("Insert a student number to be searched:\n");
    scanf("%d", &stdNum);

    if(std.stdNum==0){
        printf("\n\n The student is not found in the file.\n");
    }
    else{
        printf("Student number: %d\n", std.stdNum);
        printf("Student full name: %s %s\n", std.name, std.surname);
        printf("Department name: %s\n\n", std.depName);
    }
}

int main(){
    int c;
    FILE *mp;

    if((mp = fopen("student.dat", "r+"))==NULL){
        printf("\n\n The file is not found in the computer.\n");
        return 0;
    }
    else{
        while(1){
            printf("Menu:\n");
            printf("1.Add student information.\n2.Search student.\n3.Exit.\n\n");
            printf("Select your choice: ");
            scanf("%d", &c);
            printf("\n\n");

            switch(c){
                case 1:
                    addStd(mp);
                break;

                case 2:
                    searchStdNum(mp);
                break;

                case 3:
                    fclose(mp);
                    exit(0);
                break;    

                default:
                    printf(" Wrong choice. Try again...\n\n");
                break;
            }

        }
    }

    return 0;
}