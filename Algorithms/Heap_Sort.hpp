//
// Created by karasiew on 02.04.2018.
//

#pragma once

#include "../Interfaces/Interfaces.hpp"
#include <fstream>

class Heap_Sort : public IRunnable, public IPreparable, public IWriteable {
    int data_size;
    int heap_size;
    int *data;

    void build_max_heap(int array[]);

    void max_heapify(int array[], int parent_idx);

    void heap_sort(int array[]);


public:

    void run() override;

    void prepare(int size, char file_input[]) override;

    void write_data(std::ofstream &file_output) override;
};
