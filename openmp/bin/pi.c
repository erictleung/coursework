#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;
int main()
{
    double x, pi, sum, bigSum;
    double start_time, run_time;
    step = 1.0/(double) num_steps;
    int ID, start, end, i, l, threads = 5;
    int thr_len = num_steps/threads;
    double sum_thr[threads]; // each thread has own variable

    printf("Here are some parameters set:\n");
    printf("Step Size: %lf\n", step);
    printf("Num of Threads: %d\n", threads);
    printf("Num Steps per Thread: %d\n\n", thr_len);

    omp_set_num_threads(threads);

    start_time = omp_get_wtime();

    #pragma omp parallel private(ID,x,sum,start,end,i) shared(step,thr_len,sum_thr)
    {
    ID = omp_get_thread_num(); // initialize thread ID
    start = thr_len*ID; // start index
    end = thr_len*(ID+1); // end index

    for (i=start; i<end; i++) 
    {
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }
    sum_thr[ID] = sum;
    }

    for (l=0; l<threads; l++) 
    {
        printf("Thread %d has sum: %lf\n", l, sum_thr[l]);
        bigSum = bigSum + sum_thr[l];
    }
    printf("\n");

    pi = step*bigSum;

    run_time = omp_get_wtime() - start_time;
    printf("Total sum is %lf\n", bigSum);
    printf("pi with %ld steps is %lf in %lf seconds.\n", num_steps,pi,run_time);
}
