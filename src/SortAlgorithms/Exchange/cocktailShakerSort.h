#ifndef COCKTAIL_SORT_H
#define COCKTAIL_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class CocktailShakerSort : public SortStrategy {
  public:
    CocktailShakerSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Cocktail Shaker Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        cocktailShakerSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Cocktail Shaker Sort");
    }

  private:
    auto cocktailShakerSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto size{end - start + 1};
        bool swapped{true};
        while (swapped) {
            swapped = false;
            for (auto i{start}; i != size - 1; ++i) {
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
    }
};

#endif