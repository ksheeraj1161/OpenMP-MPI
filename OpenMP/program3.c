#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
 int i=0;
printf("Print # 1\n");
#pragma omp parallel
{
omp_set_num_threads(100);
printf("Print #2\n");
#pragma omp parallel for
for(int i=0;i<2;i++) {
 	printf("Print #3\n");
 	}
printf("Print #4\n");
}
 return 0;
}
