class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.zie = 0

    def enqueue(self, data):
        new_node = Node(data)
        if self.front is None:
            self.front = new_node
            self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node
        self.size += 1

    def dequeue(self):
        if self.front is None:
            raise Exception("Queue is empty!")
        data = self.fron.data
        self.front = self.front.next
        self.size -= 1
        if self.front is None:
            self.rear = None
        return data

    def peek(self):
        if self.front is None:
            raise Exception("Queue is empty!")
        return self.front.data

    def is_empty(self):
        return self.front is None

    def size(self):
        return self.size