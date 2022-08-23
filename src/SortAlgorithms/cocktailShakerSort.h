#ifndef COCKTAIL_SORT_H
#define COCKTAIL_SORT_H

#include "../sortStrategy.h"

class CocktailShakerSort : public SortStrategy {
  public:
    explicit CocktailShakerSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Cocktail Shaker Sort");
    }

    ~CocktailShakerSort() noexcept override = default;

    CocktailShakerSort(const CocktailShakerSort &other) = default;

    CocktailShakerSort &operator=(const CocktailShakerSort &other) = default;

    CocktailShakerSort(CocktailShakerSort &&other) noexcept = default;

    CocktailShakerSort &operator=(CocktailShakerSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        bool swapped{true};
        while (swapped) {
            swapped = false;
            for (auto i{0}; i != size - 1; ++i) {
                Visualize::visualizeTraverse(v, i, i + 1, "Cocktail Shaker Sort");
                if (v[i].first > v[i + 1].first) {
                    std::swap(v[i], v[i + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
            swapped = false;
            for (auto i{size - 1}; i != 0; --i) {
                Visualize::visualizeTraverse(v, i, i - 1, "Cocktail Shaker Sort");
                if (v[i].first < v[i - 1].first) {
                    std::swap(v[i], v[i - 1]);
                    swapped = true;
                }
            }
        }
        Visualize::visualizeEnding(v, "Cocktail Shaker Sort");
    }
};

#endif