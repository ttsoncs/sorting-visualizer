#ifndef SHELL_METZNER_SORT_H
#define SHELL_METZNER_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class ShellMetznerSort : public SortStrategy {
  public:
    ShellMetznerSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Shell-Metzner Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        shellMetznerSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Shell-Metzner Sort");
    }

  private:
    auto shellMetznerSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int left, int right) -> void {
        auto m{v.size()};
        while (m > 0) {
            m = m / 2;
            auto k{v.size() - m};
            auto j{0};
            do {
                auto i{j};
                do {
                    auto l{i + m};
                    Visualize::visualizeTraverse(v, i, l, "Shell-Metzner Sort");
                    if (v[i].first > v[l].first) {
                        std::swap(v[i], v[l]);
                        i -= m;
                    } else {
                        break;
                    }
                } while (i >= left);
                ++j;
            } while (j < k);
        }
    }
};

#endif