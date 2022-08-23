#ifndef BITONIC_SORT_H
#define BITONIC_SORT_H

#include "../sortStrategy.h"

class BitonicSort : public SortStrategy {
  private:
    void bitonicSort(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                     int start, int size, bool ascending) {
        if (size > 1) {
            auto k{size / 2};
            bitonicSort(v, start, k, !ascending);
            bitonicSort(v, start + k, size - k, ascending);
            bitonicMerge(v, start, size, ascending);
        }
    };

    void bitonicMerge(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                      int start, int size, bool ascending) {
        if (size > 1) {
            auto k{greatestPowerOfTwoLessThan(size)};
            for (auto i{start}; i != start + size - k; ++i) {
                Visualize::visualizeTraverse(v, i, i + k, "Bitonic Sort");
                if (ascending == (v[i].first > v[i + k].first)) {
                    std::swap(v[i], v[i + k]);
                }
            }
            bitonicMerge(v, start, k, ascending);
            bitonicMerge(v, start + k, size - k, ascending);
        }
    };

    int greatestPowerOfTwoLessThan(int n) {
        auto k{1};
        while (k < n) {
            k *= 2;
        }
        return k / 2;
    }

  public:
    explicit BitonicSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Bitonic Sort");
    }

    ~BitonicSort() noexcept override = default;

    BitonicSort(const BitonicSort &other) = default;

    BitonicSort &operator=(const BitonicSort &other) = default;

    BitonicSort(BitonicSort &&other) noexcept = default;

    BitonicSort &operator=(BitonicSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        bitonicSort(v, 0, v.size(), true);
        Visualize::visualizeEnding(v, "Bitonic Sort");
    }
};

#endif