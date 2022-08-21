#ifndef STOOGE_SORT_H
#define STOOGE_SORT_H

#include "../sortStrategy.h"
class StoogeSort : public SortStrategy {
  public:
    explicit StoogeSort(uint32_t size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Stooge Sort");
    }

    ~StoogeSort() noexcept override = default;

    StoogeSort(const StoogeSort &other) = delete;

    StoogeSort &operator=(const StoogeSort &other) = delete;

    StoogeSort(StoogeSort &&other) noexcept = default;

    StoogeSort &operator=(StoogeSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        stoogeSort(v_, 0, v_.size() - 1);
        Visualize::visualizeVector(v_, "Stooge Sort");
        Visualize::visualizeEnding(v_, "Stooge Sort");
    }

  private:
    void stoogeSort(std::vector<std::pair<float, Color>> &v, uint32_t left,
                    uint32_t right) {
        if (left <= right) {
            if (v[left].first > v[right].first) {
                Visualize::visualizeBar(v, left, "Stooge Sort");
                Visualize::visualizeBar(v, right, "Stooge Sort");
                std::swap(v[left], v[right]);
                Visualize::visualizeVector(v, "Stooge Sort");
            }
            if (right - left + 1 >= 3) {
                uint32_t middle{(right - left + 1) / 3};
                stoogeSort(v, left, right - middle);
                stoogeSort(v, left + middle, right);
                stoogeSort(v, left, right - middle);
            }
        }
    }
};

#endif