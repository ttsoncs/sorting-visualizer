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
        auto i{0};
        while (i != v.size() - 1) {
            Visualize::visualizeTraverse(v, i, i + 1, "Double Insertion Sort");
            if (v[i].first > v[i + 1].first) {
                auto temp{v[i + 1]};
                auto j{i};
                while (j >= 0 && v[j].first > temp.first) {
                    Visualize::visualizeTraverse(v, j, j + 1, "Double Insertion Sort");
                    v[j + 1] = v[j];
                    --j;
                }
                v[j + 1] = temp;
            }
            ++i;
        }
    }
};

#endif