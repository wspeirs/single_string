#ifndef SINGLE_STRING_H_
#define SINGLE_STRING_H_

#include <unordered_map>
#include <string>

class single_string {
private:
    typedef std::unordered_map<std::string, std::string*> string_table_t;
    static string_table_t string_table;
    static const single_string EMPTY_STRING;

    std::string *str_ptr;

    friend class std::hash<single_string>; // allows hash to access str_ptr
    friend bool operator==(const single_string& lhs, const single_string& rhs);
    friend bool operator==(const single_string &lhs, const char *rhs);
    friend bool operator!=(const single_string& lhs, const single_string& rhs);
    friend bool operator!=(const single_string &lhs, const char *rhs);

public:
    single_string();

    single_string(const std::string &str);

    static void free_all();

    inline std::string& to_string() const {
        return *str_ptr;
    }

    inline const char* c_str() const {
        return str_ptr->c_str();
    }

    inline char& operator[](std::size_t pos ) {
        return str_ptr->operator[](pos);
    }

    inline const char& operator[](std::size_t pos) const {
        return str_ptr->operator[](pos);
    }

    inline int compare(const std::string& str) const {
        return str_ptr->compare(str);
    }

    inline int compare(const char* str) const {
        return str_ptr->compare(str);
    }

    inline int compare(const single_string& str) const {
        return str_ptr->compare(*(str.str_ptr));
    }
};

inline bool operator==(const single_string& lhs, const single_string& rhs) {
    return lhs.str_ptr == rhs.str_ptr; // only need to check pointers
}

inline bool operator==(const single_string &lhs, const char *rhs) {
    return lhs.str_ptr == single_string(rhs).str_ptr;
}

inline bool operator!=(const single_string& lhs, const single_string& rhs) {
    return lhs.str_ptr != rhs.str_ptr; // only need to check pointers
}

inline bool operator!=(const single_string &lhs, const char *rhs) {
    return lhs.str_ptr != single_string(rhs).str_ptr;
}

inline std::string operator+(const std::string &lhs, const single_string &rhs) {
    return lhs + rhs.to_string();
}


namespace std {
    template <>
    class hash<single_string> {
    public:
        size_t operator()(const single_string &str) const;
    };
}

#endif
