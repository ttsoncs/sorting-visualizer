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
    auto shellMetznerSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto size{end - start + 1};
        auto m{size};
        while (m > 0) {
            m /= 2;
            auto k{size - m};
            auto i{0};
            do {
                auto j{i};
                do {
                    auto l{j + m};
                    if (v[j].first > v[l].first) {
                        Visualize::visualizeTraverse(v, j, l, "Shell-Metzner Sort");
                        std::swap(v[j], v[l]);
                        j -= m;
                    } else {
                        break;
                    }
                } while (j >= start);
                ++i;
            } while (i < k);
        }
    }
};

#endif