#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../sortStrategy.h"

class BubbleSort : public SortStrategy {
  public:
    explicit BubbleSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Bubble Sort");
    }

    ~BubbleSort() noexcept override = default;

    BubbleSort(const BubbleSort &other) = delete;

    BubbleSort &operator=(const BubbleSort &other) = delete;

    BubbleSort(BubbleSort &&other) noexcept = default;

    BubbleSort &operator=(BubbleSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        for (auto i{0}; i < size; ++i) {
            for (auto j{0}; j < size - i - 1; ++j) {
                if (v[j].first > v[j + 1].first) {
                    Visualize::visualizeBar(v, j, "Bubble Sort");
                    Visualize::visualizeBar(v, j + 1, "Bubble Sort");
                    std::swap(v[j], v[j + 1]);
                    Visualize::visualizeVector(v, "Bubble Sort");
                }
            }
        }
        Visualize::visualizeEnding(v, "Bubble Sort");
    }
};

#endif