#ifndef PIGEONHOLE_SORT_H
#define PIGEONHOLE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class PigeonholeSort : public SortStrategy {
  public:
    PigeonholeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Pigeonhole Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        countingSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Pigeonhole Sort");
    }

  private:
    auto countingSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto min{v[start].first};
        auto max{v[start].first};
        for (auto i{start + 1}; i != end + 1; ++i) {
            if (v[i].first < min) {
                min = v[i].first;
            }
            if (v[i].first > max) {
                max = v[i].first;
            }
        }
        auto range{max - min + 1};
        auto buckets{std::vector<std::vector<std::pair<int, std::pair<float, Color>>>>(range)};
        for (auto i{start}; i != end + 1; ++i) {
            Visualize::visualizeTraverse(v, i, v[i].first - min, "Pigeonhole Sort");
            auto index{v[i].first - min};
            buckets[index].push_back(v[i]);
        }
        auto index{0};
        for (auto i{0}; i != range; ++i) {
            if (buckets[i].size() > 0) {
                for (auto j{0}; j != buckets[i].size(); ++j) {
                    Visualize::visualizeTraverse(v, index, buckets[i][j].first, "Pigeonhole Sort");
                    v[index] = buckets[i][j];
                    ++index;
                }
            }
        }
    }
};

#endif