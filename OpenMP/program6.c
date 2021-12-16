#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define CHUNKSIZE 2
int main (int argc, char *argv[])
  {
  int i, chunk, tid;
  float a[N], b[N], c[N];
 /* Some initializations */
 for (i=0; i < N; i++)
 a[i] = b[i] = i * 1.0;
 chunk = CHUNKSIZE;
#pragma omp parallel shared(a,b,c,chunk)
 {
 tid = omp_get_thread_num();
#pragma omp parallel for private(i) schedule(static,chunk)
 for (i=0; i < N; i++)
 	{
 	c[i] = a[i] + b[i];
 printf("tid= %d i= %d c[i]= %f\n", tid, i, c[i]);
 	}
      }
 /* end of parallel for construct */
}
