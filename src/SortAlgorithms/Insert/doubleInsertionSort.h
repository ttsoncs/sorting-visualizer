#ifndef DOUBLE_INSERTION_SORT_H
#define DOUBLE_INSERTION_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class DoubleInsertionSort : public SortStrategy {
  public:
    DoubleInsertionSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Double Insertion Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        doubleInsertionSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Double Insertion Sort");
    }

  private:
    auto doubleInsertionSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto left{start + (end - start + 1) / 2 - 1};
        auto right{left + 1};
        if (v[left].first > v[right].first) {
            std::swap(v[left], v[right]);
        }
        --left;
        ++right;
        while (left >= start && right <= end) {
            if (v[left].first > v[right].first) {
                auto leftItem{v[right]};
                auto rightItem{v[left]};
                auto pos{left + 1};
                while (pos <= right && v[pos].first <= leftItem.first) {
                    Visualize::visualizeTraverse(v, pos, pos - 1, "Double Insertion Sort");
                    v[pos - 1] = v[pos];
                    ++pos;
                }
                v[pos - 1] = leftItem;
                pos        = right - 1;
                while (pos >= left && v[pos].first >= rightItem.first) {
                    Visualize::visualizeTraverse(v, pos, pos + 1, "Double Insertion Sort");
                    v[pos + 1] = v[pos];
                    --pos;
                }
                v[pos + 1] = rightItem;
            } else {
                auto leftItem{v[left]};
                auto rightItem{v[right]};
                auto pos{left + 1};
                while (v[pos].first < leftItem.first) {
                    Visualize::visualizeTraverse(v, pos, pos - 1, "Double Insertion Sort");
                    v[pos - 1] = v[pos];
                    ++pos;
                }
                v[pos - 1] = leftItem;
                pos        = right - 1;
                while (v[pos].first > rightItem.first) {
                    Visualize::visualizeTraverse(v, pos, pos + 1, "Double Insertion Sort");
                    v[pos + 1] = v[pos];
                    --pos;
                }
                v[pos + 1] = rightItem;
            }
            --left;
            ++right;
        }
        if (right <= end) {
            auto pos{right - 1};
            auto current{v[right]};
            while (v[pos].first > current.first) {
                Visualize::visualizeTraverse(v, pos, pos + 1, "Double Insertion Sort");
                v[pos + 1] = v[pos];
                --pos;
            }
            v[pos + 1] = current;
        }
    }
};

#endif