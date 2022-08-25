#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class InsertionSort : public SortStrategy {
  public:
    InsertionSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Insertion Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        insertionSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Insertion Sort");
    }

  private:
    auto insertionSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i{start + 1}; i != end + 1; ++i) {
            auto [barHeight, color] = v[i];
            auto j{i};
            while (j > 0 && v[j - 1].first > barHeight) {
                Visualize::visualizeTraverse(v, j - 1, j, "Insertion Sort");
                v[j] = v[j - 1];
                --j;
            }
            Visualize::visualizeTraverse(v, j, i, "Insertion Sort");
            v[j] = std::make_pair(barHeight, color);
        }
    }
};

#endif