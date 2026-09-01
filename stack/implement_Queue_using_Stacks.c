typedef struct {
    int stack[10000];
    int top;
    int peak;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = malloc(sizeof(MyQueue));

    q->top = -1;
    q->peak = 0;

    return q;
}

void myQueuePush(MyQueue* obj, int x) {

    // Queue overflow
    if (obj->top >= 9999) {
        return;
    }

    obj->top++;
    obj->stack[obj->top] = x;
}

int myQueuePop(MyQueue* obj) {

    // Queue is empty
    if (obj->peak > obj->top) {
        return -1;
    }

    int item = obj->stack[obj->peak];
    obj->peak++;

    return item;
}

int myQueuePeek(MyQueue* obj) {

    if (obj->peak > obj->top) {
        return -1;
    }

    return obj->stack[obj->peak];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->peak > obj->top;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}