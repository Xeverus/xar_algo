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
3. add new interval to the collection while ensuring that ranges are non-overlapping - merge ranges accordingly if required

### Union find

## Build
Example debug build commands:

```
conan install . -pr config/conan/profiles/windows_x86_64-gcc11 --build=missing -s build_type=Debug
cmake --preset conan-debug
cmake --build --preset conan-debug
```