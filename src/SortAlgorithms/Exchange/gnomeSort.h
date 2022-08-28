#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class GnomeSort : public SortStrategy {
  public:
    GnomeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Gnome Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        gnomeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Gnome Sort");
    }

  private:
    auto gnomeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto i{start};
        while (i != end + 1) {
            Visualize::visualizeTraverse(v, i, i - 1, "Gnome Sort");
            if (i == 0 || v[i].first >= v[i - 1].first) {
                ++i;
            } else {
                std::swap(v[i], v[i - 1]);
                --i;
            }
        }
    }
};

#endif