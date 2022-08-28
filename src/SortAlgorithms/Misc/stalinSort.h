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
        stalinSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Stalin Sort");
    }

  private:
    auto stalinSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto j{0};
        while (true) {
            auto moved{0};
            for (auto i{start}; i != end - j; ++i) {
                if (v[i].first > v[i + 1].first) {
                    Visualize::visualizeTraverse(v, i, i + 1, "Stalin Sort");
                    auto it{v.begin() + i + 1};
                    auto key{v[i + 1]};
                    v.erase(it);
                    v.insert(v.begin() + moved, key);
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