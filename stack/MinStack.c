typedef struct {
    int stack[10000];
    int ratio[10000];
    int top;
    int rtop;
} MinStack;


MinStack* minStackCreate() {
    MinStack *q = malloc(sizeof(MinStack));

    q->top = -1;
    q->rtop = -1;

    return q;
}


void minStackPush(MinStack* obj, int value) {

    // Main stack: always push
    if (obj->top < 9999) {
        obj->top++;
        obj->stack[obj->top] = value;

        // Min stack
        if (obj->rtop == -1 || value <= obj->ratio[obj->rtop]) {
            obj->rtop++;
            obj->ratio[obj->rtop] = value;
        }
    }
}


void minStackPop(MinStack* obj) {

    if (obj->top == -1) {
        return;
    }

    // Check the value BEFORE decreasing top
    if (obj->stack[obj->top] == obj->ratio[obj->rtop]) {
        obj->rtop--;
    }

    obj->top--;
}


int minStackTop(MinStack* obj) {

    if (obj->top == -1) {
        return -1;
    }

    return obj->stack[obj->top];
}


int minStackGetMin(MinStack* obj) {

    if (obj->rtop == -1) {
        return -1;
    }

    return obj->ratio[obj->rtop];
}


void minStackFree(MinStack* obj) {
    free(obj);
}
