#include <iostream>
#include <fstream>
#include <math.h>
#include <chrono>
#include <string>
#include <ctime>
#include "sortAlgorithms.h"

using std::cout;
using std::endl;
using namespace std;

//These little functions are used by the heap-sort algorithm
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)



//selection Sort

void sort::selectionSort(int list[], int size)
{
    int temp[size];
    for(int n = 0;n < size; n++)
    {
        temp[n] = list [n];
    }
    int start = clock();
    int j = 0;
    int tmp = 0;
    for(int i=0;i<size;i++){
        j = i;
        for(int k = i;k<size;k++){
            if(temp[j]>temp[k]){
                j = k;
            }
        }
        tmp = temp[i];
        temp[i] = temp[j];
        temp[j] = tmp;
    }
    int stop = clock();
    cout << "Selection Sort Took: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << "ms for Size of " << size << endl;
    for(int k = 0; k < size; k ++)
    {
        cout << temp[k] << " ";
    }
}




// bubble-sort

void sort::bubble_sort(int list[], int size)
{
    int temp2[size];
    for(int n = 0;n < size; n++)
    {
        temp2[n] = list [n];
    }
    int start = clock();
    int temp;
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>i; j--)
        {
            if(temp2[j]<temp2[j-1])
            {
                temp=temp2[j-1];
                temp2[j-1]=temp2[j];
                temp2[j]=temp;
            }
        }
    }
    int stop = clock();
    cout << "Bubble Sort Took: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << "ms for Size of " << size << endl;
    for(int k = 0; k < size; k ++)
    {
        cout << temp2[k] << " ";
    }
}


//Insertion sort

void sort::insertion_sort(int list[], int size)
{
    int temp[size];
    for(int n = 0;n < size; n++)
    {
        temp[n] = list [n];
    }
    int start = clock();
    for(int j=1;j<size;j++)
    {
        int key=temp[j];
        int i = j-1;
        while(i>-1 and temp[i]>key)
        {
            temp[i+1]=temp[i];
            i=i-1;
        }
        temp[i+1]=key;
    }
    int stop = clock();
    cout << "Insertion Sort Took: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << "ms for Size of " << size << endl;
    for(int k = 0; k < size; k ++)
    {
        cout << temp[k] << " ";
    }

}

void sort::merge(int array[], int min, int max, int mid)
{
    int temp[max+1];
    for(int n = 0;n < max+1; n++)
    {
        temp[n] = array[n];
    }
    int start = clock();
    int firstIndex = min ;
    int secondIndex = mid + 1 ;
    int index = min ;
    int tempArray[max] ;
    
    // if there are still objects in both arrays
    while ((firstIndex <= mid) && (secondIndex <= max))
    {
        if (temp[firstIndex] < temp[secondIndex])
        {
            tempArray[index] = temp[firstIndex] ;
            index++ ;
            firstIndex++ ;
        }
        else
        {
            tempArray[index] = temp[secondIndex] ;
            index++ ;
            secondIndex++ ;
        }
    }
    
    
    
    // terminates the object of the lower array
    while (firstIndex <= mid)
    {
        tempArray[index] = temp[firstIndex] ;
        index++ ;
        firstIndex++ ;
    }
    
    // terminates the object of the upper array
    while (secondIndex <= max)
    {
        tempArray[index] = temp[secondIndex] ;
        index++ ;
        secondIndex++ ;
    }
    
    // transfer to the initial array
    for (int i = min ; i < index ; i++) {
        temp[i] = tempArray[i] ;
    }
    int stop = clock();
    cout << "Merge Sort Took: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << "ms for Size of " << max+1 << endl;
    
    for(int k = 0; k < max+1; k ++)
    {
        cout << temp[k] << " ";
    }

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
    int temp2[arraySize];
    for(int n = 0;n < arraySize; n++)
    {
        temp2[n] = array[n];
    }
    int start = clock();
    // determine the heap size
    int heapSize = arraySize ;
    
    // build the heap
    buildMaxHeap(temp2, heapSize) ;
    
    // loop through the heap
    for (int i = heapSize ; i > 0 ; i--)
    {
        // swap the root of the heap with the last element of the heap
        int temp = temp2[0] ;
        temp2[0] = temp2[i] ;
        temp2[i] = temp ;
        
        // decrease the size of the heap by one so that the previous
        // max value will stay in its proper placement
        heapSize-- ;
        
        // put the heap back in max-heap order
        maxHeapify(temp2, 0, heapSize) ;
    }
    int stop = clock();
    cout << "Heap Sort Took: " << (stop-start)/double(CLOCKS_PER_SEC)*1000<< "ms for Size of " << arraySize << endl;
    
    for(int k = 0; k < arraySize; k ++)
    {
        cout << temp2[k] << " ";
    }

}

//Quicksort...............

int partition(int array[], int min, int max)
{
    // define a pivot as the max item of the (sub)array
    int pivot = array[max] ;
    int i = min - 1 ;
    // loop through the elements of the (sub)array
    for (int j = min ; j < max ; j++)
    {
        // in case the element has a smaller value that the pivot
        // bring it in front of it (larger elements will come after it)
        if (array[j] <= pivot)
        {
            i++ ;
            int temp = array[i] ;
            array[i] = array[j] ;
            array[j] = temp ;
        }
    }
    // bring the pivot to its correct position
    int temp = array[i+1] ;
    array[i+1] = array[max] ;
    array[max] = temp ;
    
    return i+1 ;
}

void sort::quickSort(int array[], int min, int max)
{
    int temp[max+1];
    for(int n = 0;n < max+1; n++)
    {
        temp[n] = array[n];
    }
    if (min < max)
    {
        // partition the array in two parts
        int q = partition(temp, min, max) ;
        // apply QuickSort recursively to both parts
        quickSort(temp, min, q-1) ;
        quickSort(temp, q+1, max) ;
    }
    for(int k = 0; k < max+1; k ++)
    {
        cout << temp[k] << " ";
    }
}
//..........................

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
                        int start = clock();
                        Sorter.quickSort(numbers[files], 0, array[size]-1);
                        int stop = clock();
                        cout << "Quick Sort Took: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << "ms for Size of " << array[size] << endl;

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
