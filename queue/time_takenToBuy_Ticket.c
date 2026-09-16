int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {

    int queue[10000];

    int front = 0;
    int rear = -1;

    int person;
    int time = 0;

    // Initialize queue with person indices
    for (int i = 0; i < ticketsSize; i++) {
        rear++;
        queue[rear] = i;
    }

    // Continue until person k finishes
    while (tickets[k] > 0) {

        // Take person from front
        person = queue[front];
        front = (front + 1) % ticketsSize;

        // Person buys one ticket
        tickets[person]--;
        time++;

        // If they still need tickets, move them to the rear
        if (tickets[person] > 0) {
            rear = (rear + 1) % ticketsSize;
            queue[rear] = person;
        }
    }

    return time;
}