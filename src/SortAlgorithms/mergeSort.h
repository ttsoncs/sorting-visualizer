#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../sortStrategy.h"
class MergeSort : public SortStrategy {
  private:
    void mergeSort(std::vector<std::pair<float, Color>> &v, uint32_t start,
                   uint32_t end) {
        if (start < end) {
            auto mid{(start + end) / 2};
            Visualize::visualizeBar(v, start, "Merge Sort");
            Visualize::visualizeBar(v, mid, "Merge Sort");
            Visualize::visualizeBar(v, end, "Merge Sort");
            Visualize::visualizeVector(v, "Merge Sort");
            mergeSort(v, start, mid);
            mergeSort(v, mid + 1, end);
            merge(v, start, mid, end);
        }
    }

    void merge(std::vector<std::pair<float, Color>> &v, uint32_t start,
               uint32_t mid, uint32_t end) {
        std::vector<std::pair<float, Color>> temp(end - start + 1);
        auto i{start};
        auto j{mid + 1};
        auto k{0};
        while (i <= mid && j <= end) {
            if (v[i].first < v[j].first) {
                temp[k++] = v[i++];
            } else {
                temp[k++] = v[j++];
            }
        }
        Visualize::visualizeVector(v, "Merge Sort");
        while (i <= mid) {
            temp[k++] = v[i++];
        }
        Visualize::visualizeVector(v, "Merge Sort");
        while (j <= end) {
            temp[k++] = v[j++];
        }
        Visualize::visualizeVector(v, "Merge Sort");
        for (auto i{0}; i < temp.size(); ++i) {
            v[start + i] = temp[i];
        }
    }

  public:
    explicit MergeSort(uint32_t size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Merge Sort");
    }

    ~MergeSort() noexcept override = default;

    MergeSort(const MergeSort &other) = delete;

    MergeSort &operator=(const MergeSort &other) = delete;

    MergeSort(MergeSort &&other) noexcept = default;

    MergeSort &operator=(MergeSort &&other) noexcept = default;

    void sort() override {
        auto v = vector_.getVector();
        mergeSort(v, 0, v.size() - 1);
        Visualize::visualizeVector(v, "Merge Sort");
        Visualize::visualizeEnding(v, "Merge Sort");
    }
};

#endif