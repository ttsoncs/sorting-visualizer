#ifndef SLOPE_SORT_H
#define SLOPE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class SlopeSort : public SortStrategy {
  public:
    SlopeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Slope Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        slopeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Slope Sort");
    }

  private:
    auto slopeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i{start + 1}, j{start + 1}; i != end + 1; ++i, ++j) {
            for (auto k{i}; k != start; --k) {
                if (v[k].first < v[k - 1].first) {
                    Visualize::visualizeTraverse(v, k, k - 1, "Slope Sort");
                    std::swap(v[k], v[k - 1]);
                } else {
                    break;
                }
            }
        }
    }
};

#endif