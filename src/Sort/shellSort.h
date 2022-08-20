#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "../sort.h"

class ShellSort : public SortStrategy {
  public:
    explicit ShellSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Shell Sort");
    }

    ~ShellSort() noexcept override = default;

    ShellSort(const ShellSort &other) = delete;

    ShellSort &operator=(const ShellSort &other) = delete;

    ShellSort(ShellSort &&other) noexcept = default;

    ShellSort &operator=(ShellSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        uint32_t gap{static_cast<uint32_t>(v_.size())};
        while (gap > 1) {
            gap = static_cast<uint32_t>(static_cast<double>(gap) / 1.3);
            for (uint32_t i{gap}; i < v_.size(); ++i) {
                auto [value, color] = v_[i];
                uint32_t j{i};
                Visualize::visualizeBar(v_, i, "Shell Sort");
                while (j >= gap && v_[j - gap].first > value) {
                    v_[j] = v_[j - gap];
                    j -= gap;
                }
                Visualize::visualizeBar(v_, j, "Shell Sort");
                v_[j] = std::make_pair(value, color);
                Visualize::visualize(v_, "Shell Sort");
                if (IsKeyPressed(KEY_Q)) { return; }
            }
        }
        Visualize::visualizeEnding(v_, "Shell Sort");
    }
};

#endif