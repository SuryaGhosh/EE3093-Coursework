// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 o  r Debug > Start Debugging menu

// Surya Ghosh
// 52426797
// EE 3093 

#define _USE_MATH_DEFINES // tells compiler to use the constants defined in math.h

// includes libraries 
#include <stdio.h> // <> tells the compiler to look in the standard libraries 
#include <math.h>

// allows the use of scanf
#define _CRT_SECURE_NO_WARNINGS true 

// Function declarations
void q1();
void q2();
void q3();
void q4();
void q5();

void run_lab_1() {
    q1();
    q2();
    q3();
    q4();
    q5();
}

void q1() {
    printf("\nQ1\n");

    int val = 33;
    int val_square = val * val;
    int val_cube = val_square * val;
    float val_reciprocal = 1.0 / val;
    printf("Value: %i\n", val);
    printf("Value squared: %i\n", val_square);
    printf("Value cubed: %i\n", val_cube);
    printf("Value reciprocal: %f\n", val_reciprocal);

}

void q2() {
    printf("\nQ2\n");

    float radius = 0.5774;
    float perimeter = 2 * M_PI;
}

void q3() {
    printf("\nQ3\n");

    # define N 42  // #define doesn't create a variable when the program is run,
                     // but instead tells the compiler to replace all instances of N with 42

    const int x = 1729;
    int remainder = x % N;

    printf("Remainder: %i\n", remainder);
}

void q4() {
    printf("\nQ4\n");

    int base;
    int height;
    int area;
    int perimeter;

    // scanf syntax: scanf("%x", &variable); &variable: address of variable, needed so that scanf can write the value to it 
    //

    printf("Enter base: ");
    scanf("%d", &base); // stores into base 
    printf("Enter height: ");
    scanf("%d", &height);
    area = base * height;
    perimeter = 2 * base + 2 * height;

    printf("Area: %d\tPerimeter: %d\n", area, perimeter);
}

void q5() {
    printf("\nQ5\n");

    int a;
    int b;
    int c;
    float alpha;
    float beta;
    float gamma;
    float area;

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    alpha = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2*a * c));
    beta = acos((pow(b, 2) + pow(a, 2) - pow(c, 2)) / (2*b * a));
    gamma = acos((pow(c, 2) + pow(b, 2) - pow(a, 2)) / (2*c * b));

    printf("alpha (rad): %f\n", alpha);
    printf("beta (rad): %f\n", beta);
    printf("gamma (rad): %f\n", gamma);

    float s = (a + b + c) / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("area: %f\n", area);
} 