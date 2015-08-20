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

- Symmetric multiprocessor (SMP): this is where memory is divided into evenly
  accessible pieces, meaning that the computer can access or use each piece of
  memory with equal time
- Non Uniform address space multiprocess (NUMA): this is where memory will be
  divided and some parts of memory may be easier to access than others,
  depending on where the processor is in relation to memory

Not too long ago, there was a truly SMP computer called the Cray-2 back in
1985. Each of its memory had equal-time access.

## Today's Computers

![Intel i7-970][chip]

[chip]: ./figures/intel-i7.png

Take for example Intel's Core i7-970 chip shown above. It has size cores and
multiple layers of cache you may have heard, such as L1, L2, or L3 cache. These
are all pieces of memory, but they can be accessed at different speeds.
