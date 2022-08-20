#ifndef TIM_SORT_H
#define TIM_SORT_H

#include "../sort.h"

class TimSort : public SortStrategy {
  private:
    void timSort(std::vector<std::pair<float, Color>> &v_, uint32_t start,
                 uint32_t end) {
        if (end - start < 15) {
            insertionSort(v_, start, end);
            return;
        }
        uint32_t mid{(start + end) / 2};
        timSort(v_, start, mid);
        timSort(v_, mid + 1, end);
        if (v_[mid].first > v_[mid + 1].first) { merge(v_, start, mid, end); }
    }

    void insertionSort(std::vector<std::pair<float, Color>> &v_, uint32_t start,
                       uint32_t end) {
        for (uint32_t i{start + 1}; i <= end; ++i) {
            auto [value, color] = v_[i];
            uint32_t j{i};
            while (j > start && v_[j - 1].first > value) {
                v_[j] = v_[j - 1];
                --j;
            }
            v_[j] = std::make_pair(value, color);
            Visualize::visualize(v_, "Tim Sort");
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
            Visualize::visualize(v_, "Tim Sort");
        }
        while (i <= mid) {
            temp[k++] = v_[i++];
            Visualize::visualize(v_, "Tim Sort");
        }
        while (j <= end) {
            temp[k++] = v_[j++];
            Visualize::visualize(v_, "Tim Sort");
        }
        for (uint32_t i{0}; i < temp.size(); ++i) {
            v_[start + i] = temp[i];
        }
    }

  public:
    explicit TimSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Tim Sort");
    }

    ~TimSort() noexcept override = default;

    TimSort(const TimSort &other) = delete;

    TimSort &operator=(const TimSort &other) = delete;

    TimSort(TimSort &&other) noexcept = default;

    TimSort &operator=(TimSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        timSort(v_, 0, v_.size() - 1);
        Visualize::visualize(v_, "Tim Sort");
        Visualize::visualizeEnding(v_, "Tim Sort");
    }
};

#endif