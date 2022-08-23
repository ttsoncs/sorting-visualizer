#include "SortAlgorithms/binaryInsertionSort.h"
#include "SortAlgorithms/bitonicSort.h"
#include "SortAlgorithms/bubbleSort.h"
#include "SortAlgorithms/cocktailShakerSort.h"
#include "SortAlgorithms/combSort.h"
#include "SortAlgorithms/countingSort.h"
#include "SortAlgorithms/cycleSort.h"
#include "SortAlgorithms/evenOddSort.h"
#include "SortAlgorithms/gnomeSort.h"
#include "SortAlgorithms/heapSort.h"
#include "SortAlgorithms/insertionSort.h"
#include "SortAlgorithms/mergeSort.h"
#include "SortAlgorithms/pancakeSort.h"
#include "SortAlgorithms/quickSort.h"
#include "SortAlgorithms/radixSort.h"
#include "SortAlgorithms/selectionSort.h"
#include "SortAlgorithms/shellSort.h"
#include "SortAlgorithms/slowSort.h"
#include "SortAlgorithms/stoogeSort.h"
#include "SortAlgorithms/timSort.h"
#include "globalVariable.h"
#include "sortController.h"
#include "window.h"

int main() {
    Window window{SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE};
    window.setTargetFps(SCREEN_FPS);
    SortController sortController;
    while (!Window::windowShouldClose()) {
        if (Window::isKeyDown(KEY_ONE)) {
            sortController.setSortStrategy(
                std::make_unique<BinaryInsertionSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_TWO)) {
            sortController.setSortStrategy(
                std::make_unique<BitonicSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_THREE)) {
            sortController.setSortStrategy(
                std::make_unique<BubbleSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_FOUR)) {
            sortController.setSortStrategy(
                std::make_unique<CocktailShakerSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_FIVE)) {
            sortController.setSortStrategy(
                std::make_unique<CombSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_SIX)) {
            sortController.setSortStrategy(
                std::make_unique<CountingSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_SEVEN)) {
            sortController.setSortStrategy(
                std::make_unique<CycleSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_EIGHT)) {
            sortController.setSortStrategy(
                std::make_unique<EvenOddSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_NINE)) {
            sortController.setSortStrategy(
                std::make_unique<GnomeSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_ZERO)) {
            sortController.setSortStrategy(
                std::make_unique<HeapSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_Q)) {
            sortController.setSortStrategy(
                std::make_unique<InsertionSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_W)) {
            sortController.setSortStrategy(
                std::make_unique<MergeSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_E)) {
            sortController.setSortStrategy(
                std::make_unique<PancakeSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_R)) {
            sortController.setSortStrategy(
                std::make_unique<QuickSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_T)) {
            sortController.setSortStrategy(
                std::make_unique<RadixSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_Y)) {
            sortController.setSortStrategy(
                std::make_unique<SelectionSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_U)) {
            sortController.setSortStrategy(
                std::make_unique<ShellSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_I)) {
            sortController.setSortStrategy(
                std::make_unique<SlowSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_O)) {
            sortController.setSortStrategy(
                std::make_unique<StoogeSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_P)) {
            sortController.setSortStrategy(
                std::make_unique<TimSort>(VECTOR_SIZE));
        }

        if (Window::isKeyDown(KEY_SPACE)) {
            sortController.sort();
        }

        if (Window::isKeyDown(KEY_ESCAPE)) {
            break;
        }

        if (Window::isKeyDown(KEY_UP) && VECTOR_SIZE < 480) {
            VECTOR_SIZE += 2;
        }

        if (Window::isKeyDown(KEY_DOWN) && VECTOR_SIZE > 10) {
            VECTOR_SIZE -= 2;
        }

        BeginDrawing();
        EndDrawing();
    }
    return EXIT_SUCCESS;
}