#ifndef SORT_CONTROLLER_H
#define SORT_CONTROLLER_H

#include "sort.h"
#include <memory>

class SortController {
  private:
    std::unique_ptr<SortStrategy> sortStrategy_;

  public:
    SortController() = default;

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