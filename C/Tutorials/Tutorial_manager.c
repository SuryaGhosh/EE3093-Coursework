#include "tutorial1.h"
#include "tutorial2.h"
#include "tutorial3.h"
#include <stdio.h>


// Tutorial Manager


int tutorial_select;
void tutorial_manager();

int main() {
	tutorial_manager();
}

void tutorial_manager() {
    printf("----- EE3093 Tutorial Manager -----\n\n");
    printf("-- Available Tutorials --\n");
    printf("tutorial1.c\ntutorial2.c\ntutorial3.c\n");
    printf("Select Tutorial: ");
    scanf_s("%d", &tutorial_select);
    printf("-----------------------------------\n");

    switch (tutorial_select) {
    case 1:
        run_tutorial_1();
        break;
    case 2:
        run_tutorial_2();
        break;
    case 3:
        run_tutorial_3();
        break;
    }
}