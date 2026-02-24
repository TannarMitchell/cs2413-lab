#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {

    if (s == NULL) {
        return false;
    }

    size_t length = strlen(s);

    if (length % 2 != 0) {
        return false;
    }

    char Mystack[length];
    int top = -1;

    for (size_t i = 0; i < length; i++) {

        char check = s[i];

        if ((check == '(') || (check == '{') || (check == '[')) {

            Mystack[++top] = check;

        } 
        else {  // closing bracket

            if (top == -1) {
                return false;
            }

            char topCharacter = Mystack[top];

            if ((check == ')' && topCharacter == '(') ||
                (check == '}' && topCharacter == '{') ||
                (check == ']' && topCharacter == '[')) {

                top--;  // pop

            } 
            else {
                return false;
            }
        }
    }

    return top == -1;
}
