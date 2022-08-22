#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "../sortStrategy.h"
class QuickSort : public SortStrategy {
  private:
    void quickSort(std::vector<std::pair<float, Color>> &v, int start,
                   int end) {
        if (start <= end) {
            auto i{start};
            auto j{end};
            auto pivot{v[(start + end) / 2]};
            while (i <= j) {
                while (v[i].first < pivot.first) {
                    ++i;
                }
                while (v[j].first > pivot.first) {
                    --j;
                }
                if (i <= j) {
                    Visualize::visualizeBar(v, i, "Quicksort");
                    Visualize::visualizeBar(v, j, "Quicksort");
                    std::swap(v[i], v[j]);
                    ++i;
                    --j;
                    Visualize::visualizeVector(v, "Quicksort");
                }
            }
            if (start < j) { quickSort(v, start, j); }
            if (i < end) { quickSort(v, i, end); }
        }
    }

  public:
    explicit QuickSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Quicksort");
    }

    ~QuickSort() noexcept override = default;

    QuickSort(const QuickSort &other) = delete;

    QuickSort &operator=(const QuickSort &other) = delete;

    QuickSort(QuickSort &&other) noexcept = default;

    QuickSort &operator=(QuickSort &&other) noexcept = default;

    void sort() override {
        auto v = vector_.getVector();
        quickSort(v, 0, v.size() - 1);
        Visualize::visualizeVector(v, "Quicksort");
        Visualize::visualizeEnding(v, "Quicksort");
    }

    // void quickSort(std::vector<std::pair<float, Color>> &v, int start,
    //                int end) {
    //     if (start < end) {
    //         auto pivot = partition(v, start, end);
    //         quickSort(v, start, pivot - 1);
    //         quickSort(v, pivot + 1, end);
    //     }
    // }

    // int partition(std::vector<std::pair<float, Color>> &v, int
    // start,
    //                    int end) {
    //     auto pivot = v[end];
    //     auto i = start - 1;
    //     for (auto j = start; j < end; j++) {
    //         if (v[j].first <= pivot.first) {
    //             i++;
    //             std::swap(v[i], v[j]);
    //             Visualize::visualizeBar(v, i, "Quicksort");
    //             Visualize::visualizeBar(v, j, "Quicksort");
    //             Visualize::visualizeVector(v, "Quicksort");
    //         }
    //     }
    //     std::swap(v[i + 1], v[end]);
    //     Visualize::visualizeBar(v, i + 1, "Quicksort");
    //     Visualize::visualizeBar(v, end, "Quicksort");
    //     Visualize::visualizeVector(v, "Quicksort");
    //     return i + 1;
};

#endif