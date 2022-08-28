#ifndef PANCAKE_SORT_H
#define PANCAKE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class PancakeSort : public SortStrategy {
  public:
    PancakeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Pancake Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        pancakeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Pancake Sort");
    }

  private:
    auto pancakeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i{end + 1}; i != start + 1; --i) {
            auto location{maxIndex(v, i)};
            if (location != i - 1) {
                reverseElement(v, location);
                reverseElement(v, i - 1);
            }
        }
    }

    auto maxIndex(std::vector<std::pair<int, std::pair<float, Color>>> const &v, int size) -> int {
        auto maxIndex{0};
        for (auto i{0}; i != size; ++i) {
            if (v[i].first > v[maxIndex].first) {
                Visualize::visualizeTraverse(v, maxIndex, i, "Pancake Sort");
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    auto reverseElement(std::vector<std::pair<int, std::pair<float, Color>>> &v, int index) -> void {
        auto j{0};
        while (j < index) {
            Visualize::visualizeTraverse(v, j, index, "Pancake Sort");
            std::swap(v[j], v[index]);
            ++j;
            --index;
        }
    }
};

#endif