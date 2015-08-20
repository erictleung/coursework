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
