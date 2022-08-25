#ifndef ODD_EVEN_SORT_H
#define ODD_EVEN_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class OddEvenSort : public SortStrategy {
  public:
    OddEvenSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Odd Even Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        oddEvenSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Odd Even Sort");
    }

  private:
    auto oddEvenSort(std::vector<std::pair<int, std::pair<float,Color>>> &v, int start, int end) -> void {
        bool isSorted{false};
        while (!isSorted) {
            isSorted = true;
            for (auto i{start + 1}; i < end; i += 2) {
                Visualize::visualizeTraverse(v, i, i + 1, "Odd Even Sort");
                if (v[i].first > v[i + 1].first) {
                    std::swap(v[i], v[i + 1]);
                    isSorted = false;
                }
            }
            for (auto i{start}; i < end; i += 2) {
                Visualize::visualizeTraverse(v, i, i + 1, "Odd Even Sort");
                if (v[i].first > v[i + 1].first) {
                    std::swap(v[i], v[i + 1]);
                    isSorted = false;
                }
            }
        }
    }
};

#endif