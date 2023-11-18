int Queue::peek() {
    if (front == rear) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return queue[front];
}
