#include <iostream>
#include <fstream>
#include <math.h>
#include <chrono>
#include <string>
#include "sortAlgorithms.h"

using std::cout;
using std::endl;
using namespace std;

//These little functions are used by the heap-sort algorithm
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)



int main(){
    
    ifstream fsnumbers;
    fsnumbers.open ("/Users/viraj/Desktop/CSCI 2720 (Data)/sortingDataStructure/sorting/random.dat");
    
    int array[10];
    
    int counter = 0;
    while (counter < 10)
    {
        fsnumbers >> array[counter];
        cout << &fsnumbers;
        cout << endl;
        counter++;
    }
        }//end of main
    

    
    




//selection Sort

void sort::selectionSort(int list[], int size)
{
    int j = 0;
    int tmp = 0;
    for(int i=0;i<size;i++){
        j = i;
        for(int k = i;k<size;k++){
            if(list[j]>list[k]){
                j = k;
            }
        }
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
    }
}




// bubble-sort

void sort::bubble_sort(int list[], int size)
{
    int temp;
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>i; j--)
        {
            if(list[j]<list[j-1])
            {
                temp=list[j-1];
                list[j-1]=list[j];
                list[j]=temp;
            }
        }
    }
}


//Insertion sort

void sort::insertion_sort(int list[], int size)
{
    for(int j=1;j<size;j++)
    {
        int key=list[j];
        int i = j-1;
        while(i>-1 and list[i]>key)
        {
            list[i+1]=list[i];
            i=i-1;
        }
        list[i+1]=key;
        
    }
}

//Merge-sort

void sort::merge(int list[], int p, int q, int r)
{
    //n1 and n2 are the lengths of the pre-sorted sublists, list[p..q] and list[q+1..r]
    int n1=q-p+1;
    int n2=r-q;
    //copy these pre-sorted lists to L and R
    int L[n1+1];
    int R[n2+1];
    for(int i=0;i<n1; i++)
    {
        L[i]=list[p+i];
    }
    for(int j=0;j<n2; j++)
    {
        R[j]=list[q+1+j];
    }
    
    
    //Create a sentinal value for L and R that is larger than the largest
    //element of list
    int largest;
    if(L[n1-1]<R[n2-1]) largest=R[n2-1]; else largest=L[n1-1];
    L[n1]=largest+1;
    R[n2]=largest+1;
    
    //Merge the L and R lists
    int i=0;
    int j=0;
    for(int k=p; k<=r; k++)
    {
        if (L[i]<=R[j])
        {
            list[k]=L[i];
            i++;
        } else
        {
            list[k]=R[j];
            j++;
        }
    }
}

void merge_sort_aux(int list[], int p, int r)
{
    if(p<r)
    {
        int q=floor((p+r)/2);
        merge_sort_aux(list,p,q);
        merge_sort_aux(list,q+1,r);
       // merge(list,p,q,r);
    }
    
}

void merge_sort(int list[], int size)
{
    merge_sort_aux(list, 0, size - 1);
}

//Heap-sort................................................................

class heap
{
public:
    int *nodes;
    int length;
    int heap_size;
};

//max_heapify places the element list[index] into the subarray list[index+1...],
//which is assumed to already be in max-heap form

void max_heapify(heap list, int index)
{
    
    int left,right,largest,exchange_temp;
    
    left = LEFT(index);
    right = RIGHT(index);
    
    if(left <list.heap_size && list.nodes[left] > list.nodes[index])
    {
        largest = left;
    } else
    {
        largest = index;
    }
    
    if(right <list.heap_size && list.nodes[right] > list.nodes[largest])
    {
        largest = right;
    }
    
    
    if(largest != index)
    {
        exchange_temp = list.nodes[index];
        list.nodes[index] = list.nodes[largest];
        list.nodes[largest] = exchange_temp;
        max_heapify(list, largest);
    }
    
}

//build_max_heap turns an array into max-heap form by repeatedly calling
//max_heapify

void build_max_heap(heap list)
{
    list.heap_size = list.length;
    for(int i = floor(list.length/2); i>=0; i--)
    {
        max_heapify(list, i);
    }
}

//Since one property of a max-heap is that the first element is the largest,
//heap_sort swaps this element with the last element, then re-heapifies the
//rest, recursively until the whole array is sorted

void heap_sort(int list[], int size)
{
    int exchange_temp;
    heap tempheap;
    tempheap.length = size;
    tempheap.nodes = list;
    tempheap.heap_size = size;
    build_max_heap(tempheap);
    
    
    for(int i= tempheap.length - 1; i>=1; i--)
    {
        exchange_temp = tempheap.nodes[0];
        tempheap.nodes[0] = tempheap.nodes[i];
        tempheap.nodes[i] = exchange_temp;
        tempheap.heap_size = tempheap.heap_size - 1;
        
        max_heapify(tempheap,0);
    }
    
}

//Quicksort

int partition(int list[], int p, int r)
{
    int pivot, index, exchange_temp;
    pivot = list[r];
    index = p - 1;
    for(int i = p; i < r; i++)
    {
        if(list[i] <= pivot)
        {
            index++;
            exchange_temp = list[i];
            list[i] = list[index];
            list[index] = exchange_temp;
        }
    }
    exchange_temp = list[r];
    list[r] = list[index+1];
    list[index+1] = exchange_temp;
    return index+1;
}

void quicksort_aux(int list[], int p, int r)
{
    int q;
    if(p<r)
    {
        q = partition(list, p, r);
        quicksort_aux(list, p, q-1);
        quicksort_aux(list, q+1, r);
    }
}

void sort::quick_sort(int list[], int size)
{
    quicksort_aux(list,0, size-1);
}

