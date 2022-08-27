#ifndef STALIN_SORT_H
#define STALIN_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class StalinSort : public SortStrategy {
  public:
    StalinSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Stalin Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        stalinSort(v);
        Visualize::visualizeEnding(v, "Stalin Sort");
    }

  private:
    auto stalinSort(std::vector<std::pair<int, std::pair<float, Color>>> &v) -> void {
        auto j{0};
        while (true) {
            auto moved{0};
            for (auto i{0}; i != v.size() - 1 - j; ++i) {
                Visualize::visualizeTraverse(v, i, i + 1, "Stalin Sort");
                if (v[i].first > v[i + 1].first) {
                    std::vector<std::pair<int, std::pair<float, Color>>>::iterator it{v.begin() + i + 1};
                    auto temp{v[i + 1]};
                    v.erase(it);
                    v.insert(v.begin() + moved, temp);
                    ++moved;
                }
            }
            ++j;
            if (moved == 0) {
                break;
            }
        }
    }
};

#endif