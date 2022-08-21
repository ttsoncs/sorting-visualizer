#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "../sortStrategy.h"
class InsertionSort : public SortStrategy {
  public:
    explicit InsertionSort(uint32_t size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Insertion Sort");
    }

    ~InsertionSort() noexcept override = default;

    InsertionSort(const InsertionSort &other) = delete;

    InsertionSort &operator=(const InsertionSort &other) = delete;

    InsertionSort(InsertionSort &&other) noexcept = default;

    InsertionSort &operator=(InsertionSort &&other) noexcept = default;

    void sort() override {
        auto v = vector_.getVector();
        auto size{v.size()};
        for (auto i{1}; i < size; ++i) {
            auto [barHeight, color] = v[i];
            auto j{i};
            while (j > 0 && v[j - 1].first > barHeight) {
                v[j] = v[j - 1];
                --j;
            }
            Visualize::visualizeBar(v, i, "Insertion Sort");
            Visualize::visualizeBar(v, j, "Insertion Sort");
            v[j] = std::make_pair(barHeight, color);
            Visualize::visualizeVector(v, "Insertion Sort");
        }
        Visualize::visualizeEnding(v, "Insertion Sort");
    }
};

#endif