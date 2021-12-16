#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
 omp_set_num_threads(5);
 		int i=omp_get_num_threads();
        int j=omp_get_max_threads();
 		if(5==omp_get_thread_num())
 	    {
 			printf("num threds\n%d\n%d",i,j);
 			}
 return 0;
 }
