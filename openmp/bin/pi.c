#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;
int main()
{
    double pi, sum = 0.0;
    double start_time, run_time;
    step = 1.0/(double) num_steps;
    int threads = 5;
    int thr_len = num_steps/threads;
    //double sum_thr[threads]; // each thread has own variable

    printf("Here are some parameters set:\n");
    printf("Step Size: %lf\n", step);
    printf("Num of Threads: %d\n", threads);
    printf("Num Steps per Thread: %d\n\n", thr_len);

    omp_set_num_threads(threads);

    start_time = omp_get_wtime();

    #pragma omp parallel for private(ID,x_temp,temp_sum,start,end,i) shared(sum,step,thr_len)
    {
    int ID = omp_get_thread_num(); // initialize thread ID
    double x_temp = 0.0, temp_sum = 0.0; // temp sum for particular thread
    int start = thr_len*ID; // start index
    int end = thr_len*(ID+1); // end index

    for (int i=start; i<end; i++) 
    {
        x_temp = (i+0.5)*step;
        temp_sum = temp_sum + 4.0/(1.0+x_temp*x_temp);
    }
    //sum_thr[ID] = temp_sum;
    sum = temp_sum;
    }

    // check array summing
    //printf("Here are the values of the thread sums.\n");
    //for (i=0; i<threads; i++) 
    //{
        //printf("%lf\n", sum_thr[i]);
    //}
    //printf("\n");
    
    // loop through sum of each thread and add them together
    //for (i=0; i<threads; i++) 
    //{
     //   printf("This is the thread %d sum: %lf\n", i,sum_thr[i]);
      //  printf("This is the sum so far: %lf\n", sum);
       // sum = sum + sum_thr[i];
        //printf("This is the sum after adding: %lf\n\n", sum);
    //}
    //printf("This is the sum: %lf\n", sum);

    pi = step*sum;

    run_time = omp_get_wtime() - start_time;
    printf("pi with %ld steps is %lf in %lf seconds.\n", num_steps,pi,run_time);
}
