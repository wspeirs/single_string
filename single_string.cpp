#include "single_string.h"

single_string::string_table_t single_string::string_table;

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

inline const char* single_string::c_str() const {
    return str_ptr->c_str();
}

inline char& single_string::operator[](std::size_t pos ) {
    return str_ptr->operator[](pos);
}

inline const char& single_string::operator[](std::size_t pos) const {
    return str_ptr->operator[](pos);
}

inline int single_string::compare(const std::string& str) const {
    return str_ptr->compare(str);
}

inline int single_string::compare(const char* str) const {
    return str_ptr->compare(str);
}

inline int single_string::compare(const single_string& str) const {
    return str_ptr->compare(*(str.str_ptr));
}

bool operator==(const single_string& lhs, const single_string& rhs) {
    return lhs.str_ptr == rhs.str_ptr; // only need to check pointers
}

namespace std {
    size_t hash<single_string>::operator()(const single_string &str) const {
        return size_t(str.str_ptr);
    }
}
