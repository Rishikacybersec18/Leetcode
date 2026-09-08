typedef struct {
    int q[100000];
    int front;
    int rear;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));

    obj->front = -1;
    obj->rear = -1;

    return obj;
}


int recentCounterPing(RecentCounter* obj, int t) {

  
    if (obj->front == -1) {
        obj->front = 0;
    }

    
    obj->rear++;
    obj->q[obj->rear] = t;

    
    while (obj->front <= obj->rear &&
           obj->q[obj->front] < t - 3000) {
        obj->front++;
    }

    
    return obj->rear - obj->front + 1;
}


void recentCounterFree(RecentCounter* obj) {
    free(obj);
}