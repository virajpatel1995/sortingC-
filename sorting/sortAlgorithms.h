//
//  sortAlgorithms.hpp
//  sorting
//
//  Created by Viraj patel on 11/22/16.
//  Copyright © 2016 Viraj Patel. All rights reserved.
//

#include <stdio.h>

#ifndef sortAlgorithms_h
#define sortAlgorithms_h


class sort{
    
public:

    void selectionSort(int list[], int size);
    
    void bubble_sort(int list[], int size);
    
    void insertion_sort(int list[], int size);
    
    void merge(int array[], int min, int max, int mid);
    
    void quickSort(int array[], int min, int max);

    void heapSort(int array[], int arraySize);
    
};



#endif

