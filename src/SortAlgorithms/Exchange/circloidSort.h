#ifndef CIRCLOID_SORT_H
#define CIRCLOID_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class CircloidSort : public SortStrategy {
  public:
    CircloidSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Circloid Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        while (circloidSort(v, 0, v.size() - 1))
            ;
        Visualize::visualizeEnding(v, "Circloid Sort");
    }

  private:
    auto circloidSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> bool {
        if (start >= end) {
            return false;
        }
        auto mid{(start + end) / 2};
        return circloidSort(v, start, mid) || circloidSort(v, mid + 1, end) || circloidMerge(v, start, end);
    }

    auto circloidMerge(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> bool {
        auto left{start};
        auto right{end};
        auto swapped{false};
        while (left < right) {
            if (v[left].first > v[right].first) {
                Visualize::visualizeTraverse(v, left, right, "Circloid Sort");
                std::swap(v[left], v[right]);
                swapped = true;
            }
            ++left;
            --right;
            if (left == right) {
                ++right;
            }
        }
        return swapped;
    }
};

#endif