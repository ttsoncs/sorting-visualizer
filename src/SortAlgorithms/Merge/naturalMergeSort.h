#ifndef NATURAL_MERGE_SORT_H
#define NATURAL_MERGE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class NaturalMergeSort : public SortStrategy {
  public:
    NaturalMergeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Natural Merge Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        naturalMergeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Natural Merge Sort");
    }

  private:
    auto naturalMergeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        std::vector<std::pair<int, std::pair<float, Color>>> temp(v.size());
        auto n{end - start + 1};
        auto l{start};
        auto r{start};
        auto m{start};
        auto i{start};
        auto j{start};
        auto k{start};
        auto len{1};
        while (len < n) {
            l = 0;
            r = len;
            while (r + len <= n) {
                m = r + len;
                i = l;
                j = r;
                k = 0;
                while (i < r && j < m) {
                    Visualize::visualizeTraverse(v, i, j, "Natural Merge Sort");
                    if (v[i].first < v[j].first) {
                        temp[k++] = v[i++];
                    } else {
                        temp[k++] = v[j++];
                    }
                }
                while (i < r) {
                    temp[k++] = v[i++];
                }
                while (j < m) {
                    temp[k++] = v[j++];
                }
                for (i = l; i < m; ++i) {
                    v[i] = temp[i - l];
                }
                l = m;
                r = m + len;
            }
            if (r < n) {
                m = n;
                i = l;
                j = r;
                k = 0;
                while (i < r && j < m) {
                    Visualize::visualizeTraverse(v, i, j, "Natural Merge Sort");
                    if (v[i].first < v[j].first) {
                        temp[k++] = v[i++];
                    } else {
                        temp[k++] = v[j++];
                    }
                }
                while (i < r) {
                    temp[k++] = v[i++];
                }
                while (j < m) {
                    temp[k++] = v[j++];
                }
                for (i = l; i < m; ++i) {
                    v[i] = temp[i - l];
                }
            }
            len *= 2;
        }
    }
};

#endif