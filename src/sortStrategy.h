#ifndef SORT_STRATEGY_H
#define SORT_STRATEGY_H

class SortStrategy {
  public:
    SortStrategy() = default;

    virtual ~SortStrategy() noexcept = default;

    SortStrategy(const SortStrategy &other) = delete;

    auto operator=(const SortStrategy &other) -> SortStrategy & = delete;

    SortStrategy(SortStrategy &&other) noexcept = default;

    auto operator=(SortStrategy &&other) noexcept -> SortStrategy & = default;

    virtual auto sort() -> void = 0;
};

#endif