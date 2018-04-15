//
// Created by karasiew on 02.04.2018.
//

#pragma once

#include "../Interfaces/Interfaces.hpp"
#include "Quick_Sort.hpp"
#include <fstream>

class Hybrid_Sort : public IRunnable, public IPreparable, public IWriteable {
    int data_size{0};
    int* data{nullptr};

    void insertion_sort(int array[], int first, int last);

    int median_of_three(int& x, int& y, int& z);

    int partition(int array[], int first, int last);

    void hybrid_sort(int array[], int first, int last);

public:
    ~Hybrid_Sort();

    void run() override;

    void prepare(int size,char file_input[]) override;

    void write_data(std::ofstream& file_output) override;
};
