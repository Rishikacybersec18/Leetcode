char st[10000];
int top = -1;

void PUSH(char c) {
    if(top != 9999) {
        top++;
        st[top] = c;
    }
}

char pop() {
    char item;

    if(top != -1) {
        item = st[top];
        top--;
        return item;
    }

    return -1;
}

char peek(int top) {
    char topmost;
    topmost = st[top];
    return topmost;
}

bool isValid(char* s) {
    int i;

    for(i = 0; s[i] != '\0'; i++) {

        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            PUSH(s[i]);
        }
        else {

            if(top == -1) {
                return false;
            }

            char f;
            f = pop();

            if((f == '(' && s[i] != ')') ||
               (f == '{' && s[i] != '}') ||
               (f == '[' && s[i] != ']')) {

                return false;
            }
        }
    }

    if(top == -1) {
        return true;
    }
    else {
        return false;
    }
}