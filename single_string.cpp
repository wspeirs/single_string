#include "single_string.h"

single_string::string_table_t single_string::string_table;
const single_string single_string::EMPTY_STRING("");

single_string::single_string() {
    this->str_ptr = EMPTY_STRING.str_ptr;
}

single_string::single_string(const std::string &str) {
    auto it = string_table.find(str);

    if(it == string_table.end()) {
        str_ptr = new std::string(str);
        string_table.insert(std::make_pair(*str_ptr, str_ptr));
    } else {
        str_ptr = it->second;
    }
}

void single_string::free_all() {
    for(auto s : string_table) {
        delete s.second;
    }
}

namespace std {
    size_t hash<single_string>::operator()(const single_string &str) const {
        return size_t(str.str_ptr);
    }
}
