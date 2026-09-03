typedef struct {
    int *queue;
    int front;
    int rear;
} MyStack;


MyStack* myStackCreate() {
    MyStack *q = malloc(sizeof(MyStack));

    q->queue = malloc(10000 * sizeof(int));
    q->front = 0;
    q->rear = -1;

    return q;
}


void myStackPush(MyStack* obj, int x) {

    // Insert normally at rear
    obj->rear++;
    obj->queue[obj->rear] = x;

    // Move all previous elements behind x
    int size = obj->rear - obj->front;

    for (int i = 0; i < size; i++) {

        int temp = obj->queue[obj->front];
        obj->front++;

        obj->rear++;
        obj->queue[obj->rear] = temp;
    }
}


int myStackPop(MyStack* obj) {

    if (obj->front > obj->rear) {
        return -1;
    }

    int value = obj->queue[obj->front];
    obj->front++;

    return value;
}


int myStackTop(MyStack* obj) {

    if (obj->front > obj->rear) {
        return -1;
    }

    return obj->queue[obj->front];
}


bool myStackEmpty(MyStack* obj) {

    return obj->front > obj->rear;
}


void myStackFree(MyStack* obj) {
    free(obj->queue);
    free(obj);
}