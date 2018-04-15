#include <iostream>
#include <chrono>
#include <cstring>
#include <iomanip>

#include "Algorithms/Quick_Sort.hpp"
#include "Algorithms/Merge_Sort.hpp"
#include "Algorithms/Hybrid_Sort.hpp"
#include "Algorithms/Heap_Sort.hpp"
#include "Helpers/Time_Measurement.hpp"

int main() {

    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    int size = (sizeof(sizes)/sizeof(*sizes));

    std::string names[] = {"random_", "identical_","sorted_","reversely_sorted_"};
    int name_size = (sizeof(names)/sizeof(names[0]));

    for (int j = 0; j < name_size ; ++j) {
        for (int i = 0; i < size; ++i) {

            Quick_Sort* quick_sort_program = new Quick_Sort();
            Merge_Sort* merge_sort_program = new Merge_Sort();
            Hybrid_Sort* hybrid_sort_program = new Hybrid_Sort();
            Heap_Sort* heap_sort_program = new Heap_Sort();

            std::string join = "Data/" + names[j] + std::to_string(sizes[i]);
            char *name = new char[join.length() + 1];
            strcpy(name, join.c_str());

            quick_sort_program->prepare(sizes[i], name);
            merge_sort_program->prepare(sizes[i], name);
            hybrid_sort_program->prepare(sizes[i], name);
            heap_sort_program->prepare(sizes[i], name);

            double score_quick=0;
            double score_merge=0;
            double score_hybrid=0;
            double score_heap=0;

//            score_quick = Time_Measure(quick_sort_program);
//            score_merge = Time_Measure(merge_sort_program);
//            score_hybrid = Time_Measure(hybrid_sort_program);
//            score_heap = Time_Measure(heap_sort_program);

            Averaged_Measure(quick_sort_program,score_quick);
            Averaged_Measure(merge_sort_program,score_merge);
            Averaged_Measure(hybrid_sort_program,score_hybrid);
            Averaged_Measure(heap_sort_program,score_heap);

            std::string quick_sort_output = "Data_Output/qsort_output_" + names[j] + std::to_string(sizes[i]);
            std::string merge_sort_output = "Data_Output/merge_output_" + names[j] + std::to_string(sizes[i]);
            std::string hybrid_sort_output = "Data_Output/hybrid_output_" + names[j] + std::to_string(sizes[i]);
            std::string heap_sort_output = "Data_Output/heap_output_" + names[j] + std::to_string(sizes[i]);

            char *qs_out = new char[quick_sort_output.length() + 1];
            char *ms_out = new char[merge_sort_output.length() + 1];
            char *hy_out = new char[hybrid_sort_output.length() + 1];
            char *hs_out = new char[heap_sort_output.length() + 1];

            strcpy(qs_out, quick_sort_output.c_str());
            strcpy(ms_out, merge_sort_output.c_str());
            strcpy(hy_out, hybrid_sort_output.c_str());
            strcpy(hs_out, heap_sort_output.c_str());

            std::ofstream qs_ofstream(qs_out);
            std::ofstream ms_ofstream(ms_out);
            std::ofstream hy_ofstream(hy_out);
            std::ofstream hs_ofstream(hs_out);

            quick_sort_program->write_data(qs_ofstream);
            merge_sort_program->write_data(ms_ofstream);
            hybrid_sort_program->write_data(hy_ofstream);
            heap_sort_program->write_data(hs_ofstream);
            
            std::cout.precision(10);
            std::cout << std::endl << name << std::endl;
            std::cout << " Quick: " << std::fixed  << score_quick << std::endl;
            std::cout << " Merge: " << std::fixed  << score_merge << std::endl;
            std::cout << " Hybrid: " << std::fixed  << score_hybrid << std::endl;
            std::cout << " Heap: " << std::fixed  << score_heap << std::endl;

            delete quick_sort_program;
            delete merge_sort_program;
            delete hybrid_sort_program;
            delete heap_sort_program;

            delete [] qs_out;
            delete [] ms_out;
            delete [] hy_out;
            delete [] hs_out;
        }
    }
    return 0;
}
