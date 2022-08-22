#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../sortStrategy.h"
class SelectionSort : public SortStrategy {
  public:
    explicit SelectionSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Selection Sort");
    }

    ~SelectionSort() noexcept override = default;

    SelectionSort(const SelectionSort &other) = delete;

    SelectionSort &operator=(const SelectionSort &other) = delete;

    SelectionSort(SelectionSort &&other) noexcept = default;

    SelectionSort &operator=(SelectionSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        for (auto i{0}; i < size; ++i) {
            auto minIndex{i};
            for (auto j{i + 1}; j < size; ++j) {
                BeginDrawing();
                Visualize::visualizeVector(v, "Selection Sort");
                Visualize::visualizeBar(v, j, "Selection Sort");
                Visualize::visualizeBar(v, minIndex, "Selection Sort");
                EndDrawing();
                if (v[j].first < v[minIndex].first) { minIndex = j; }
            }
            BeginDrawing();
            Visualize::visualizeVector(v, "Selection Sort");
            Visualize::visualizeBar(v, i, "Selection Sort");
            Visualize::visualizeBar(v, minIndex, "Selection Sort");
            EndDrawing();
            std::swap(v[i], v[minIndex]);
        }
        Visualize::visualizeEnding(v, "Selection Sort");
    }
};

#endif