//
// Created by karasiew on 02.04.2018.
//
#include <chrono>

#include "Time_Measurement.hpp"

double Time_Measure(IRunnable* program)
{
    auto start = std::chrono::high_resolution_clock::now();

    program->run();

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}

void Averaged_Measure(IRunnable* program, double& averaged_measure)
{
    const int counter = 10;
    double *measurement_table = new double [counter];

    for (int i = 0; i < counter; ++ i) {
        measurement_table[i] = Time_Measure(program);
        averaged_measure += measurement_table[i];
    }

    averaged_measure = (averaged_measure / counter);
    delete[] measurement_table;
}
