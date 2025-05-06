set(PUBLIC_FILES
        # dummy
        src/xar_algo/dummy.cpp)

set(PRIVATE_FILES
        # dummy
        include/xar_algo/dummy.hpp
        # interval
        include/xar_algo/interval/interval.hpp
        include/xar_algo/interval/interval_container.hpp)

add_library(xar_algo STATIC)

target_sources(xar_algo
        PRIVATE
            ${PUBLIC_FILES}
            ${PRIVATE_FILES})

target_include_directories(xar_algo
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src)


##############################
# Tests
##############################
add_subdirectory(test)