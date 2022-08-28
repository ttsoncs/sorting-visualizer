#ifndef SMOOTH_SORT_H
#define SMOOTH_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class SmoothSort : public SortStrategy {
  public:
    SmoothSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Smooth Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        smoothSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Smooth Sort");
    }

  private:
    auto smoothSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto n{end - start + 1};
        auto m{1};
        while (m < n) {
            m = 2 * m + 1;
        }
        while (m > 1) {
            m = (m - 1) / 2;
            for (auto i{start + m}; i <= end; ++i) {
                auto j{i};
                auto key{v[i]};
                while (j >= start + m && key.first < v[j - m].first) {
                    Visualize::visualizeTraverse(v, j, j - m, "Smooth Sort");
                    v[j] = v[j - m];
                    j = j - m;
                }
                v[j] = key;
            }
        }
    }
};

#endif