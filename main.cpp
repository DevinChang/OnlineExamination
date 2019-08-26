#include "stdx.h"
#include "MeiTuan8_22.h"


int main() {
    MeiTuan8_22 meituan;
    std::string str = "MPMPCPMCMDEFEGDEHINHKLIN";
    std::string str2 = "ababcbacadefegdehijhklij";
    meituan.latestKuaiDiWrap(str2);
    std::vector<std::string> words{"wrt", "wrf", "er", "ett", "rftt"};
    std::vector<std::string> words2{"z", "z"};
    meituan.alienOrder(words2);
    return 0;
}