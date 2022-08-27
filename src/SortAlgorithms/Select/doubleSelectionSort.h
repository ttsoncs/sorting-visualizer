#ifndef DOUBLE_SELECTION_SORT_H
#define DOUBLE_SELECTION_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class DoubleSelectionSort : public SortStrategy {
  public:
    DoubleSelectionSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Double Selection Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        doubleSelectionSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Double Selection Sort");
    }

  private:
    auto doubleSelectionSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto left{start};
        auto right{end};
        auto min{0};
        auto max{0};
        while (left < right) {
            min = left;
            max = right;
            for (auto i{left}; i <= right; ++i) {
                if (v[i].first < v[min].first) {
                    Visualize::visualizeTraverse(v, i, min, "Double Selection Sort");
                    min = i;
                }
                if (v[i].first > v[max].first) {
                    Visualize::visualizeTraverse(v, i, max, "Double Selection Sort");
                    max = i;
                }
            }
            Visualize::visualizeTraverse(v, min, left, "Double Selection Sort");
            std::swap(v[left], v[min]);
            if (max == left) {
                max = min;
            }
            Visualize::visualizeTraverse(v, max, right, "Double Selection Sort");
            std::swap(v[right], v[max]);
            ++left;
            --right;
        }
    }
};

#endif