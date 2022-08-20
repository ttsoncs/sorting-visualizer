#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "../sort.h"

class HeapSort : public SortStrategy {
  public:
    explicit HeapSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Heap Sort");
    }

    ~HeapSort() noexcept override = default;

    HeapSort(const HeapSort &other) = delete;

    HeapSort &operator=(const HeapSort &other) = delete;

    HeapSort(HeapSort &&other) noexcept = default;

    HeapSort &operator=(HeapSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        for (uint32_t i{static_cast<uint32_t>(v_.size()) / 2}; i > 0; --i) {
            siftDown(v_, i, v_.size() - 1);
            Visualize::visualize(v_, "Heap Sort");
        }

        for (uint32_t i{static_cast<uint32_t>(v_.size() - 1)}; i > 0; --i) {
            std::swap(v_[0], v_[i]);
            siftDown(v_, 0, i - 1);
            Visualize::visualize(v_, "Heap Sort");
        }
        Visualize::visualizeEnding(v_, "Heap Sort");
    }

  private:
    void siftDown(std::vector<std::pair<float, Color>> &v_, uint32_t start,
                  uint32_t end) {
        uint32_t root{start};
        while (root * 2 + 1 <= end) {
            uint32_t child{root * 2 + 1};
            if (child + 1 <= end && v_[child].first < v_[child + 1].first) {
                ++child;
            }
            if (v_[root].first < v_[child].first) {
                std::swap(v_[root], v_[child]);
                root = child;
            } else {
                break;
            }
        }
    }
};

#endif