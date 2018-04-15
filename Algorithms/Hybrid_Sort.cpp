//////
////// Created by karasiew on 15.03.18.
//////

#include "Hybrid_Sort.hpp"
#include <algorithm>

Hybrid_Sort::~Hybrid_Sort()
{
    if (data) {
        delete data;
    }
}

int Hybrid_Sort::partition(int *array, int first, int last) {
    int x=array[first],y=array[(last-first)/2+first],z=array[last-1],i=first-1,j=last;
    if (y>x && y<z || y>z && y<x ) x=y;
    else if (z>x && z<y || z>y && z<x ) x=z;
    while (1) {
        do  {j--;} while (array[j] > x);
        do  {i++;} while (array[i] < x);
        if  (i < j) std::swap(array[i],array[j]);
        else return j+1;
    }
}

void Hybrid_Sort::hybrid_sort(int *array, int first, int last) {
    if (last - first < 2) return;

    if(first < last){
        if((last - first) < 60)
        {
            insertion_sort(array,first,last);
        } else {
            int _pivot_idx = partition(array, first, last);

            hybrid_sort(array, first, _pivot_idx);
            hybrid_sort(array, _pivot_idx, last);
        }
    }
}

void Hybrid_Sort::run() {
    hybrid_sort(data, 0, data_size);
}

void Hybrid_Sort::prepare(int size, char file_input[]) {
    std::ifstream _input(file_input);
    if (_input.is_open()) {
        this->data_size = size;
        data = new int[data_size];
        for (int i = 0; i < data_size; ++i) {
            _input >> this->data[i];
        }

    } else {
        std::cout << "File not open properly" << std::endl;
    }
}

void Hybrid_Sort::write_data(std::ofstream &file_output) {
    for (int i = 0; i < data_size; ++i) {
        file_output << data[i] << std::endl;
    }
}


void Hybrid_Sort::insertion_sort(int *array, int first, int last) {
    for (int x = first + 1; x < last; x++)
    {
        int val = array[x];
        int j = x - 1;
        while (j >= 0 && val < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = val;
    }
}

