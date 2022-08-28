#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class QuickSort : public SortStrategy {
  public:
    QuickSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Quicksort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        quickSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Quicksort");
    }

  private:
    auto quickSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
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
                    Visualize::visualizeTraverse(v, i, j, "Quicksort");
                    std::swap(v[i], v[j]);
                    ++i;
                    --j;
                }
            }
            if (start < j) {
                quickSort(v, start, j);
            }
            if (i < end) {
                quickSort(v, i, end);
            }
        }
    }
};

#endif