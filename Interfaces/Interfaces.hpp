//
// Created by karasiew on 02.04.2018.
//

#pragma once

#include <iostream>

class IRunnable {
public:
    virtual ~IRunnable() = default;
    virtual void run() = 0;
};

class IPreparable {
public:
    virtual ~IPreparable() = default;
    virtual void prepare(int size, char file_input[]) = 0;
};

class IWriteable {
public:
    virtual ~IWriteable() = default;
    virtual void write_data(std::ofstream& writehere) = 0;
};
