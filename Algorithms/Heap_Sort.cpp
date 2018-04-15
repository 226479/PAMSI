//////
////// Created by karasiew on 15.03.18.
//////

#include "Heap_Sort.hpp"
#include <algorithm>


void Heap_Sort::run() {
    heap_sort(data);
}

void Heap_Sort::prepare(int size, char file_input[]) {
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

void Heap_Sort::write_data(std::ofstream &file_output) {
    for (int i = 0; i < data_size; ++i) {
        file_output << data[i] << std::endl;
    }
}

void Heap_Sort::build_max_heap(int *array) {
    heap_size = data_size - 1;
    for (int i = (data_size - 1) / 2; i >= 0; --i) {
        max_heapify(array, i);
    }
}

void Heap_Sort::heap_sort(int *array) {
    build_max_heap(array);
    for (int i = (data_size - 1); i >= 0; i--) {
        std::swap(array[0],array[i]);
        --heap_size;
        max_heapify(array, 0);
    }
}

void Heap_Sort::max_heapify(int array[], int parent_idx) {
    int l = 2 * (parent_idx + 1) - 1;
    int r = 2 * (parent_idx + 1);
    int largest;
    if (l <= heap_size && array[l] > array[parent_idx]) {
        largest = l;
    } else {
        largest = parent_idx;
    }
    if (r <= heap_size && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != parent_idx) {
        std::swap(array[parent_idx],array[largest]);
        max_heapify(array, largest);
    }
}
