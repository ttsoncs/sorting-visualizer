#include "Sort/bubbleSort.h"
#include "Sort/cocktailSort.h"
#include "Sort/combSort.h"
#include "Sort/gnomeSort.h"
#include "Sort/insertionSort.h"
#include "Sort/mergeSort.h"
#include "Sort/selectionSort.h"
#include "Sort/shellSort.h"
#include "Sort/timSort.h"
#include "Sort/heapSort.h"
#include "sortController.h"
#include "window.h"

int constexpr SCREEN_WIDTH = 1280;
int constexpr SCREEN_HEIGHT = 720;
int constexpr SCREEN_FPS = 60;
std::string const WINDOW_TITLE{"Sort Visualizer"};

int main() {
    Window window{SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_FPS, WINDOW_TITLE};
    SortController sortController(std::make_unique<BubbleSort>(30));
    while (!Window::windowShouldClose()) {
        if (Window::isKeyDown(KEY_ESCAPE)) { break; }

        if (Window::isKeyDown(KEY_SPACE)) { sortController.sort(); }

        if (Window::isKeyDown(KEY_ONE)) {
            sortController.setSortStrategy(std::make_unique<BubbleSort>(60));
        }

        if (Window::isKeyDown(KEY_TWO)) {
            sortController.setSortStrategy(std::make_unique<InsertionSort>(60));
        }

        if (Window::isKeyDown(KEY_THREE)) {
            sortController.setSortStrategy(std::make_unique<SelectionSort>(60));
        }

        if (Window::isKeyDown(KEY_FOUR)) {
            sortController.setSortStrategy(std::make_unique<CocktailSort>(60));
        }

        if (Window::isKeyDown(KEY_FIVE)) {
            sortController.setSortStrategy(std::make_unique<ShellSort>(60));
        }

        if (Window::isKeyDown(KEY_SIX)) {
            sortController.setSortStrategy(std::make_unique<MergeSort>(60));
        }

        if (Window::isKeyDown(KEY_SEVEN)) {
            sortController.setSortStrategy(std::make_unique<CombSort>(60));
        }

        if (Window::isKeyDown(KEY_EIGHT)) {
            sortController.setSortStrategy(std::make_unique<GnomeSort>(60));
        }

        if (Window::isKeyDown(KEY_NINE)) {
            sortController.setSortStrategy(std::make_unique<TimSort>(60));
        }

        if (Window::isKeyDown(KEY_ZERO)) {
            sortController.setSortStrategy(std::make_unique<HeapSort>(60));
        }

        BeginDrawing();
        EndDrawing();
    }
    return EXIT_SUCCESS;
}