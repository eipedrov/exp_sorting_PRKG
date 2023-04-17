#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

struct timeval t1, t2;
double elapsedTime;
/*para o calculo do tempo*/
unsigned long time_diff(struct timeval a, struct timeval b){
	struct timeval res;
	timersub(&a, &b, &res);
	return res.tv_sec * 1000000 + res.tv_usec;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(int argc, char **argv){
	FILE *fp;

	/* Testa os argumentos da linha de comando */
	if(argc!=2){
		printf("Uso: %s <arquivo>\n", argv[0]);
		exit(0);
	}
	fp=fopen(argv[1],"r");	
   
    int *arr = NULL;
    int num,n = 0;
 

    while (fscanf(fp, "%d", &num) == 1) {
        n++;
        arr = realloc(arr,n * sizeof(int));
        arr[n - 1] = num;
    }

	//para o tempo inicial
	gettimeofday(&t1, NULL);
    quicksort(arr, 0, n-1);
	//para o tempo final
	gettimeofday(&t2, NULL);
	//imprimi o tempo em milisegundos								
	printf("\n Tempo de Execucao: ---> %lf \n",time_diff(t2, t1)/100000.0);		
	return 0;
}
