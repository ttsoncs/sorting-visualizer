#ifndef BITONIC_SORT_H
#define BITONIC_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class BitonicSort : public SortStrategy {
  public:
    BitonicSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Bitonic Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        bitonicSort(v, 0, v.size(), true);
        Visualize::visualizeEnding(v, "Bitonic Sort");
    }

  private:
    auto bitonicSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int size, bool ascending) -> void {
        if (size > 1) {
            auto k{size / 2};
            bitonicSort(v, start, k, !ascending);
            bitonicSort(v, start + k, size - k, ascending);
            bitonicMerge(v, start, size, ascending);
        }
    };

    auto bitonicMerge(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int size, bool ascending) -> void {
        if (size > 1) {
            auto k{greatestPowerOfTwoLessThan(size)};
            for (auto i{start}; i != start + size - k; ++i) {
                if (ascending == (v[i].first > v[i + k].first)) {
                    Visualize::visualizeTraverse(v, i, i + k, "Bitonic Sort");
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
};

#endif