#ifndef INTERPOLATION_SORT_H
#define INTERPOLATION_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class InterpolationSort : public SortStrategy {
  public:
    InterpolationSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Interpolation Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        interpolationSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Interpolation Sort");
    }

  private:
    auto interpolationSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto size{end - start + 1};
        if (size <= 1) {
            return;
        }
        std::vector<int> process;
        std::vector<std::vector<int>> bucket;
        for (auto i{0}; i < size; i++) {
            bucket.push_back(std::vector<int>());
        }
        process.push_back(size);
        while (!process.empty()) {
            auto p{process.back()};
            process.pop_back();
            auto left{end - p + 1};
            auto right{end + 1};
            auto max{v[left].first};
            auto min{v[left].first};
            for (auto i{left + 1}; i <= end; i++) {
                if (v[i].first > max) {
                    max = v[i].first;
                }
                if (v[i].first < min) {
                    min = v[i].first;
                }
            }
            if (max == min) {
                right = right - p;
            } else {
                for (auto i{left}; i < right; i++) {
                    auto index{(v[i].first - min) / (max - min) * (p - 1)};
                    bucket[index].push_back(i);
                }
                for (auto i{start}; i < p; i++) {
                    if (!bucket[i].empty()) {
                        for (auto j{0}; j < bucket[i].size(); j++) {
                            v[left].first = v[bucket[i][j]].first;
                            left++;
                        }
                    }
                }
                for (auto i{0}; i < p; i++) {
                    bucket[i].clear();
                }
            }
        }
        Visualize::visualizeVector(v);
    }
};

#endif