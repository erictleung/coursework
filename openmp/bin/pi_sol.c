#include <stdio.h>
#include <omp.h>

static long num_steps = 100000; double step;
#define NUM_THREADS 2

void main() 
{
    int i, nthreads; double pi, sum[NUM_THREADS];
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
    // initialize local variables for each thread
    int i, id, nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

    // save num threads in case computer doesn't give you all you requested
    if (id == 0) nthreads = nthrds;

    // cyclic distribution of loop interations
    for (i=id,sum[id]=0.0; i<num_steps; i=i+nthrds) 
    {
        x = (i+0.5)*step;
        sum[id] += 4.0/(1.0 + x*x);
    }
    }

    for (i=0,pi=0.0; i<nthreads; i++) pi += sum[i] * step;
    printf("%lf\n", pi);
}
