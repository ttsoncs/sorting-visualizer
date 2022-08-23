#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../sortStrategy.h"

class MergeSort : public SortStrategy {
  private:
    void mergeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                   int start, int end) {
        if (start < end) {
            auto mid{(start + end) / 2};
            mergeSort(v, start, mid);
            mergeSort(v, mid + 1, end);
            merge(v, start, mid, end);
        }
    }

    void merge(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start,
               int mid, int end) {
        std::vector<std::pair<int, std::pair<float, Color>>> temp(end - start + 1);
        auto i{start};
        auto j{mid + 1};
        auto k{0};
        while (i <= mid && j <= end) {
            Visualize::visualizeTraverse(v, i, j, "Merge Sort");
            if (v[i].first < v[j].first) {
                temp[k++] = v[i++];
            } else {
                temp[k++] = v[j++];
            }
        }
        while (i <= mid) {
            Visualize::visualizeTraverse(v, i, j, "Merge Sort");
            temp[k++] = v[i++];
        }
        while (j <= end) {
            Visualize::visualizeTraverse(v, i, j, "Merge Sort");
            temp[k++] = v[j++];
        }
        auto size{temp.size()};
        for (auto i{0}; i != size; ++i) {
            v[start + i] = temp[i];
        }
    }

  public:
    explicit MergeSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Merge Sort");
    }

    ~MergeSort() noexcept override = default;

    MergeSort(const MergeSort &other) = default;

    MergeSort &operator=(const MergeSort &other) = default;

    MergeSort(MergeSort &&other) noexcept = default;

    MergeSort &operator=(MergeSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        mergeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Merge Sort");
    }
};

#endif