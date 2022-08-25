#ifndef COMB_SORT_H
#define COMB_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class CombSort : public SortStrategy {
  public:
    CombSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Comb Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        combSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Comb Sort");
    }

  private:
    auto combSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto gap{end - start};
        auto size{end - start + 1};
        bool swapped{true};
        while (gap > 1 || swapped) {
            if (gap > 1) {
                gap = gap * 10 / 13;
            }
            swapped = false;
            for (auto i{start}; i != size - gap; ++i) {
                Visualize::visualizeTraverse(v, i, i + gap, "Comb Sort");
                if (v[i].first > v[i + gap].first) {
                    std::swap(v[i], v[i + gap]);
                    swapped = true;
                }
            }
        }
    }
};

#endif