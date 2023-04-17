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

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
    mergeSort(arr, 0, n-1);
	//para o tempo final
	gettimeofday(&t2, NULL);
	//imprimi o tempo em milisegundos								
	printf("\n Tempo de Execucao: ---> %lf \n",time_diff(t2, t1)/100000.0);		
	return 0;
}
