//////
////// Created by karasiew on 15.03.18.
//////

#include "Quick_Sort.hpp"
#include <algorithm>


Quick_Sort::~Quick_Sort() {
    if (data) {
        delete data;
    }
}

int Quick_Sort::partition(int *array, int first, int last) {
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

void Quick_Sort::quick_sort(int *array, int first, int last) {
    if (last - first < 2) return;

    int _pivot_idx = partition(array, first, last);

    quick_sort(array, first, _pivot_idx);
    quick_sort(array, _pivot_idx, last);
}

void Quick_Sort::run() {
    quick_sort(data, 0, data_size);
}

void Quick_Sort::prepare(int size, char file_input[]) {
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

void Quick_Sort::write_data(std::ofstream &file_output) {
    for (int i = 0; i < data_size; ++i) {
        file_output << data[i] << std::endl;;
    }
}
