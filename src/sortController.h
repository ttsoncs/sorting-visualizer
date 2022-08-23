#ifndef SORT_CONTROLLER_H
#define SORT_CONTROLLER_H

#include "SortAlgorithms/bubbleSort.h"
#include <memory>

class SortController {
private:
  std::unique_ptr<SortStrategy> sortStrategy_;

public:
  SortController() { sortStrategy_ = std::make_unique<BubbleSort>(100); }

  explicit SortController(std::unique_ptr<SortStrategy> sortStrategy)
      : sortStrategy_{std::move(sortStrategy)} {}

  ~SortController() noexcept = default;

  SortController(const SortController &other) = delete;

  SortController &operator=(const SortController &other) = delete;

  SortController(SortController &&other) noexcept = default;

  SortController &operator=(SortController &&other) noexcept = default;

  void setSortStrategy(std::unique_ptr<SortStrategy> sortStrategy) {
    sortStrategy_ = std::move(sortStrategy);
  }

  void sort() { sortStrategy_->sort(); }
};

#endif