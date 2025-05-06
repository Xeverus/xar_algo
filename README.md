# Xar Algo

A repository of my implementation of different algorithms. 

## Build
Example debug build commands:

```
conan install . -pr config/conan/profiles/windows_x86_64-gcc11 --build=missing -s build_type=Debug
cmake --preset conan-debug
cmake --build --preset conan-debug
```