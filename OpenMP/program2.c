#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
 omp_set_num_threads(4);
 int i=0;
 printf(“Print about PDC lab# 1\n”); 
#pragma omp parallel
{
printf(“Print about PDC lab #2\n”);
for (i=0;i<5;i++) {
 	printf(“Print about PDC lab #3\n”);
 	}
printf(“Print about PDC lab #4\n”);
 }
 return 0;
}
