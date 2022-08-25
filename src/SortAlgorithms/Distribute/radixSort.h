#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class RadixSort : public SortStrategy {
  public:
    RadixSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Radix Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        radixSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Radix Sort");
    }

  private:
    auto radixSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        if (start < end) {
            auto max{v[start].first};
            auto j{start};
            for (auto i{start + 1}; i != end; ++i) {
                if (v[i].first > max) {
                    Visualize::visualizeTraverse(v, i, j, "Radix Sort");
                    max = v[i].first;
                    j   = i;
                }
            }
            auto exp{1};
            while (max / exp > 0) {
                countingSort(v, start, end, exp);
                exp *= 10;
            }
        }
    }

    auto countingSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end, int exp) -> void {
        std::vector<std::pair<int, std::pair<float, Color>>> temp(end - start + 1);
        std::vector<int> count(10);
        for (auto i{start}; i != end + 1; ++i) {
            ++count[(v[i].first / exp) % 10];
        }
        for (auto i{1}; i != 10; ++i) {
            Visualize::visualizeTraverse(v, i, i - 1, "Radix Sort");
            count[i] += count[i - 1];
        }
        for (auto i{end}; i != start - 1; --i) {
            auto j{(v[i].first / exp) % 10};
            Visualize::visualizeTraverse(v, i, count[j] - 1, "Radix Sort");
            temp[count[j] - 1] = v[i];
            --count[j];
        }
        for (auto i{start}; i != end + 1; ++i) {
            Visualize::visualizeTraverse(v, i, i - start, "Radix Sort");
            v[i] = temp[i - start];
        }
    }
};
#endif