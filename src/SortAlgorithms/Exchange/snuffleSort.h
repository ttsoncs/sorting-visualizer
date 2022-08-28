#ifndef SNUFFLE_SORT_H
#define SNUFFLE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"
#include <cmath>

class SnuffleSort : public SortStrategy {
  public:
    SnuffleSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Snuffle Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        snuffleSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Snuffle Sort");
    }

  private:
    auto snuffleSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto size{end - start + 1};
        if (size >= 2) {
            if (v[start].first > v[end].first) {
                Visualize::visualizeTraverse(v, start, end, "Snuffle Sort");
                std::swap(v[start], v[end]);
            }
            if (size >= 3) {
                auto mid{(start + end) / 2};
                for (auto i{0}; i != std::ceil(size / 2); ++i) {
                    snuffleSort(v, start, mid);
                    snuffleSort(v, mid, end);
                }
            }
        }
    }
};

#endif