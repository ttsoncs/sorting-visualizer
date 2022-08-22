#ifndef STOOGE_SORT_H
#define STOOGE_SORT_H

#include "../sortStrategy.h"
class StoogeSort : public SortStrategy {
  public:
    explicit StoogeSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Stooge Sort");
    }

    ~StoogeSort() noexcept override = default;

    StoogeSort(const StoogeSort &other) = delete;

    StoogeSort &operator=(const StoogeSort &other) = delete;

    StoogeSort(StoogeSort &&other) noexcept = default;

    StoogeSort &operator=(StoogeSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        stoogeSort(v, 0, v.size() - 1);
        Visualize::visualizeVector(v, "Stooge Sort");
        Visualize::visualizeEnding(v, "Stooge Sort");
    }

  private:
    void stoogeSort(std::vector<std::pair<float, Color>> &v, int left,
                    int right) {
        if (left <= right) {
            if (v[left].first > v[right].first) {
                Visualize::visualizeBar(v, left, "Stooge Sort");
                Visualize::visualizeBar(v, right, "Stooge Sort");
                std::swap(v[left], v[right]);
                Visualize::visualizeVector(v, "Stooge Sort");
            }
            if (right - left + 1 > 2) {
                auto mid{(right - left + 1) / 3};
                stoogeSort(v, left, right - mid);
                stoogeSort(v, left + mid, right);
                stoogeSort(v, left, right - mid);
            }
        }
    }
};

#endif