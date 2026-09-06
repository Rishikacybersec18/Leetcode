#include <stdbool.h>

int top = -1;

void push(char a, char *m) {
    if (top < 200) {
        top++;
        m[top] = a;
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

bool backspaceCompare(char* s, char* t) {

    char stackS[201];
    char stackT[201];

    // Process s
    top = -1;

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == '#') {
            pop();
        }
        else {
            push(s[i], stackS);
        }
    }

    int topS = top;

    // Process t
    top = -1;

    for (int i = 0; t[i] != '\0'; i++) {

        if (t[i] == '#') {
            pop();
        }
        else {
            push(t[i], stackT);
        }
    }

    int topT = top;

    if (topS != topT)
        return false;

    for (int i = 0; i <= topS; i++) {

        if (stackS[i] != stackT[i])
            return false;
    }

    return true;
}