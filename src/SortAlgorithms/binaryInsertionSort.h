#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include "../sortStrategy.h"

class BinaryInsertionSort : public SortStrategy {
  private:
    void binaryInsertionSort(std::vector<std::pair<float, Color>> &v, int start,
                             int end) {
        for (auto i{start + 1}; i <= end; ++i) {
            Visualize::visualizeTraverse(v, i, i - 1, "Binary Insertion Sort");
            auto key{v[i]};
            auto low{start};
            auto high{i - 1};
            while (low <= high) {
                auto mid{(low + high) / 2};
                Visualize::visualizeTraverse(v, mid, mid + 1,
                                             "Binary Insertion Sort");
                if (v[mid].first < key.first) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            for (auto j{i - 1}; j >= low; --j) {
                Visualize::visualizeTraverse(v, j, j + 1,
                                             "Binary Insertion Sort");
                v[j + 1] = v[j];
            }
            v[low] = key;
        }
    }

  public:
    explicit BinaryInsertionSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Binary Insertion Sort");
    }

    ~BinaryInsertionSort() noexcept override = default;

    BinaryInsertionSort(const BinaryInsertionSort &other) = delete;

    BinaryInsertionSort &operator=(const BinaryInsertionSort &other) = delete;

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