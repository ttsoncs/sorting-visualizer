#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../sort.h"

class SelectionSort : public SortStrategy {
  public:
    explicit SelectionSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Selection Sort");
    }

    ~SelectionSort() noexcept override = default;

    SelectionSort(const SelectionSort &other) = delete;

    SelectionSort &operator=(const SelectionSort &other) = delete;

    SelectionSort(SelectionSort &&other) noexcept = default;

    SelectionSort &operator=(SelectionSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        for (uint32_t i{0}; i < v_.size(); ++i) {
            uint32_t minIndex{i};
            Visualize::visualizeBar(v_, i, "Selection Sort");
            for (uint32_t j{i + 1}; j < v_.size(); ++j) {
                if (v_[j].first < v_[minIndex].first) { minIndex = j; }
            }
            Visualize::visualizeBar(v_, minIndex, "Selection Sort");
            std::swap(v_[i], v_[minIndex]);
            if (IsKeyPressed(KEY_Q)) { return; }
            Visualize::visualize(v_, "Selection Sort");
        }
        Visualize::visualizeEnding(v_, "Selection Sort");
    }
};

#endif