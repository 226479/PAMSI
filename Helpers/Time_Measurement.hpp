//
// Created by karasiew on 02.04.2018.
//

#pragma once

#include "../Interfaces/Interfaces.hpp"

double Time_Measure(IRunnable *program);

void Averaged_Measure(IRunnable *program, double &averaged_measure);
