# Exercise 1: Dust Off that Compiler

This lesson is the "Hello World" for C. 

## Header Command

In this lesson, we see the importance of the `#include <stdio.h>` header
command for the program to start.

That header tells the program to look for the `stdio.h` file in place of the
header. The `stdio.h` file contains function prototypes that have functions like
`printf()` and `scanf()` (the standard input function). 

## Other Headers

There are other such header files such as the `<math.h>` file for some math
functions and the `<complex.h>` file to handle complex number arithmetic. Some
of the C Standard Library header files can be found [here][header]. If I were to
get into C++, [here][c++] are the C++ Standard Library header files. 

## argc and argv

For the first exercise, there was this "incantation" part of the program.
Namely:

```C
int main(int argc, char *argv[])
```

The `argc` stands for "argument count"; `argc` contains the number of arguments
passed to the program.

The `argv` stands for "argument vector". This contains the vector (one can think
of this as a list) of arguments, the number of which were defined in `argc`.

This [website][argc] explains these arguments even more. But on that website, it
describes a simple program to explain what these arguments mean.

```C
#include <stdio.h>

int main (int argc, char *argv[])
{
  int count;

  printf ("This program was called with \"%s\".\n",argv[0]);

  if (argc > 1)
  {
    for (count = 1; count < argc; count++)
    {
      printf("argv[%d] = %s\n", count, argv[count]);
    }
  }
  else
  {
    printf("The command had no other arguments.\n");
  }

  return 0;
}
```

From what I understand from this simple program (plus the explanation on the
site), the `argc` and `argv` are just instantiated variables that can be used
through the program. The arguments from `argv` are added from the arguments you
add to the end of the calling of the function (e.g. `./ex1 a b c`). The
arguments `a`, `b`, `c` will be added to the `argv` vector.

Source:

- http://stackoverflow.com/questions/19088284/what-does-include-stdio-h-really-do-in-a-c-program
- http://www.quora.com/What-is-include-stdio-h

[header]: http://en.cppreference.com/w/c/header
[c++]: http://en.cppreference.com/w/cpp/header
[argc]: http://crasseux.com/books/ctutorial/argc-and-argv.html
