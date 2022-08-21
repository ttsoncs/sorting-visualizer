#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../sort.h"

class BubbleSort : public SortStrategy {
  public:
    explicit BubbleSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Bubble Sort");
    }

    ~BubbleSort() noexcept override = default;

    BubbleSort(const BubbleSort &other) = delete;

    BubbleSort &operator=(const BubbleSort &other) = delete;

    BubbleSort(BubbleSort &&other) noexcept = default;

    BubbleSort &operator=(BubbleSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        for (uint32_t i{0}; i < v_.size(); ++i) {
            for (uint32_t j{0}; j < v_.size() - i - 1; ++j) {
                if (v_[j].first > v_[j + 1].first) {
                    Visualize::visualizeBar(v_, j, "Bubble Sort");
                    Visualize::visualizeBar(v_, j + 1, "Bubble Sort");
                    std::swap(v_[j], v_[j + 1]);
                    Visualize::visualize(v_, "Bubble Sort");
                }
                if (IsKeyPressed(KEY_Q)) { return; }
            }
        }
        Visualize::visualizeEnding(v_, "Bubble Sort");
    }
};

#endif