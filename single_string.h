#ifndef SINGLE_STRING_H_
#define SINGLE_STRING_H_

#include <unordered_map>
#include <string>

class single_string {
private:
    typedef std::unordered_map<std::string, std::string*> string_table_t;
    static string_table_t string_table;

    std::string *str_ptr;

    friend class std::hash<single_string>; // allows hash to access str_ptr
    friend bool operator==(const single_string& lhs, const single_string& rhs);

public:
    single_string(const std::string &str);

    static void free_all();

    inline const char* c_str() const;

    inline char& operator[](std::size_t pos );

    inline const char& operator[](std::size_t pos) const;

    inline int compare(const std::string& str) const;

    inline int compare(const char* str) const;

    inline int compare(const single_string& str) const;
};

bool operator==(const single_string& lhs, const single_string& rhs);

namespace std {
    template <>
    class hash<single_string> {
    public:
        size_t operator()(const single_string &str) const;
    };
}

#endif
