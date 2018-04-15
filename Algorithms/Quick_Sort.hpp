//
// Created by karasiew on 02.04.2018.
//

#pragma once

#include "../Interfaces/Interfaces.hpp"
#include <fstream>

class Quick_Sort : public IRunnable, public IPreparable, public IWriteable {
    int data_size{0};
    int* data{nullptr};

    int partition(int array[], int first, int last);

    void quick_sort(int array[], int first, int last);

public:
    ~Quick_Sort();

    void run() override;

    void prepare(int size,char file_input[]) override;

    void write_data(std::ofstream& file_output) override;
};
