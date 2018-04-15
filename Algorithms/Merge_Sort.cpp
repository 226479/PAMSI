//////
////// Created by karasiew on 15.03.18.
//////

#include "Merge_Sort.hpp"
//#include "../Helpers/Swap.Cpp"

void Merge_Sort::merge_sort(int *array, int first, int last) {
    if (first < last) {
        int _middle = first + (last - first) / 2;
        merge_sort(array, first, _middle);
        merge_sort(array, _middle + 1, last);
        merge(array, first, _middle, last);
    }
}

void Merge_Sort::merge(int *array, int first, int middle, int last) {
    int *tmp = new int [last-first+1];
    int i = first, j = middle + 1, k = 0;

    while (i <= middle && j <= last) {
        if (array[i] <= array[j])
            tmp[k++] = array[i++];
        else
            tmp[k++] = array[j++];
    }
    while (i <= middle)
        tmp[k++] = array[i++];

    while (j <= last)
        tmp[k++] = array[j++];

    k--;
    while (k >= 0) {
        array[first + k] = tmp[k];
        k--;
    }
    delete []tmp;
}

void Merge_Sort::run() {
    merge_sort(data, 0, data_size-1);
}

void Merge_Sort::prepare(int size, char file_input[]) {
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

void Merge_Sort::write_data(std::ofstream &file_output) {
    for (int i = 0; i < data_size; ++i) {
        file_output << data[i] << std::endl;
    }
}




