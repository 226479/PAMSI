set(HELPERS_SOURCES
    Time_Measurement.cpp
)

set(HELPERS_HEADERS
    Time_Measurement.hpp
        )

add_library(Helpers STATIC ${HELPERS_SOURCES} ${HELPERS_HEADERS})
