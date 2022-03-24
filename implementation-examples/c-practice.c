#include <stdio.h>

int main() // pointer practice
{
    // declare a pointer
    int *p;  // most common
    int *p1; // some other ways to declare
    int *p2;

    // declare multiple pointers
    int *p1, p2;

    // practice taking input
    int var;
    printf("var: ");
    scanf("%d", &var);
    printf("value of var: %d", var);
    printf("address of var: %p", &var);
    return 0;

    // assign addresses to pointers
    int *pc, c;
    c = 5;
    pc = &c; // pc has the address of the location of variable c

    // get value of thing pointed by pointers
    printf("%d", *pc); // Output: 5
    //* is called a dereference operator (when working with pointers)
    // opeartes on a pointer and gives the value stored in that pointer.

    // change value of pointed by pointers
    int *pc, c;
    c = 5;             // value of c is 5
    pc = &c;           // pc is address of c
    c = 1;             // c is modified but address remains the same
    printf("%d", c);   // Output: 1
    printf("%d", *pc); // Output: 1

    int *pc, c;
    c = 5;
    pc = &c;
    *pc = 1;           // value of element stored in address is modified
    printf("%d", *pc); // Output: 1
    printf("%d", c);   // Output: 1

    int *pc, c, d;
    c = 5;
    d = -15;

    pc = &c;
    printf("%d", *pc); // Output: 5
    pc = &d;
    printf("%d", *pc); // Output: -15
}

//==================================================
// C Dynamic Memory Allocation
//  learn how to dynamically allocate memory in C program using
//  standard library functions: malloc(), calloc(), free(), realloc().

// An array is a collection of a fixed number of values
// Once array size is declared, you cannot change it.
// Sometimes the size of the declared array is insufficient
// To solve this issue, allocate memory manually during run-time.

// To allocate memory dynamically, malloc(), calloc(), realloc(), free() are used.
// these functions are defined in the <stdlib.h> header file.

// C malloc()
// malloc() stands for memory allocation.
// function reserves block of memory of the specified numebr of bytes.
// returns a pointer of void which can be casted into pointers of any form.

#include <stdlib.h>
// ptr = (castType*) malloc(size);
int main()
{
    float *ptr;
    ptr = (float *)malloc(100 * sizeof(float));
}
// The above statement allocates 400 bytes of memeory.
// Because size of float is 4 bytes
// ptr holds the address of the first byte
// expression results in a NULL pointer if the memory cannot be allocated.

// C calloc()
// The name "calloc" stands for contiguous allocation.
// malloc() function allocates memory and leaves the memory uninitialized,
// whereas the calloc() function allocates memory and initializes all bits to 0;

// ptr = (castType*)calloc(n, size);
int main()
{
    float *ptr;
    ptr = (float *)calloc(25, sizeof(float));
}
// allocates contiguous space in memory for 25 elements of type float

// C free()
// Dynamically allocated memory created with either calloc() or malloc()
// doesn't get freed on their own.
// You must explicity use free() to release the space

// free(ptr)
free(ptr);
// frees the space allocated in memory pointed by ptr.

// Example: malloc() and free()
//  Program to calculate the sum of n numbers entered by the user
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    // if memory cannot be allocated
    if (ptr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);

    // deallocating the memory
    free(ptr);

    return 0;
}

// Outputs:
//  Enter number of elements: 3
//  Enter elements: 100
//  20
//  36
//  Sum = 156
// Dynamically allocated the memory for n number of int

// Example 2: calloc() and free()
//  Program to calculate the sum of n numbers entered by the user
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, *ptr, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);
    free(ptr);
    return 0;
}

// Outputs:
//  Enter number of elements: 3
//  Enter elements: 100
//  20
//  36
//  Sum = 156

// C realloc()
// If the dynamically allocated memory is insufficient or more than required,
// you can change the size of perviously allocated memory using realloc()

// ptr = realloc(ptr, x);
int main()
{
    int *ptr, x;
    ptr = realloc(ptr, x);
}
// ptr is reallocated with a new size of x

// Example 3: realloc()
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, i, n1, n2;
    printf("Enter size: ");
    scanf("%d", &n1);

    ptr = (int *)malloc(n1 * sizeof(int));

    printf("Addresses of previously allocated memory:\n");
    for (i = 0; i < n1; ++i)
        printf("%pc\n", ptr + i);

    printf("\nEnter the new size: ");
    scanf("%d", &n2);

    // rellocating the memory
    ptr = realloc(ptr, n2 * sizeof(int));

    printf("Addresses of newly allocated memory:\n");
    for (i = 0; i < n2; ++i)
        printf("%pc\n", ptr + i);

    free(ptr);

    return 0;
}

// Output:
//  Enter size: 2
//  Addresses of previously allocated memory:
//  26855472
//  26855476

// Enter the new size: 4
// Addresses of newly allocated memory:
// 26855472
// 26855476
// 26855480
// 26855484

//==================================================
// struct practuce
struct structureName
{
    // dataType member1;
    // dataType member2;
    //...
    int n;
};

struct Person
{
    char name[50];
    int citNo;
    float salary;
};

// create structure variables
//  to allocate memory of structure types, structure variables must be created

// use struct Person declared earlier
int main()
{
    struct Person person1, person2, p[20];
    return 0;
}

// another way of creating struct variables
struct Person
{
    char name[50];
    int citNo;
    float salary;
} person1, person2, p[20];
// person1 and person2 are struct Person variables
// p[] is a struct Person array of size 20

// Access members of a structure
//  1. "." member operator
//  2. "->" structure pointer operator

// access salary of person2
// person2.salary

#include <stdio.h>
#include <string.h>
// create struct with person1 variable
struct Person
{
    char name[50];
    int citNo;
    float salary;
} person1;

int main()
{

    // assign value to name of person1
    strcpy(person1.name, "George Orwell");

    // assign values to other person1 variables
    person1.citNo = 1984;
    person1.salary = 2500;

    // print struct variables
    printf("Name: %s\n", person1.name);
    printf("Citizenship No.: %d\n", person1.citNo);
    printf("Salary: %.2f", person1.salary);

    return 0;
}

// Output
// Name: George Orwell
// Citizienship No.: 1984
// Salary: 2500.00

// for assigning value to person1.name we use strcpy()
// this is because name is a char array (C-string) and cannot use assignment operator =

// Keyword typedef
// use typedef keyword to create an alias name for data types.
// commonly used with structrues to simplify the syntax of declaring variables.

struct Distance
{
    int feet;
    float inch;
};

int main()
{
    struct Distance d1, d2;
}

// can be summarized with typedef
typedef struct Distance
{
    int feet;
    float inch;
} distances;

int main()
{
    distances d1, d2;
}

// C++ example
#include <stdio.h>
#include <string.h>

// struct with typedef person
typedef struct Person
{
    char name[50];
    int citNo;
    float salary;
} person;

int main()
{

    // create  Person variable
    person p1;

    // assign value to name of p1
    strcpy(p1.name, "George Orwell");

    // assign values to other p1 variables
    p1.citNo = 1984;
    p1.salary = 2500;

    // print struct variables
    printf("Name: %s\n", p1.name);
    printf("Citizenship No.: %d\n", p1.citNo);
    printf("Salary: %.2f", p1.salary);

    return 0;
}
// typedef with Person structure to create an alias person
// simple declar Person variable using person alias

// Nested structures
struct complex
{
    int imag;
    float real;
};

struct number
{
    struct complex comp;
    int integer;
} num1, num2;

// set imag of num2 variable to 11.
// num2.comp.imag = 11;

// C++ example
#include <stdio.h>

struct complex
{
    int imag;
    float real;
};

struct number
{
    struct complex comp;
    int integer;
} num1;

int main()
{

    // initialize complex variables
    num1.comp.imag = 11;
    num1.comp.real = 5.25;

    // initialize number variable
    num1.integer = 6;

    // print struct variables
    printf("Imaginary Part: %d\n", num1.comp.imag);
    printf("Real Part: %.2f\n", num1.comp.real);
    printf("Integer: %d", num1.integer);

    return 0;
}

// Output:
// Imaginary Part: 11
// Real Part: 5.25
// Integer: 6

//==================================================
// C Pointers to struct
struct name
{
    // member1;
    // member2;
    //.
    //.
    int blank;
};

int main()
{
    struct name *ptr, Harry;
}
// ptr is a pointer to struct

// Access members using pointer
#include <stdio.h>
struct person
{
    int age;
    float weight;
};

int main()
{
    struct person *personPtr, person1;
    personPtr = &person1;

    printf("Enter age: ");
    scanf("%d", &personPtr->age);

    printf("Enter weight:");
    scanf("%f", &personPtr->weight);

    printf("Displaying:\n");
    printf("Age: %d", personPtr->age);
    printf("Weight: %f", personPtr->weight);
    return 0;
}
// address of person1 is stord in personPtr
// access members of person1 using personPtr
// personPtr->age is equivalent to (*personPtr).age
// personPtr->weight is equivalent to (*perosnPtr).weight

// Dynamic memory allocation of structs
// Example:
#include <stdio.h>
#include <stdlib.h>
struct person
{
    int age;
    float weight;
    char name[30];
};

int main()
{
    struct person *ptr;
    int i, n;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    // allocating memory for n numbers of struct person
    ptr = (struct person *)malloc(n * sizeof(struct person));

    for (i = 0; i < n; ++i)
    {
        printf("Enter first name and age respectively: ");

        // To access members of 1st struct person,
        // ptr->name and ptr->age is used

        // To access members of 2nd struct person,
        // (ptr+1)->name and (ptr+1)->age is used
        scanf("%s %d", (ptr + i)->name, &(ptr + i)->age);
    }

    printf("Displaying Information:\n");
    for (i = 0; i < n; ++i)
        printf("Name: %s\tAge: %d\n", (ptr + i)->name, (ptr + i)->age);

    return 0;
}
// Outputs:
//  Enter the number of persons:  2
//  Enter first name and age respectively:  Harry 24
//  Enter first name and age respectively:  Gary 32
//  Displaying Information:
//  Name: Harry	Age: 24
//  Name: Gary	Age: 32

// n number of struct variables are created where n is entered by the user.
// to allocate memory for n number of struct person
// ptr = (struct person*) malloc(n * sizeof(struct person));
// then we used ptr pointer to access elements of person.