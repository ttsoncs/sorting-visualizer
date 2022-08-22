#include "SortAlgorithms/binaryInsertionSort.h"
#include "SortAlgorithms/bitonicSort.h"
#include "SortAlgorithms/bubbleSort.h"
#include "SortAlgorithms/cocktailShakerSort.h"
#include "SortAlgorithms/combSort.h"
#include "SortAlgorithms/cycleSort.h"
#include "SortAlgorithms/evenOddSort.h"
#include "SortAlgorithms/gnomeSort.h"
#include "SortAlgorithms/heapSort.h"
#include "SortAlgorithms/insertionSort.h"
#include "SortAlgorithms/mergeSort.h"
#include "SortAlgorithms/pancakeSort.h"
#include "SortAlgorithms/quickSort.h"
#include "SortAlgorithms/selectionSort.h"
#include "SortAlgorithms/shellSort.h"
#include "SortAlgorithms/slowSort.h"
#include "SortAlgorithms/stoogeSort.h"
#include "SortAlgorithms/timSort.h"
#include "sortController.h"
#include "window.h"

auto const SCREEN_WIDTH{1280};
auto const SCREEN_HEIGHT{720};
auto const SCREEN_FPS{50};
auto const SIZE{100};
std::string const WINDOW_TITLE{"Sort Visualizer"};

int main() {
    Window window{SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE};
    window.setTargetFps(SCREEN_FPS);
    SortController sortController;
    while (!Window::windowShouldClose()) {
        if (Window::isKeyDown(KEY_ONE)) {
            sortController.setSortStrategy(std::make_unique<BubbleSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_TWO)) {
            sortController.setSortStrategy(std::make_unique<InsertionSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_THREE)) {
            sortController.setSortStrategy(std::make_unique<SelectionSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_FOUR)) {
            sortController.setSortStrategy(
                std::make_unique<CocktailShakerSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_FIVE)) {
            sortController.setSortStrategy(std::make_unique<ShellSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_SIX)) {
            sortController.setSortStrategy(std::make_unique<MergeSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_SEVEN)) {
            sortController.setSortStrategy(std::make_unique<CombSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_EIGHT)) {
            sortController.setSortStrategy(std::make_unique<GnomeSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_NINE)) {
            sortController.setSortStrategy(std::make_unique<TimSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_ZERO)) {
            sortController.setSortStrategy(std::make_unique<QuickSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_Z)) {
            sortController.setSortStrategy(std::make_unique<StoogeSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_X)) {
            sortController.setSortStrategy(std::make_unique<CycleSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_C)) {
            sortController.setSortStrategy(std::make_unique<EvenOddSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_V)) {
            sortController.setSortStrategy(std::make_unique<PancakeSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_B)) {
            sortController.setSortStrategy(std::make_unique<HeapSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_N)) {
            sortController.setSortStrategy(
                std::make_unique<BinaryInsertionSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_M)) {
            sortController.setSortStrategy(std::make_unique<SlowSort>(20));
        }

        if (Window::isKeyDown(KEY_A)) {
            sortController.setSortStrategy(std::make_unique<BitonicSort>(SIZE));
        }

        if (Window::isKeyDown(KEY_SPACE)) { sortController.sort(); }

        if (Window::isKeyDown(KEY_ESCAPE)) { break; }

        BeginDrawing();
        EndDrawing();
    }
    return EXIT_SUCCESS;
}