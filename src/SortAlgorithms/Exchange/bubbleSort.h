#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class BubbleSort : public SortStrategy {
  public:
    BubbleSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Bubble Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        bubbleSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Bubble Sort");
    }

  private:
    auto bubbleSort(std::vector<std::pair<int, std::pair<float,Color>>> &v, int start, int end) -> void {
        for (auto i{start}; i < end; ++i) {
            for (auto j{start}; j < end - i; ++j) {
                Visualize::visualizeTraverse(v, j, j + 1, "Bubble Sort");
                if (v[j].first > v[j + 1].first) {
                    std::swap(v[j], v[j + 1]);
                }
            }
        }
    }
};

#endif