#include "SortAlgorithms/Concurrent/bitonicSort.h"
#include "SortAlgorithms/Distribute/countingSort.h"
#include "SortAlgorithms/Distribute/radixSort.h"
#include "SortAlgorithms/Exchange/bubbleSort.h"
#include "SortAlgorithms/Exchange/cocktailShakerSort.h"
#include "SortAlgorithms/Exchange/combSort.h"
#include "SortAlgorithms/Exchange/gnomeSort.h"
#include "SortAlgorithms/Exchange/oddEvenSort.h"
#include "SortAlgorithms/Exchange/quickSort.h"
#include "SortAlgorithms/Exchange/slowSort.h"
#include "SortAlgorithms/Exchange/stoogeSort.h"
#include "SortAlgorithms/Hybrid/timSort.h"
#include "SortAlgorithms/Insert/binaryInsertionSort.h"
#include "SortAlgorithms/Insert/insertionSort.h"
#include "SortAlgorithms/Insert/shellSort.h"
#include "SortAlgorithms/Merge/mergeSort.h"
#include "SortAlgorithms/Misc/pancakeSort.h"
#include "SortAlgorithms/Select/cycleSort.h"
#include "SortAlgorithms/Select/heapSort.h"
#include "SortAlgorithms/Select/selectionSort.h"
#include "sortController.h"
#include "window.h"

int main() {
    Window window;
    Vector vector_;
    SortController sortController;
    while (!Window::windowShouldClose()) {
        if (Window::isKeyDown(KEY_ONE)) {
            sortController.setSortStrategy(std::make_unique<BinaryInsertionSort>());
        }

        if (Window::isKeyDown(KEY_TWO)) {
            sortController.setSortStrategy(std::make_unique<BitonicSort>());
        }

        if (Window::isKeyDown(KEY_THREE)) {
            sortController.setSortStrategy(std::make_unique<BubbleSort>());
        }

        if (Window::isKeyDown(KEY_FOUR)) {
            sortController.setSortStrategy(std::make_unique<OddEvenSort>());
        }

        if (Window::isKeyDown(KEY_FIVE)) {
            sortController.setSortStrategy(std::make_unique<GnomeSort>());
        }

        if (Window::isKeyDown(KEY_SIX)) {
            sortController.setSortStrategy(std::make_unique<SlowSort>());
        }

        if (Window::isKeyDown(KEY_SEVEN)) {
            sortController.setSortStrategy(std::make_unique<StoogeSort>());
        }

        if (Window::isKeyDown(KEY_EIGHT)) {
            sortController.setSortStrategy(std::make_unique<CombSort>());
        }

        if (Window::isKeyDown(KEY_NINE)) {
            sortController.setSortStrategy(std::make_unique<CocktailShakerSort>());
        }

        if (Window::isKeyDown(KEY_ZERO)) {
            sortController.setSortStrategy(std::make_unique<CountingSort>());
        }

        if (Window::isKeyDown(KEY_Q)) {
            sortController.setSortStrategy(std::make_unique<TimSort>());
        }

        if (Window::isKeyDown(KEY_W)) {
            sortController.setSortStrategy(std::make_unique<InsertionSort>());
        }

        if (Window::isKeyDown(KEY_E)) {
            sortController.setSortStrategy(std::make_unique<ShellSort>());
        }

        if (Window::isKeyDown(KEY_R)) {
            sortController.setSortStrategy(std::make_unique<MergeSort>());
        }

        if (Window::isKeyDown(KEY_T)) {
            sortController.setSortStrategy(std::make_unique<PancakeSort>());
        }

        if (Window::isKeyDown(KEY_Y)) {
            sortController.setSortStrategy(std::make_unique<CycleSort>());
        }

        if (Window::isKeyDown(KEY_U)) {
            sortController.setSortStrategy(std::make_unique<HeapSort>());
        }

        if (Window::isKeyDown(KEY_I)) {
            sortController.setSortStrategy(std::make_unique<SelectionSort>());
        }

        if (Window::isKeyDown(KEY_O)) {
            sortController.setSortStrategy(std::make_unique<RadixSort>());
        }

        if (Window::isKeyDown(KEY_P)) {
            sortController.setSortStrategy(std::make_unique<QuickSort>());
        }

        if (Window::isKeyDown(KEY_SPACE)) {
            sortController.sort();
        }

        if (Window::isKeyDown(KEY_ESCAPE)) {
            break;
        }

        if (Window::isKeyDown(KEY_UP)) {
            Vector::incrementVectorSize();
        }

        if (Window::isKeyDown(KEY_DOWN)) {
            Vector::decrementVectorSize();
        }

        if (Window::isKeyDown(KEY_LEFT)) {
            Window::decrementFps();
        }

        if (Window::isKeyDown(KEY_RIGHT)) {
            Window::incrementFps();
        }

        if (Window::isKeyDown(KEY_Z)) {
            Vector::randomShuffle();
        }

        if (Window::isKeyDown(KEY_X)) {
            Vector::reverseSortedShuffle();
        }

        if (Window::isKeyDown(KEY_C)) {
            Vector::almostSortedShuffle();
        }

        BeginDrawing();
        EndDrawing();
    }
    return EXIT_SUCCESS;
}