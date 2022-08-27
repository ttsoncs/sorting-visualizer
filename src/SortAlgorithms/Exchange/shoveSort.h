#ifndef SHOVE_SORT_H
#define SHOVE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class ShoveSort : public SortStrategy {
  public:
    ShoveSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Shove Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        shoveSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Shove Sort");
    }

  private:
    auto shoveSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto i{start};
        while (i < end) {
            if (v[i].first > v[i + 1].first) {
                Visualize::visualizeTraverse(v, i, i + 1, "Shove Sort");
                for (auto j{i}; j < end; ++j) {
                    Visualize::visualizeTraverse(v, j, j + 1, "Shove Sort");
                    std::swap(v[j], v[j + 1]);
                }
                if (i > start) {
                    --i;
                }
                continue;
            }
            ++i;
        }
    }
};

#endif