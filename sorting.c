#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000

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

printf("Mergesort Time: %f\n", secondsMerge);
printf("Insertionsort Time: %f\n", secondsInsertion);
printf("Heapsort Time: %f\n", secondsHeap);
printf("Bubblesort Time: %f\n", secondsBubble);
//printf("Quicksort Time: %f\n", secondsQuick);
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
  
// array是待调整的堆数组,i是待调整的数组元素的位置,nlength是数组的长度  
void HeapAdjust(int array[], int i, int nLength)  
{  
    int nChild, nTemp;  
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild)  
    {  
        // nChild:左子结点的位置是 父结点位置 * 2 + 1  nChild + 1： 右子结点   
        nChild = 2 * i + 1;  
        // 得到子结点中较大的结点  
        if (nChild != nLength - 1 && array[nChild + 1] > array[nChild])  
            ++nChild;  
        // 如果较大的子结点大于父结点那么把较大的子结点往上移动,替换它的父结点  
        if (nTemp < array[nChild])  
        {  
            array[i] = array[nChild];  
        }  
        else  // 否则退出循环  
        {  
            break;  
        }  
    }  
    // 最后把需要调整的元素值放到合适的位置  
    array[i] = nTemp;  
}  
// 堆排序算法  
void HeapSort(int array[], int length)  
{  
    // 调整序列的前半部分元素,（即每个有孩子的节点）调整完之后是一个大顶堆，第一个元素是序列的最大的元素  
    for (int i = length / 2 - 1; i >= 0; --i)  
    {  
        HeapAdjust(array, i, length);  
    }  
    // 从最后一个元素开始对序列进行调整,不断的缩小调整的范围直到第一个元素  
    for (int i = length - 1; i > 0; --i)  
    {  
        // 把第一个元素和当前的最后一个元素交换,  
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的  
        Swap(&array[0], &array[i]);  
        // 不断缩小调整heap的范围,每一次调整完毕保证第一个元素是当前序列的最大值  
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
