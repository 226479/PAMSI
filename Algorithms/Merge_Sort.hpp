//
// Created by karasiew on 02.04.2018.
//

#pragma once

#include "../Interfaces/Interfaces.hpp"
#include <fstream>

class Merge_Sort : public IRunnable, public IPreparable, public IWriteable {
    int data_size;
    int* data;

    void merge(int array[], int first, int middle, int last);

    void merge_sort(int array[], int first, int last);


public:

    void run() override;

    void prepare(int size,char file_input[]) override;

    void write_data(std::ofstream& file_output) override;
};
