# Exercise 5: The Structure of a C Program

```C
#include <stdio.h> // import functions we want to use

/* This is a comment. */

/*
Explaination of text in main():
    int - integer data type
    argc - count of total command line arguments passed
    char - character data type
    argv - array of character strings of each command line parameter passed
*/

int main(int argc, char *argv[])
{
    /* type name = value; */
    int distance = 100;

    // this is also a comment
    printf("You are %d miles away.\n", distance);

    return 0;
}
```
