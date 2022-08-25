#include "SortAlgorithms/Concurrent/bitonicSort.h"
#include "SortAlgorithms/Distribute/pigeonholeSort.h"
#include "SortAlgorithms/Distribute/radixSort.h"
#include "SortAlgorithms/Exchange/binaryGnomeSort.h"
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
        if (Window::isKeyPressed(KEY_ONE)) {
            sortController.setSortStrategy(std::make_unique<BinaryInsertionSort>());
        }

        if (Window::isKeyPressed(KEY_TWO)) {
            sortController.setSortStrategy(std::make_unique<BitonicSort>());
        }

        if (Window::isKeyPressed(KEY_THREE)) {
            sortController.setSortStrategy(std::make_unique<BubbleSort>());
        }

        if (Window::isKeyPressed(KEY_FOUR)) {
            sortController.setSortStrategy(std::make_unique<OddEvenSort>());
        }

        if (Window::isKeyPressed(KEY_FIVE)) {
            sortController.setSortStrategy(std::make_unique<GnomeSort>());
        }

        if (Window::isKeyPressed(KEY_SIX)) {
            sortController.setSortStrategy(std::make_unique<SlowSort>());
        }

        if (Window::isKeyPressed(KEY_SEVEN)) {
            sortController.setSortStrategy(std::make_unique<StoogeSort>());
        }

        if (Window::isKeyPressed(KEY_EIGHT)) {
            sortController.setSortStrategy(std::make_unique<CombSort>());
        }

        if (Window::isKeyPressed(KEY_NINE)) {
            sortController.setSortStrategy(std::make_unique<CocktailShakerSort>());
        }

        if (Window::isKeyPressed(KEY_ZERO)) {
            sortController.setSortStrategy(std::make_unique<PigeonholeSort>());
        }

        if (Window::isKeyPressed(KEY_Q)) {
            sortController.setSortStrategy(std::make_unique<TimSort>());
        }

        if (Window::isKeyPressed(KEY_W)) {
            sortController.setSortStrategy(std::make_unique<InsertionSort>());
        }

        if (Window::isKeyPressed(KEY_E)) {
            sortController.setSortStrategy(std::make_unique<ShellSort>());
        }

        if (Window::isKeyPressed(KEY_R)) {
            sortController.setSortStrategy(std::make_unique<MergeSort>());
        }

        if (Window::isKeyPressed(KEY_T)) {
            sortController.setSortStrategy(std::make_unique<PancakeSort>());
        }

        if (Window::isKeyPressed(KEY_Y)) {
            sortController.setSortStrategy(std::make_unique<CycleSort>());
        }

        if (Window::isKeyPressed(KEY_U)) {
            sortController.setSortStrategy(std::make_unique<HeapSort>());
        }

        if (Window::isKeyPressed(KEY_I)) {
            sortController.setSortStrategy(std::make_unique<SelectionSort>());
        }

        if (Window::isKeyPressed(KEY_O)) {
            sortController.setSortStrategy(std::make_unique<RadixSort>());
        }

        if (Window::isKeyPressed(KEY_P)) {
            sortController.setSortStrategy(std::make_unique<QuickSort>());
        }

        if (Window::isKeyPressed(KEY_A)) {
            sortController.setSortStrategy(std::make_unique<BinaryGnomeSort>());
        }

        if (Window::isKeyPressed(KEY_SPACE)) {
            sortController.sort();
        }

        if (Window::isKeyDown(KEY_ESCAPE)) {
            break;
        }

        if (Window::isKeyPressed(KEY_UP)) {
            Vector::incrementVectorSize();
        }

        if (Window::isKeyPressed(KEY_DOWN)) {
            Vector::decrementVectorSize();
        }

        if (Window::isKeyDown(KEY_LEFT)) {
            Window::decrementFps();
        }

        if (Window::isKeyDown(KEY_RIGHT)) {
            Window::incrementFps();
        }

        if (Window::isKeyPressed(KEY_Z)) {
            Vector::randomShuffle();
        }

        if (Window::isKeyPressed(KEY_X)) {
            Vector::reverseSortedShuffle();
        }

        if (Window::isKeyPressed(KEY_C)) {
            Vector::almostSortedShuffle();
        }

        if (Window::isKeyPressed(KEY_V)) {
            Visualize::visualizeStyle(Vector::getVector());
        }

        Window::beginDrawing();
        Window::endDrawing();
    }
    return EXIT_SUCCESS;
}