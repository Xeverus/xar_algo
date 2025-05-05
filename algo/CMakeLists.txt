set(PUBLIC_FILES
        src/dummy.cpp)

set(PRIVATE_FILES
        include/dummy.hpp)

add_library(algo STATIC)

target_sources(algo
        PRIVATE
            ${PUBLIC_FILES}
            ${PRIVATE_FILES})

target_include_directories(algo
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src)


##############################
# Tests
##############################
add_subdirectory(test)