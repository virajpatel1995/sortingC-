//
//  sortAlgorithms.hpp
//  sorting
//
//  Created by Viraj patel on 11/22/16.
//  Copyright © 2016 Viraj Patel. All rights reserved.
//

#ifndef sortAlgorithms_h
#define sortAlgorithms_h

#include <stdio.h>


class sort{
    
public:

    void selectionSort(int list[], int size);
    
    void bubble_sort(int list[], int size);
    
    void insertion_sort(int list[], int size);
    
    void merge(int list[], int p, int q, int r);
    
    void quick_sort(int list[], int size);


    
};










#endif /* sortAlgorithms_hpp */
