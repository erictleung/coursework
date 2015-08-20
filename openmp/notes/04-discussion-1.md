# Discussion 1

```
#pragma omp parallel
```

We will look at this statement later, but for now, our understanding should be
that this statement says "Give me a bunch of threads." Since we did not specify
this number, it will just use the default number. The system chooses this.

```
int ID = omp_get_thread_num();
```

This `omp_get_thread_num()` is a runtime library routine that retrieves the
number of threads. That will give us an identifier for the thread being used,
which ranges from `0` to `n-1` number of threads, where `n` is the total number
of threads.

## Share Memory Computers

There are two types:

- **Symmetric multiprocessor (SMP)**: this is where memory is divided into evenly
  accessible pieces, meaning that the computer can access or use each piece of
  memory with equal time
- **Non Uniform address space multiprocess (NUMA)**: this is where memory will be
  divided and some parts of memory may be easier to access than others,
  depending on where the processor is in relation to memory

Not too long ago, there was a truly SMP computer called the Cray-2 back in
1985. Each of its memory had equal-time access.

## Today's Computers

![Intel i7-970][chip]

Source: Mattson, Tim. A "Hands-on" Introduction to OpneMP.

Take for example Intel's Core i7-970 chip shown above. It has size cores and
multiple layers of cache you may have heard, such as L1, L2, or L3 cache. These
are all pieces of memory, but they can be accessed at different speeds. This is
also known as a cache hierarchy.

![Intel i7-970 Abstraction][cartoonChip]

Source: Mattson, Tim. A "Hands-on" Introduction to OpneMP.

[chip]: ./figures/intel-i7.png
[cartoonChip]: ./figures/i7-abstract.png

## Programming Shared Memory Computers

Within a computer, there is a concept of a "process." It is an instance of a
program execution. There is also a concept of a "stack." These stacks can be
split up into multiple threads. Each thread will have its own piece of *private
memory*. However, the entire process also has a shared memory. This shared
memory can be accessed by these threads in case there is some data that needs to
be accessed globally.

The difference threads of a program will go in and out of the shared address
space as they are being run. These threads are also scheduled in different times
everytime you run a parallel program. This can be seen while running a
parallelized "Hello, World!" program.

```C
#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        ID = omp_get_thread_num();
        printf("Hello(%d)", ID);
        printf("World(%d)", ID);
    }
}
```

## OpenMP Overview: How do thread interact?

- OpenMP is a multi-threading, shared address model.
    - Threads communicate by sharing variables in the heap.
- Unintended sharing of data causes race conditions.
    - **Race condition**: when the program's outcome changes as the threads are
      scheduled differently.
    - This can be a problem and the programmer should be very aware of how these
      threads can communicate
- To control race conditions:
    - Use synchronization to protect data conflicts
- Synchronization is expensive so change how data is accessed to minimize the
  need for synchronization
