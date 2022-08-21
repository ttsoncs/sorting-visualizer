#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "../sortStrategy.h"
class QuickSort : public SortStrategy {
  public:
    explicit QuickSort(uint32_t size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Quick Sort");
    }

    ~QuickSort() noexcept override = default;

    QuickSort(const QuickSort &other) = delete;

    QuickSort &operator=(const QuickSort &other) = delete;

    QuickSort(QuickSort &&other) noexcept = default;

    QuickSort &operator=(QuickSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        quickSort(v_, 0, v_.size() - 1);
        Visualize::visualizeEnding(v_, "Heap Sort");
    }

    void quickSort(std::vector<std::pair<float, Color>> &v, uint32_t start,
                   uint32_t end) {
        if (start < end) {
            uint32_t pivot = partition(v, start, end);
            Visualize::visualizeBar(v, start, "Quick Sort");
            Visualize::visualizeBar(v, pivot, "Quick Sort");
            Visualize::visualizeBar(v, end, "Quick Sort");
            Visualize::visualizeVector(v, "Quick Sort");
            quickSort(v, start, pivot - 1);
            quickSort(v, pivot + 1, end);
        }
    }

    uint32_t partition(std::vector<std::pair<float, Color>> &v, uint32_t start,
                       uint32_t end) {
        uint32_t i = start;
        uint32_t j = end;
        uint32_t pivot = v[start].first;
        while (i < j) {
            while (pivot >= v[i].first) {
                ++i;
            }
            while (pivot < v[j].first) {
                --j;
            }
            if (i < j) { std::swap(v[i], v[j]); }
        }
        std::swap(v[start], v[j]);
        return j;
    }
};

#endif