#include<iostream>
#include<cstring>

namespace ca {
    class String {
    private:
        char* str;
        void copy(const String& other) {
            str = new char[strlen(other.str) + 1];
            strcpy_s(str, strlen(other.str) + 1, other.str);
        }

    public:
        String() {
            str = new char[1];
            str[0] = '\0';
        }

        String(const char* s) {
            str = new char[strlen(s) + 1];
            strcpy_s(str, strlen(s) + 1, s);
        }

        String& operator=(const String& other) {
            if (this == &other) {
                return *this;
            }
            delete[] str;
            copy(other);
            return *this;
        }

        String(const String& other) {
            copy(other);
        }

        ~String() {
            delete[] str;
        }

        const char* c_str() const {
            return str;
        }
    };
}
