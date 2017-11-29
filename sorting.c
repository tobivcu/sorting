#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 200000

void mergesort(int a[], size_t top, size_t bottom);
void merge(int a[], size_t top, size_t bottom);
void insertionsort(int a[], size_t length);
void quicksort(int data[], size_t i, size_t j);
int partition(int data[], size_t i, size_t j);
//void heap_sort(int a[], int n);
//void creat_heap(int a[], int n);
void HeapSort(int array[], int length);  
void HeapAdjust(int array[], int i, int nLength);  
void Swap( int *num_a, int *num_b);
void bubblesort(int a[], int n);
  
int main(void)
{
int array1[SIZE];
for(size_t i = 0; i < SIZE; ++i)
{
array1[i] = rand() % SIZE;
}
int arrayMerge[SIZE];
for(size_t i = 0; i < SIZE; ++i)
{
arrayMerge[i] = array1[i];
}
int arrayInsertion[SIZE];
for(size_t i = 0; i < SIZE; ++i)
{
arrayInsertion[i] = array1[i];
}
int arrayQuick[SIZE];
for(size_t i = 0; i < SIZE; ++i)
{
arrayQuick[i] = array1[i];
}
int arrayHeap[SIZE];
for(size_t i = 0; i< SIZE; ++i)
{
arrayHeap[i] = array1[i];
}
int arrayBubble[SIZE];
for(size_t i = 0; i< SIZE; ++i)
{
arrayBubble[i] = array1[i];
}

clock_t startMerge = clock();
mergesort(arrayMerge, 0, SIZE - 1);
clock_t endMerge = clock();

clock_t startInsertion = clock();
insertionsort(arrayInsertion, SIZE);
clock_t endInsertion = clock();

clock_t startHeap = clock();
HeapSort(arrayHeap, SIZE);
clock_t endHeap = clock();

clock_t startBubble = clock();
bubblesort(arrayBubble, SIZE);
clock_t endBubble = clock();

clock_t startQuick = clock();
//quicksort(arrayQuick, 0, SIZE - 1);
clock_t endQuick = clock();

float secondsMerge = (float)(endMerge - startMerge) / CLOCKS_PER_SEC;
float secondsInsertion = (float)(endInsertion - startInsertion) / CLOCKS_PER_SEC;
float secondsHeap = (float)(endHeap - startHeap) / CLOCKS_PER_SEC;
float secondsQuick = (float)(endQuick - startQuick) / CLOCKS_PER_SEC;
float secondsBubble = (float)(endBubble - startBubble) / CLOCKS_PER_SEC;

/* Print out the sorted results
printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
printf("Before sorting, the array is as follows:\n");

int count;
for(count =0; count < SIZE; count++)
{
	printf("%d ", array1[count]);
}
printf("\nAfter sorting:");
printf("\n---------------------------------");

printf("\nMergesort Time: %f, the sorted result is:\n", secondsMerge);
for(count =0; count < SIZE; count++)
{
        printf("%d ", arrayMerge[count]);
}
printf("\n---------------------------------");

printf("\nInsertionsort Time: %f, the sorted result is\n", secondsInsertion);
for(count =0; count < SIZE; count++)
{
        printf("%d ", arrayInsertion[count]);
}
printf("\n---------------------------------");

printf("\nHeapsort Time: %f, the sorted result is\n", secondsHeap);
for(count =0; count < SIZE; count++)
{
        printf("%d ", arrayHeap[count]);
}
printf("\n---------------------------------");

printf("\nBubblesort Time: %f, the sorted result is\n", secondsBubble);
for(count =0; count < SIZE; count++)
{
        printf("%d ", arrayBubble[count]);
}
printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
printf("\n");
//printf("Quicksort Time: %f\n", secondsQuick);
*/
printf("Mergesort Time: %f\n", secondsMerge);
printf("Insertionsort Time: %f\n", secondsInsertion);
printf("Heapsort Time: %f\n", secondsHeap);
printf("Bubblesort Time: %f\n", secondsBubble);
}

void mergesort(int a[], size_t top, size_t bottom)
    {
        if (top != bottom)
        {
            int middle = (top + bottom) / 2;
            mergesort(a, top, middle);
            mergesort(a, middle + 1, bottom);
            merge(a, top, bottom);
        }
    }
     
    void merge(int a[], size_t top, size_t bottom)
    {
        size_t t = top;
        size_t middle = (top + bottom) / 2;
        size_t b = middle + 1;
        size_t i = 0;
	size_t length = bottom - top + 1;
        int s[length];
        while((t <= middle) && (b <= bottom))
        {
            if(a[t] < a[b])
            {
                s[i] = a[t];
                ++t;
            }
            else
            {
                s[i] = a[b];
		++b;
            }
            ++i;
        }
        size_t last = middle;
        if(b <= bottom)
        {
            t = b;
            last = bottom;
        }
        while(t <= last)
        {
            s[i] = a[t];
            ++t;
            ++i;
        }
        for(i = 0; i < length; i++)
        {
            a[i + top] = s[i];
        }
    }
     
    void insertionsort(int a[], size_t length)
    {
        for(size_t i = 1; i < length; ++i)
        {
            for(size_t j = i; j > 0; --j)
            {
                if(a[j] < a[j - 1])
                {
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
            }
        }
    }
     
    void quicksort(int data[], size_t i, size_t j)
    {
        int p;
        if(i < j)
        {
            p = partition(data, i, j);
            quicksort(data, i, p - 1);
            quicksort(data, p + 1, j);
        }
    }
     
    int partition(int data[], size_t i, size_t j)
    {
        size_t upper = i;
        size_t lower = j;
        int save = data[i];
        while(upper < lower)
        {
            while((upper < lower) && (save <= data[lower]))
            {
                lower--;
            }
            if(upper < lower)
            {
                data[upper++] = data[lower];
            }
            while((upper < lower) && (save >= data[upper]))
            {
                upper++;
            }
            if(upper < lower)
            {
                data[lower--] = data[upper];
            }
       }
       data[upper] = save;
       return upper;
    }

void Swap( int *num_a, int *num_b )  
{  
    int temp = *num_b;  
    *num_b = *num_a;  
    *num_a = temp;  
}  
  
void HeapAdjust(int array[], int i, int nLength)  
{  
    int nChild, nTemp;  
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild)  
    {  
        nChild = 2 * i + 1;  
        if (nChild != nLength - 1 && array[nChild + 1] > array[nChild])  
            ++nChild;  
        if (nTemp < array[nChild])  
        {  
            array[i] = array[nChild];  
        }  
        else         {  
            break;  
        }  
    }  
    array[i] = nTemp;  
}  
void HeapSort(int array[], int length)  
{  
    for (int i = length / 2 - 1; i >= 0; --i)  
    {  
        HeapAdjust(array, i, length);  
    }  
    for (int i = length - 1; i > 0; --i)  
    {  
        Swap(&array[0], &array[i]);  
        HeapAdjust(array, 0, i);  
    }  
}  
void bubblesort(int a[], int n)
{
  long c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (a[d] > a[d+1])
      {
        /* Swapping */
 
        t         = a[d];
        a[d]   = a[d+1];
        a[d+1] = t;
      }
    }
  }
}
