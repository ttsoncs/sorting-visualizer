#ifndef COMB_SORT_H
#define COMB_SORT_H

#include "../sortStrategy.h"

class CombSort : public SortStrategy {
  public:
    explicit CombSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Comb Sort");
    }

    ~CombSort() noexcept override = default;

    CombSort(const CombSort &other) = delete;

    CombSort &operator=(const CombSort &other) = delete;

    CombSort(CombSort &&other) noexcept = default;

    CombSort &operator=(CombSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto gap{v.size()};
        auto size{v.size()};
        bool swapped{true};
        while (gap > 1 || swapped) {
            if (gap > 1) { gap = gap * 10 / 13; }
            swapped = false;
            for (auto i{0}; i < size - gap; ++i) {
                Visualize::visualizeTraverse(v, i, i + gap, "Comb Sort");
                if (v[i].first > v[i + gap].first) {
                    std::swap(v[i], v[i + gap]);
                    swapped = true;
                }
            }
        }
        Visualize::visualizeEnding(v, "Comb Sort");
    }
};

#endif