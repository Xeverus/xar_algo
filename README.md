# Xar Algo

## Description
A repository of my implementation of different algorithms. 

## Algorithms

### Interval container
Container which stores a set of non-overlapping intervals. 
Each interval is a range defined by two values - beginning and end of the interval.
Both ends of interval are included in the range (lower and upper bound values are part of the range).

Implemented functions:
1. check if a given value belongs to any interval in the collection
2. find all intervals in the collection which overlap with a given interval
3. add new interval to the collection while ensuring that ranges are non-overlapping - merge ranges accordingly if
required

### Union find
Union find algorithm with trees merging optimization. 
The optimization uses tree sizes of both trees to determine which tree should be a child tree and which should be a
parent tree. 

Implemented functions:
1. finding topmost value for a given value (topmost parent)
2. checking if two values are connected
3. connecting two values

### Quick sort
Quick sort implementation which supports custom value comparator.

### Partition
Partition a range of numbers using given pivot value and value comparator.

## Environment setup and Build process
Example debug build commands:

### install
```
CMAKE_POLICY_VERSION_MINIMUM=3.5 conan install . --profile:build=config/conan/profiles/linux_x86_64-gcc11 --profile:host=config/conan/profiles/linux_x86_64-gcc11 --build=missing -s build_type=Debug
```

### build
```
cmake --preset conan-debug
cmake --build --preset conan-debug
```