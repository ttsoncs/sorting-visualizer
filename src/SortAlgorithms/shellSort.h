#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "../sortStrategy.h"

class ShellSort : public SortStrategy {
  public:
    explicit ShellSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Shell Sort");
    }

    ~ShellSort() noexcept override = default;

    ShellSort(const ShellSort &other) = delete;

    ShellSort &operator=(const ShellSort &other) = delete;

    ShellSort(ShellSort &&other) noexcept = default;

    ShellSort &operator=(ShellSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        for (auto gap{size / 2}; gap > 0; gap /= 2) {
            for (auto i{gap}; i < size; ++i) {
                auto j{i};
                while (j >= gap && v[j].first < v[j - gap].first) {
                    Visualize::visualizeTraverse(v, j, j - gap, "Shell Sort");
                    std::swap(v[j], v[j - gap]);
                    j -= gap;
                }
            }
        }
        Visualize::visualizeEnding(v, "Shell Sort");
    }
};

#endif