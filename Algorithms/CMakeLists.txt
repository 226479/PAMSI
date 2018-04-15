set(ALGORITH_SOURCES
        Quick_Sort.cpp
        Merge_Sort.cpp
        Hybrid_Sort.cpp
        Heap_Sort.cpp
        )

set(ALGORITHM_HEADERS
        Quick_Sort.hpp
        Merge_Sort.hpp
        Hybrid_Sort.hpp
        Heap_Sort.hpp
        )

add_library(Algorithms STATIC ${ALGORITH_SOURCES} ${ALGORITHM_HEADERS})
