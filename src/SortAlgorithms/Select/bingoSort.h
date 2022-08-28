#ifndef BINGO_SORT_H
#define BINGO_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class BingoSort : public SortStrategy {
  public:
    BingoSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Bingo Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        bingoSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Bingo Sort");
    }

  private:
    auto bingoSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto maximum{end};
        auto next{v[end].first};
        auto k{end};
        for (auto i{maximum}; i != start - 1; --i) {
            if (v[i].first > next) {
                Visualize::visualizeTraverse(v, i, k, "Bingo Sort");
                next = v[i].first;
                k    = i;
            }
        }
        while (maximum > 0 && v[maximum].first == next) {
            --maximum;
        }
        while (maximum > 0) {
            auto val{next};
            next = v[maximum].first;
            for (auto i{maximum}; i != start - 1; --i) {
                if (v[i].first == val) {
                    Visualize::visualizeTraverse(v, i, maximum, "Bingo Sort");
                    std::swap(v[i], v[maximum]);
                    --maximum;
                } else if (v[i].first > next) {
                    next = v[i].first;
                }
            }
            while (maximum > 0 && v[maximum].first == next) {
                --maximum;
            }
        }
    }
};

#endif