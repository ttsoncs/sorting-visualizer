#ifndef EVEN_ODD_SORT_H
#define EVEN_ODD_SORT_H

#include "../sortStrategy.h"

class EvenOddSort : public SortStrategy {
  public:
    explicit EvenOddSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Even Odd Sort");
    }

    ~EvenOddSort() noexcept override = default;

    EvenOddSort(const EvenOddSort &other) = delete;

    EvenOddSort &operator=(const EvenOddSort &other) = delete;

    EvenOddSort(EvenOddSort &&other) noexcept = default;

    EvenOddSort &operator=(EvenOddSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        bool isSorted{false};
        while (!isSorted) {
            isSorted = true;
            for (auto i{1}; i < size - 1; i = i + 2) {
                Visualize::visualizeTraverse(v, i, i + 1, "Even Odd Sort");
                if (v[i].first > v[i + 1].first) {
                    std::swap(v[i], v[i + 1]);
                    isSorted = false;
                }
            }
            for (auto i{0}; i < size - 1; i = i + 2) {
                Visualize::visualizeTraverse(v, i, i + 1, "Even Odd Sort");
                if (v[i].first > v[i + 1].first) {
                    std::swap(v[i], v[i + 1]);
                    isSorted = false;
                }
            }
        }
        Visualize::visualizeEnding(v, "Even Odd Sort");
    }
};

#endif