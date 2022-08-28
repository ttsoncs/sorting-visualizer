#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class BinaryInsertionSort : public SortStrategy {
  public:
    BinaryInsertionSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Binary Insertion Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        binaryInsertionSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Binary Insertion Sort");
    }

  private:
    auto binaryInsertionSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i{start + 1}; i != end + 1; ++i) {
            auto key{v[i]};
            auto left{start};
            auto right{i - 1};
            while (left <= right) {
                auto mid{(left + right) / 2};
                if (v[mid].first < key.first) {
                    Visualize::visualizeTraverse(v, left, mid + 1, "Binary Insertion Sort");
                    left = mid + 1;
                } else {
                    Visualize::visualizeTraverse(v, right, mid - 1, "Binary Insertion Sort");
                    right = mid - 1;
                }
            }
            for (auto j{i - 1}; j != left - 1; --j) {
                Visualize::visualizeTraverse(v, j + 1, j, "Binary Insertion Sort");
                v[j + 1] = v[j];
            }
            Visualize::visualizeTraverse(v, left, i, "Binary Insertion Sort");
            v[left] = key;
        }
    }
};

#endif