/* Obtención del modo de funcionamiento del scheduler para el proceso en ejecución */

#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
static int iteration_num=10000;
float proceso_1(int n_iter);
void proceso_2(int n_iter);
void proceso_3(int n_iter);
int main(void)
{
  clock_t start, stop;
  start = clock();
  proceso_1(iteration_num);
  stop = clock();
  printf("Proceso 1 %f\n",(double)(stop - start) / CLOCKS_PER_SEC);
  start = clock();
  proceso_2(iteration_num);
  stop = clock();
  printf("Proceso 2 %f\n",(double)(stop - start) / CLOCKS_PER_SEC);
  start = clock();
  proceso_3(iteration_num);
  stop = clock();
  printf("Proceso 3 %f\n",(double)(stop - start) / CLOCKS_PER_SEC);

	exit(EXIT_SUCCESS);
}
/* Fin función principal */

/* Función auxiliar */
float proceso_1(int n_iter){
  float result=1;
  for (size_t i = 2; i <= n_iter; i++) {
    result=result*(int)i;
    result=result*((int)i-1);
  }


}
void proceso_2(int n_iter){
  float result=1;

  for (size_t i = 1; i <= n_iter; i++) {
    float result_op=1;
    for (size_t j = 1; j <= n_iter; j++) {
      result_op=result_op+(int)j;
    }
    result=result+result_op;
  }

}
void proceso_3(int n_iter){
  float result=1;
  for (size_t i = 1; i <= n_iter/3; i++) {
    continue;
  }

}
