# Introduction to Parallel Programming Part 2

## Concurrency vs Parallelism

- Concurrency: things are active at the same time
- Parallelism: things are running and doing things are the same time

This is a subtle difference between the two. To use an analogy of constructing a
house, concurrency is having five people working on a house together but only
one person is working on the house at one time. Parallelism of building a
house means that everyone is working on the house simultaneously.

## Paint the Parallel Landscape

You need to map the concurrency process onto your processors so that you can
actually run things in parallel, not just concurrently. So understanding these
definitions, we can think of each of these paradigms as subsets of one another.

There is overall programs that run. A subset of those programs can be
concurrent, as they can run together but not necessarily at the same time. Then
within concurrent programs, you can have truly parallel running programs.

## Concurrent vs Parallel Application

- Concurrent application: an application for which computations logically
  execute simultaneously due to the semantics of the application (e.g. web
  server)
- Parallel application: an application for which the computations actually
  execute simultaneously in order to complete a problem in less time.

## Process of Parallel Programming

You need to breakdown your problem and find the parallelism. This part is not
and has not been automated yet. Once you have this parallelism, you need to
design an algorithm that can execute in parallel.

The actually parallel programming language you choose is the very last step in
figuring out the parallelism. The hardest part is designing the parallelism in
your problem. 

## OpenMP

- An API for writing multithreaded applications
- A set of compiler directives and library routines for parallel application
  programmers
- Greatly simplifies writing multi-threaded (MT) programs in Fortran, C, and C++

Assumes you have shared hardware space. You have an operating system that
manages the hardware with OpenMP just above that. Then you have your programs
that you parallelize. 

## OpenMP Core Syntax

Most of the constructs in OpenMP are compiler directives. So you will need the
following in your code:

```C
#pragma omp construct [clause [clause] ...] 
    #pragma omp parallel num_thread(4);
```

Additionally, you will need to call function prototypes and types in the header
with the following:

```C
#include <omp.h>
```

Most OpenMP constructs apply to a "Structured Block." 

A "Structured Block" is a block of one or more statements with one point of
entry at the top and one point of exist the bottom. To me, this sounds like a
function definition and using the `multiprocessing` package in Python where you
need to define a function to use in the parallelism.
