#include "trim.h"

#include <string>
#include <algorithm>
#include <cctype>

void trim(std::string* s) {
    auto& str = *s;
    str.erase(str.begin(),
              std::find_if(str.begin(), str.end(),
                           [](unsigned char ch){ return !std::isspace(ch); }));

    str.erase(std::find_if(str.rbegin(), str.rend(),
                           [](unsigned char ch){ return !std::isspace(ch); }).base(),
              str.end());
}
