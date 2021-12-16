//Write an OpenMP program to find and sum the Fibonacci series. Use one thread to generate the numbers up to the specified limit N=50000 and other threads has to sum and print them. Use omp reduction to protect the code region that might be updated by multiple threads concurrently. Measure the execution time for both versions (omp critical) varying the number of threads: 4 and 8.

//With parallel region and critical condition
#include <stdio.h>
#include <time.h>
#include <omp.h>
int main()
{
    int N=50, a[1000], i;
    omp_set_num_threads(4);

    a[0] = 0;
    a[1] = 1;
    
    double time_spent = 0.0;
 
    clock_t begin = clock();
    
#pragma omp parallel
    {
#pragma omp single
        for (i = 2; i < N; i++)
        {
            a[i] = a[i - 2] + a[i - 1];
            printf("Thread ID involved in the computation of Fibonnaci number %d is=%d\n", i + 1, omp_get_thread_num());
        }
#pragma omp barrier
#pragma omp single
        {
            printf("The series is:\n");
            for (i = 0; i < N; i++)
                printf("%d \t Thread ID displaying this number is = %d\n", a[i], omp_get_thread_num());
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The execution time is %f seconds \n", time_spent);
    return 0;
}

//Without parallel region:

#include <stdio.h>
#include <time.h>
#include <omp.h>
int main()
{
    int N=50, a[1000], i;
    omp_set_num_threads(4);

    a[0] = 0;
    a[1] = 1;
    
    double time_spent = 0.0;
 
    clock_t begin = clock();
    
        for (i = 2; i < N; i++)
        {
            a[i] = a[i - 2] + a[i - 1];
            printf("Thread ID involved in the computation of Fibonnaci number %d is=%d\n", i + 1, omp_get_thread_num());
        }

        {
            printf("The series is:\n");
            for (i = 0; i < N; i++)
                printf("%d \t Thread ID displaying this number is = %d\n", a[i], omp_get_thread_num());
        }
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The execution time is %f seconds \n", time_spent);
    return 0;
}


//With for loop reduction

#include <stdio.h>
#include <omp.h>
#include <time.h>
int main()
{
    int N=50, a[1000], i;
    omp_set_num_threads(8);
    int sum=0;
    a[0] = 0;
    a[1] = 1;
    double time_spent = 0.0;
    clock_t begin = clock();
#pragma omp parallel reduction(+: sum)
    {
#pragma omp single  
        for (i = 2; i < N; i++)
        {
            a[i] = a[i - 2] + a[i - 1];
            sum +=a[i];
            if(a[i]>=50000)
            {
              break;
            }
            printf("Thread ID involved in the computation of Fibonnaci number %d is=%d\n", i + 1, omp_get_thread_num());
        }
#pragma omp barrier
#pragma omp single
        {
            printf("The series is:\n");
            for (i = 0; i < N; i++)
            {
              if(a[i]>=50000)
              {
                break;
              }
                printf("%d \t Thread ID displaying this number is = %d\n", a[i], omp_get_thread_num());
            }
            printf("sum of series is \n");
            printf(" %d \t Thread ID displaying this number is = %d\n", sum, omp_get_thread_num());
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds \n", time_spent);
    return 0;
}

//To get values of series till 50000
#include <stdio.h>
#include <omp.h>
#include <time.h>
int main()
{
    int N=5000, a[100], i;
    omp_set_num_threads(4);
    a[0] = 0;
    a[1] = 1;
    double time_spent = 0.0;
    clock_t begin = clock();
#pragma omp parallel
    {
#pragma omp single
        for (i = 2; i < N; i++)
        {
            a[i] = a[i - 2] + a[i - 1];
            if(a[i]>=5000)
            {
              break;
            }
            printf("Thread ID involved in the computation of Fibonnaci number %d is=%d\n", i + 1, omp_get_thread_num());
        }
#pragma omp barrier
#pragma omp single
        {
            printf("The series is:\n");
            for (i = 0; i < N; i++)
            {
              if(a[i]>=5000L)
              {
                break;
              }
                printf("%d \t Thread ID displaying this number is = %d\n", a[i], omp_get_thread_num());
            }
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds \n", time_spent);
    return 0;
}
