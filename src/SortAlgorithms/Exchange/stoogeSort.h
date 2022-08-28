#ifndef STOOGE_SORT_H
#define STOOGE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class StoogeSort : public SortStrategy {
  public:
    StoogeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Stooge Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        stoogeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Stooge Sort");
    }

  private:
    auto stoogeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto size{end - start + 1};
        if (start <= end) {
            if (v[start].first > v[end].first) {
                Visualize::visualizeTraverse(v, start, end, "Stooge Sort");
                std::swap(v[start], v[end]);
            }
            if (size > 2) {
                auto mid{size / 3};
                stoogeSort(v, start, end - mid);
                stoogeSort(v, start + mid, end);
                stoogeSort(v, start, end - mid);
            }
        }
    }
};

#endif