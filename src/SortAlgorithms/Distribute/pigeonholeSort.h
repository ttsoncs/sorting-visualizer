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
        pigeonholeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Pigeonhole Sort");
    }

  private:
    auto pigeonholeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto minmax{std::minmax_element(v.begin() + start, v.begin() + end + 1, [](const auto &a, const auto &b) { return a.first < b.first; })};
        auto range{minmax.second->first - minmax.first->first + 1};
        auto buckets{std::vector<std::vector<std::pair<int, std::pair<float, Color>>>>(range)};
        for (auto const &i : v) {
            auto j{i.first - minmax.first->first};
            Visualize::visualizeTraverse(v, i.first, j, "Pigeonhole Sort");
            buckets[j].push_back(i);
        }
        auto k{0};
        for (auto const &bucket : buckets) {
            for (auto const &i : bucket) {
                Visualize::visualizeTraverse(v, k, i.first, "Pigeonhole Sort");
                v[k++] = i;
            }
        }
    }
};

#endif