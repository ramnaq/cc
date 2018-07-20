/* C implementation QuickSort */
#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define LIM 5550
int a[LIM];
int l[LIM];
int p[LIM];
int caixas[3*LIM];
int mem[LIM];
int n;


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
            swap(&a[i], &a[j]);
            swap(&l[i], &l[j]);
            swap(&p[i], &p[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void preencher() {
    for (int i = 0; i < n; ++i)
        caixas[i] = a[i%n] * l[i%n];
    for (int i = n; i < n*2; ++i) {
        caixas[i] = a[i%n] * p[i%n];
        a[i] = a[i%n];
        l[i] = l[i%n];
        p[i] = p[i%n];
    }
    for (int i = n*2; i < n*3; ++i) {
        caixas[i] = l[i%n] * p[i%n];
        a[i] = a[i%n];
        l[i] = l[i%n];
        p[i] = p[i%n];
    }
}

int maior_altura() {
    for (int i = 0; i < 3*n; ++i)
        mem[i] = a[i % n];

    for (int i = 1; i < 3*n; ++i)
        for (int j = 0; j < i; ++j)
            if (p[j] > p[i] && l[j] > l[i])
                mem[i] = MAX(mem[i], mem[j] + a[i]);

    int max = 0;
    for (int i = 0; i < 3*n; ++i)
        if (mem[i] > max)
            max = mem[i];

    return max;
}

void main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            scanf("%d", &l[i]);
            scanf("%d", &p[i]);
        }

        preencher(n);
        quickSort(caixas, 0, 3*n - 1);

        printf("%d\n", maior_altura(n));
    }
}