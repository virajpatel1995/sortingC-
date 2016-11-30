#include <iostream>
#include <fstream>
#include <math.h>
#include <chrono>
#include <string>
#include <time.h>
#include "sortAlgorithms.h"

using std::cout;
using std::endl;
using namespace std;

//These little functions are used by the heap-sort algorithm
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)



//selection Sort

sort::sort() {
    int count = 0;
}

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
    for(int k = 0; k < size; k ++)
    {
        cout << list[k] << " ";
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
    for(int k = 0; k < size; k ++)
    {
        cout << list[k] << " ";
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
    for(int k = 0; k < size; k ++)
    {
        cout << list[k] << " ";
    }

}

void sort::merge(int array[], int min, int max, int mid)
{
    int firstIndex = min ;
    int secondIndex = mid + 1 ;
    int index = min ;
    int tempArray[max] ;
    
    // if there are still objects in both arrays
    while ((firstIndex <= mid) && (secondIndex <= max))
    {
        if (array[firstIndex] < array[secondIndex])
        {
            tempArray[index] = array[firstIndex] ;
            index++ ;
            firstIndex++ ;
        }
        else
        {
            tempArray[index] = array[secondIndex] ;
            index++ ;
            secondIndex++ ;
        }
    }
    
    
    
    // terminates the object of the lower array
    while (firstIndex <= mid)
    {
        tempArray[index] = array[firstIndex] ;
        index++ ;
        firstIndex++ ;
    }
    
    // terminates the object of the upper array
    while (secondIndex <= max)
    {
        tempArray[index] = array[secondIndex] ;
        index++ ;
        secondIndex++ ;
    }
    
    // transfer to the initial array
    for (int i = min ; i < index ; i++)
        array[i] = tempArray[i] ;
}

//Merge-sort

void mergeSort(int array[], int min, int max)
{
    sort::sort Sorting;
    // prerequisite
    if (min < max)
    {
        // get the middle point
        int mid = (int)floor((max+min)/2) ;
        
        // apply merge sort to both parts of this
        mergeSort(array, min, mid) ;
        mergeSort(array, mid+1, max) ;
        
        // and finally merge all that sorted stuff
        Sorting.merge(array, min, max, mid) ;
    }
    for(int k = 0; k < max; k ++)
    {
        cout << array[k] << " ";
    }

}

//Heap-sort................................................................


// returns the left node (by doubling the current node)
int leftNode(int node)
{
    return node << 1 ;	// this actually does 2*node
}

// returns the right node (by doubline the current node and adding 1)
int rightNode(int node)
{
    return (node << 1) + 1 ;	// this actually does 2*node+1
}

// return the parent node (by taking the half of the
// current node and returning its floor)
int parentNode(int node)
{
    return (int)floor(node/2) ;
}

// restore the heap property
void maxHeapify(int array[], int i, int heapSize)
{
    // get the two children nodes
    int left = leftNode(i) ;
    int right = rightNode(i) ;
    
    // assume that the largest is originally the current node
    int largest = i ;
    
    // check if the left node is the largest
    if (left <= heapSize && array[left] > array[i])
        largest = left ;
    
    // check if the right node is the largest
    if (right <= heapSize && array[right] > array[largest])
        largest = right ;
    
    // in case the left or right node was larger than the parent
    if (largest != i)
    {
        // we switch the parent with the largest child
        int temp = array[i] ;
        array[i] = array[largest] ;
        array[largest] = temp ;
        
        // and apply maxHeapify recursively to the subtree
        maxHeapify(array, largest, heapSize) ;
    }
}

// build the heap by looping through the array
void buildMaxHeap(int array[], int heapSize)
{
    for (int i = (int)floor(heapSize/2) ; i >= 0 ; i--)
        maxHeapify(array, i, heapSize) ;
}

void sort::heapSort(int array[], int arraySize)
{
    // determine the heap size
    int heapSize = arraySize ;
    
    // build the heap
    buildMaxHeap(array, heapSize) ;
    
    // loop through the heap
    for (int i = heapSize ; i > 0 ; i--)
    {
        // swap the root of the heap with the last element of the heap
        int temp = array[0] ;
        array[0] = array[i] ;
        array[i] = temp ;
        
        // decrease the size of the heap by one so that the previous
        // max value will stay in its proper placement
        heapSize-- ;
        
        // put the heap back in max-heap order
        maxHeapify(array, 0, heapSize) ;
    }
    for(int k = 0; k < arraySize; k ++)
    {
        cout << array[k] << " ";
    }

}

//Quicksort...............

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
    for(int k = 0; k < size; k ++)
    {
        cout << list[k] << " ";
    }
}



int main(){
    
    ifstream randomFile("/Users/viraj/Desktop/CSCI 2720 (Data)/sortingDataStructure/sorting/random.dat");
    ifstream inorderFile("/Users/viraj/Desktop/CSCI 2720 (Data)/sortingDataStructure/sorting/inorder.dat");
    ifstream reverseFile("/Users/viraj/Desktop/CSCI 2720 (Data)/sortingDataStructure/sorting/reverse.dat");
    sort::sort Sorter;
    
    if(randomFile.is_open()) {
        
        int array [] = {10, 100, 1000, 10000, 20000, 100000, 200000};
        
        int numbers[3][200000];
        
        //Store numbers from file to array.
        for(int j = 0; j < 200000; j++) {
            randomFile >> numbers[0][j];
            inorderFile >> numbers[1][j];
            reverseFile >> numbers[2][j];
        }
        
        //six algorithms
        for(int i = 0; i < 6; i++) {
            
            //different files
            for(int files = 0; files < 3; files++) {
                
                cout << "Moving to Output File " << files+1 << endl;
                
                //different size
                for(int size = 0; size < (sizeof(array)/sizeof(*array)); size++) {
                    
                    
                    
                    //selection
                    if(i == 0) {
                        cout << "SELECTION SORT -- " << array[size] << endl;
                        Sorter.selectionSort(numbers[files], array[size]);
                        cout << endl;
                    }
                    
                    if(i == 1) {
                        cout << "BUBBLE SORT -- " << array[size] << endl;
                        Sorter.bubble_sort(numbers[files], array[size]);
                        cout << endl;
                    }
                    
                    if(i == 2) {
                        cout << "INSERTION SORT -- " << array[size] << endl;
                        Sorter.insertion_sort(numbers[files], array[size]);
                        cout << endl;
                    }
                    
                    if(i == 3) {
                        cout << "MERGE SORT -- " << array[size] << endl;
                        Sorter.merge(numbers[files], 0, array[size]-1, ((array[size]-1)/2));
                        cout << endl;
                    }
                    
                    if(i == 4) {
                        cout << "QUICK SORT -- " << array[size] << endl;
                        Sorter.quick_sort(numbers[files], array[size]);
                        cout << endl;
                    }
                    
                    if(i == 5) {
                        cout << "HEAP SORT -- " << array[size] << endl;
                        Sorter.heapSort(numbers[files], array[size]);
                        cout << endl;
                    }
                }
            }
        }
    }
    
    //    int array[10];
    //
    //    int counter = 0;
    //    while (counter < 10)
    //    {
    //        fsnumbers >> array[counter];
    //        cout << &fsnumbers;
    //        cout << endl;
    //        counter++;
    //    }
    //        }//end of main
}
