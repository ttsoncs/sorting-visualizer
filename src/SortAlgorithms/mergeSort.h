#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../sortStrategy.h"

class MergeSort : public SortStrategy {
  private:
    void mergeSort(std::vector<std::pair<float, Color>> &v, int start,
                   int end) {
        if (start < end) {
            auto mid{(start + end) / 2};
            mergeSort(v, start, mid);
            mergeSort(v, mid + 1, end);
            merge(v, start, mid, end);
        }
    }

    void merge(std::vector<std::pair<float, Color>> &v, int start, int mid,
               int end) {
        std::vector<std::pair<float, Color>> temp(end - start + 1);
        auto i{start};
        auto j{mid + 1};
        auto k{0};
        while (i <= mid && j <= end) {
            BeginDrawing();
            Visualize::visualizeVector(v, "Merge Sort");
            if (v[i].first < v[j].first) {
                Visualize::visualizeBar(v, i, "Merge Sort");
                temp[k++] = v[i++];
            } else {
                Visualize::visualizeBar(v, j, "Merge Sort");
                temp[k++] = v[j++];
            }
            EndDrawing();
        }
        while (i <= mid) {
            BeginDrawing();
            Visualize::visualizeVector(v, "Merge Sort");
            Visualize::visualizeBar(v, i, "Merge Sort");
            temp[k++] = v[i++];
            EndDrawing();
        }
        while (j <= end) {
            BeginDrawing();
            Visualize::visualizeVector(v, "Merge Sort");
            Visualize::visualizeBar(v, j, "Merge Sort");
            temp[k++] = v[j++];
            EndDrawing();
        }
        for (auto i{0}; i < temp.size(); ++i) {
            v[start + i] = temp[i];
        }
    }

  public:
    explicit MergeSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Merge Sort");
    }

    ~MergeSort() noexcept override = default;

    MergeSort(const MergeSort &other) = delete;

    MergeSort &operator=(const MergeSort &other) = delete;

    MergeSort(MergeSort &&other) noexcept = default;

    MergeSort &operator=(MergeSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        mergeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Merge Sort");
    }
};

#endif