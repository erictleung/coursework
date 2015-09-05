# Discussion 2

After many hours of thinking about the problem itself, I found a solution to
parallelizing the calculation of pi that is slightly different to Tim's
solution. 

At the base of it, the strategy to solve this problem is called **SPMD** or
**single program, multiple data**. This takes a single program (in our case it
is the construct within the `#pragma omp parallel`) and tells multiple processes
to perform such a program on different pieces of data. [Here][SPMD] is more information
on it, along with the other programming techniques defined by [Flynn's
taxonomy][flynn].

[SPMD]: https://en.wikipedia.org/wiki/SPMD
[flynn]: https://en.wikipedia.org/wiki/Flynn%27s_taxonomy

## My Solution

I was able to realize on my own that there was going to be a problem with have a
single sum variable shared across the threads being called. Instead of calling
the private variables within each thread, I decided to instantiate all variables
outside of the `#pragma omp parallel`. This allows me to distinguish explcitly
which variables are private and which ones should be shared among all the
threads. 

### Private and Public Variables

```C
#pragma omp parallel private(ID,x,sum,start,end,i) shared(step,thr_len,sum_thr)
```

The above is the key to making my program work. Here is a description of what
each variable does:

- `private` Variables
    - `ID`, 
    - `x` (the y value for the function at a given step), 
    - `sum` (the cumulative sum at a particular step), 
    - `start` (the start index out of all steps),
    - `end` (the end index out of all steps), and
    - `i` (loop index)
- `shared` Variables
    - `step` (the step size you take along the x-axis),
    - `thr_len` (this specifies how many steps each thread should take), and
    - `sum_thr` (this is an array where each thread can save their sum)

This code above allows me to get away without writing the private variables
within the `#pragma omp parallel` construct, which is what Tim's solution is. I
got the idea for code the private and shared variables at the construct from a
[Dartmouth website](http://www.dartmouth.edu/~rc/classes/intro_openmp/).

## Tim Solution

The solution Tim gives is more elegant in my opinion because you instantiate
variables in their correct places e.g. within and outside the `#pragma omp
parallel` construct. 

### Private and Public Variables

Tim instantiated all the private variables that I assigned as an afterthought.

```C
#pragma omp parallel
{
int i, id, nthreads;
double x;
id = omp_get_thread_num();
...
}
```

### Check for Number of Threads Actually Given

The one thing that was different was the following:

```C
#pragma omp parallel
{
...
nthrds = omp_get_num_threads();

if (id == 0) nthreads = nthrds;
...
}
```

Tim explains that this is crucial when asking for more threads. I only asked for
5 threads on my local laptop, so there no restrictions for me to run my program.
However, if I were running on a cluster and asked for, say, 500,000 threads, I
might only be restricted to 15 threads. Thus, even though I asked for 500,000
threads, I would only be given 15 threads. And my program will not catch this. 

The solution for this is assigning one threads (in this case he used the master
thread with the ID equal to 1) to find out truly how many threads I was given
and save that value for future use. 

### Comparison with My Solution

My solution assumes that if I ask for five threads, then I will get five
threads. This number of threads was hard-coded straight into my program, while
Tim's solution doesn't make that assumption. 

He codes in the true number of threads given using the command
`omp_get_num_threads()` to get the true number of threads and uses it in the
`for` loop for each thread. 

### `for` Loop Indices

Another elegant part of this solution is the the index allocation to each
thread. I split up the indices (i.e. the values of x) before hand using a simple
calculation.

```C
start = thr_len*ID;
end = thr_len*(ID+1);
```

I used the thread count to help me index the x values and then incremented by
one (`i++`) in the `for` loop because I am used to only incrementing by one.
Tim used a strategy he called **cyclic distribution of loop iterations** to
split up the indices for each thread. Another term he used to describe this
strategy was **round robin** or **dealing a deck of card**.

## Time Statistics

Here are the time statistics from Tim running his initial solution.

![From one thread to four threads, you go from 1.86 seconds to 0.97
seconds][pi-speed]

Source: Mattson, Tim. A "Hands-on" Introduction to OpenMP.

The time it takes to run the program decrease by a little less than a second.
But with multiple threads working on this program, you would assume that the
speed up would be much greater.

[pi-speed]: ./figures/pi-speed-up.png

## False Sharing

The reason for this is something called **false sharing**. The way we designed
the program is to share a sum array among the threads. This is crucial to save
the summation calculations of each array. However, because threads will work in
different times and save to this array at potentially the same time, this
increases the amont of time to finish.

### Cache Lines

The underlying reason of this is beyond my understanding but it has to do with
the fact that when your processor is about to compute something, it is stored in
**cache**. A cache will have a **cache line** with processes lined up. 

![False Sharing][false-sharing]

Our program might come across the situation where the writing of multiple
threads' sum to the sum array are in the same cache line. So updating the sum
array will cause the cache lines to "slosh back and forth" between threads.

[false-sharing]: ./figures/false-sharing.png
