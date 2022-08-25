#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class SelectionSort : public SortStrategy {
  public:
    SelectionSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Selection Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        selectionSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Selection Sort");
    }

  private:
    auto selectionSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i{start}; i != end + 1; ++i) {
            auto minIndex{i};
            for (auto j{i + 1}; j != end + 1; ++j) {
                Visualize::visualizeTraverse(v, j, minIndex, "Selection Sort");
                if (v[j].first < v[minIndex].first) {
                    minIndex = j;
                }
            }
            Visualize::visualizeTraverse(v, i, minIndex, "Selection Sort");
            std::swap(v[i], v[minIndex]);
        }
    }
};

#endif