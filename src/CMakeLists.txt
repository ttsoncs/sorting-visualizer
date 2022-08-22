cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Os -lraylib -lGL -lm -lpthread -ldl -lrt -lX11" )

include_directories(.)
include_directories(SortAlgorithms)

add_executable(src
        SortAlgorithms/bubbleSort.h
        SortAlgorithms/cocktailSort.h
        SortAlgorithms/combSort.h
        SortAlgorithms/cycleSort.h
        SortAlgorithms/evenOddSort.h
        SortAlgorithms/gnomeSort.h
        SortAlgorithms/heapSort.h
        SortAlgorithms/insertionSort.h
        SortAlgorithms/mergeSort.h
        SortAlgorithms/pancakeSort.h
        SortAlgorithms/quickSort.h
        SortAlgorithms/selectionSort.h
        SortAlgorithms/shellSort.h
        SortAlgorithms/stoogeSort.h
        SortAlgorithms/timSort.h
        main.cpp
        sortController.h
        sortStrategy.h
        vector.h
        visualize.h
        window.h)
