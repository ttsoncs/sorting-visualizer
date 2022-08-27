#ifndef GRAVITY_SORT_H
#define GRAVITY_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"
#include <iostream>

class GravitySort : public SortStrategy {
  public:
    GravitySort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Gravity Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        gravitySort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Gravity Sort");
    }

  private:
    auto gravitySort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i : v) {
            std::cout << i.first << " ";
        }
        auto min{v[start].first};
        auto max{v[start].first};
        for (auto i{start + 1}; i < end; ++i) {
            if (v[i].first < min) {
                min = v[i].first;
            }
            if (v[i].first > max) {
                max = v[i].first;
            }
        }
        auto range{max - min + 1};
        std::vector<int> x(v.size());
        std::vector<int> y(range);
        for (auto i{start}; i < end; ++i) {
            x[i] = v[i].first - min;
            ++y[v[i].first - min];
        }
        for (auto i{y.size() - 1}; i > 0; --i) {
            y[i - 1] += y[i];
        }
        for (auto i{y.size() - 1}; i >= 0; --i) {
            for (auto j{start}; j < end; ++j) {
                int increment{(j >= end - y[i] ? 1 : 0) - (x[j] >= i ? 1 : 0)};
                v[j].first += increment;
            }
        }
        for (auto i : v) {
            std::cout << i.first << " ";
        }
    }
};
#endif