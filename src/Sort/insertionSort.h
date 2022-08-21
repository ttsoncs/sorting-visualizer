#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "../sort.h"

class InsertionSort : public SortStrategy {
  public:
    explicit InsertionSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Insertion Sort");
    }

    ~InsertionSort() noexcept override = default;

    InsertionSort(const InsertionSort &other) = delete;

    InsertionSort &operator=(const InsertionSort &other) = delete;

    InsertionSort(InsertionSort &&other) noexcept = default;

    InsertionSort &operator=(InsertionSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        for (uint32_t i{1}; i < v_.size(); ++i) {
            auto [value, color] = v_[i];
            uint32_t j{i};
            while (j > 0 && v_[j - 1].first > value) {
                v_[j] = v_[j - 1];
                --j;
            }
            Visualize::visualizeBar(v_, i, "Insertion Sort");
            Visualize::visualizeBar(v_, j, "Insertion Sort");
            v_[j] = std::make_pair(value, color);
            Visualize::visualize(v_, "Insertion Sort");
            if (IsKeyPressed(KEY_Q)) { return; }
        }
        Visualize::visualizeEnding(v_, "Insertion Sort");
    }
};

#endif