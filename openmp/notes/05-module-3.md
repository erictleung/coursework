# Module 3: Creating Threads (The Pi Program)

In the OpenMP programming model (or maybe in parallel programming in general),
there is a concept called **Fork-Join Parallelism**. This paradigm can be
understand if you break down the name. 

When you initiate a program, you will have a master thread. This master thread
can be then be split (or *forked*) into multiple threads. The master thread will
still exist as one of the forked threads. The master thread will have the index
or rank of 0. 

![Fork-Join Parallelism][fork-join]

Source: Mattson, Tim. A "Hands-on" Introduction to OpenMP.

These forked threads will then work in parallel. Once the parallel work has
finished, the multiple threads will then come and *join* back together to make
just the one master thread again. 

[fork-join]: ./figures/fork-join.png

## Nested Fork Processes

This process can continue, through a fork then join and then fork again process.
These forking processes can even be nested. In other words, say you fork the
master thread into four threads, then we could hypothetically fork thread 3 once
more into four more threads. The joining would first begin with thread 3's
forked threads being joined back and then the other threads can join back
together to make the master thread.

## Thread Creaction

To create threads, you need to provide the parallel construct.

```C
omp_set_num_threads(4); // this calls for 4 threads
#pragma omp parallel
```
As soon above, the `omp_set_num_threads(n)` function will call for `n` number of
threads, depending on what you desire.

This statement can also be collapsed into one statement:

```C
#pragma omp parallel omp_set_num_threads(4); // this calls for 4 threads
```

## Exercises 2 through 4

The next few exercises will involve programming the integral of an eqution that
returns an estimation of ![The math constant pi][pi].

The true integral for the equation is: 

![The integral to estimate pi][integral]

The approximation for ![The math constant pi][pi] can be solved with the
following equation:

![The summation approximation for pi][approx]

The approximation of the integral can be given by the sum of smaller rectangles
underneath the curve. This is one of the basic concepts learned in calculus as
you learn the concept of an integral.

[pi]: ./figures/pi.png
[integral]: ./figures/integral.png
[approx]: ./figures/approx-pi.png

## Serial Pi Program

Below is the serial version of the program we will be parallelizing.

```C
static long num_steps = 100000;
double step;
int main()
{
    int i; double x, pi, sum = 0.0;

    step = 1.0 / (double) num_steps;

    for (i = 0; i < num_steps; i++) {
        x = (i + 0.5)*step;
        sum = sum + 4.0/(1.0 + x*x);
    }
    pi = step*sum;
}
```
