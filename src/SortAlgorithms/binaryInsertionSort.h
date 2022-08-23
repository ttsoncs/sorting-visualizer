#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include "../sortStrategy.h"

class BinaryInsertionSort : public SortStrategy {
  private:
    void
    binaryInsertionSort(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                        int start, int end) {
        for (auto i{start + 1}; i != end + 1; ++i) {
            auto key{v[i]};
            auto low{start};
            auto high{i - 1};
            while (low <= high) {
                auto mid{(low + high) / 2};
                if (v[mid].first < key.first) {
                    Visualize::visualizeTraverse(v, low, mid + 1,
                                                 "Binary Insertion Sort");
                    low = mid + 1;
                } else {
                    Visualize::visualizeTraverse(v, high, mid - 1,
                                                 "Binary Insertion Sort");
                    high = mid - 1;
                }
            }
            for (auto j{i - 1}; j != low - 1; --j) {
                Visualize::visualizeTraverse(v, j + 1, j, "Binary Insertion Sort");
                v[j + 1] = v[j];
            }
            Visualize::visualizeTraverse(v, low, i, "Binary Insertion Sort");
            v[low] = key;
        }
    }

  public:
    explicit BinaryInsertionSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Binary Insertion Sort");
    }

    ~BinaryInsertionSort() noexcept override = default;

    BinaryInsertionSort(const BinaryInsertionSort &other) = default;

    BinaryInsertionSort &operator=(const BinaryInsertionSort &other) = default;

    BinaryInsertionSort(BinaryInsertionSort &&other) noexcept = default;

    BinaryInsertionSort &
    operator=(BinaryInsertionSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        binaryInsertionSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Binary Insertion Sort");
    }
};

#endif