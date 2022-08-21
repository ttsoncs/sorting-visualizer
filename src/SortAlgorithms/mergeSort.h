#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../sortStrategy.h"
class MergeSort : public SortStrategy {
  private:
    void mergeSort(std::vector<std::pair<float, Color>> &v_, uint32_t start,
                   uint32_t end) {
        if (start < end) {
            uint32_t mid{(start + end) / 2};
            Visualize::visualizeBar(v_, start, "Merge Sort");
            Visualize::visualizeBar(v_, mid, "Merge Sort");
            Visualize::visualizeBar(v_, end, "Merge Sort");
            Visualize::visualizeVector(v_, "Merge Sort");
            mergeSort(v_, start, mid);
            mergeSort(v_, mid + 1, end);
            merge(v_, start, mid, end);
        }
    }

    void merge(std::vector<std::pair<float, Color>> &v_, uint32_t start,
               uint32_t mid, uint32_t end) {
        std::vector<std::pair<float, Color>> temp(end - start + 1);
        uint32_t i{start}, j{mid + 1}, k{0};
        while (i <= mid && j <= end) {
            if (v_[i].first < v_[j].first) {
                temp[k++] = v_[i++];
            } else {
                temp[k++] = v_[j++];
            }
        }
        Visualize::visualizeVector(v_, "Merge Sort");
        while (i <= mid) {
            temp[k++] = v_[i++];
        }
        Visualize::visualizeVector(v_, "Merge Sort");
        while (j <= end) {
            temp[k++] = v_[j++];
        }
        Visualize::visualizeVector(v_, "Merge Sort");
        for (uint32_t i{0}; i < temp.size(); ++i) {
            v_[start + i] = temp[i];
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
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        mergeSort(v_, 0, v_.size() - 1);
        Visualize::visualizeVector(v_, "Merge Sort");
        Visualize::visualizeEnding(v_, "Merge Sort");
    }
};

#endif