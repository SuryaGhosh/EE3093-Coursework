#include "lab1.h"
#include "lab2.h"
#include "lab3.h"

// selected lab to run 
int lab_select;
void lab_manager();

int main() {
    lab_manager();
    return 0;
}

void lab_manager() {
    printf("----- EE3093 Lab Manager -----\n\n");
    printf("------- Available Labs -------\n");
    printf("Lab1.c\nLab2.c\nlab3.c\n\n");
    printf("Select Lab: ");
    scanf("%d", &lab_select);
    getchar(); // removes the \n left in the buffer by scanf
    printf("------------------------------\n");

    switch (lab_select) {
    case 1:
        run_lab_1();
        break;
    case 2:
        run_lab_2();
        break;
    case 3:
        run_lab_3();
    }
}