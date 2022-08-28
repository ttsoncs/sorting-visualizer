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
            Visualize::visualizeTraverse(v, left, right, "Double Insertion Sort");
            std::swap(v[left], v[right]);
        }
        --left;
        ++right;
        while (left >= start && right <= end) {
            if (v[left].first > v[right].first) {
                auto leftKey{v[right]};
                auto rightKey{v[left]};
                auto pos{left + 1};
                while (pos != right + 1 && v[pos].first <= leftKey.first) {
                    Visualize::visualizeTraverse(v, pos, pos - 1, "Double Insertion Sort");
                    v[pos - 1] = v[pos];
                    ++pos;
                }
                Visualize::visualizeTraverse(v, right, pos - 1, "Double Insertion Sort");
                v[pos - 1] = leftKey;
                pos        = right - 1;
                while (pos != left - 1 && v[pos].first >= rightKey.first) {
                    Visualize::visualizeTraverse(v, pos, pos + 1, "Double Insertion Sort");
                    v[pos + 1] = v[pos];
                    --pos;
                }
                Visualize::visualizeTraverse(v, left, pos + 1, "Double Insertion Sort");
                v[pos + 1] = rightKey;
            } else {
                auto leftKey{v[left]};
                auto rightKey{v[right]};
                auto pos{left + 1};
                while (v[pos].first < leftKey.first) {
                    Visualize::visualizeTraverse(v, pos, pos - 1, "Double Insertion Sort");
                    v[pos - 1] = v[pos];
                    ++pos;
                }
                Visualize::visualizeTraverse(v, left, pos - 1, "Double Insertion Sort");
                v[pos - 1] = leftKey;
                pos        = right - 1;
                while (v[pos].first > rightKey.first) {
                    Visualize::visualizeTraverse(v, pos, pos + 1, "Double Insertion Sort");
                    v[pos + 1] = v[pos];
                    --pos;
                }
                Visualize::visualizeTraverse(v, right, pos + 1, "Double Insertion Sort");
                v[pos + 1] = rightKey;
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
            Visualize::visualizeTraverse(v, right - 1, pos + 1, "Double Insertion Sort");
            v[pos + 1] = current;
        }
    }
};

#endif