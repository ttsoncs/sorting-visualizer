#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class ShellSort : public SortStrategy {
  public:
    ShellSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Shell Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        shellSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Shell Sort");
    }

  private:
    auto shellSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto gap{end + 1 / 2}; gap != start; gap /= 2) {
            for (auto i{gap}; i != end + 1; ++i) {
                auto j{i};
                while (j >= gap && v[j].first < v[j - gap].first) {
                    Visualize::visualizeTraverse(v, j, j - gap, "Shell Sort");
                    std::swap(v[j], v[j - gap]);
                    j -= gap;
                }
            }
        }
    }
};

#endif