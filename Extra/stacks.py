class StackList:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        self.items.pop()

    def is_empty(self):
        return len(self.items) == 0

    def peek(self):
        return self.items[-1]

    def size(self):
        return len(self.items)

class Node:
    def __init__(self, data):
        self.data = data

class StackLinked:
    def __init__(self):
        self.head = None

    def push(self, data):
       new_node = Node(data)
       new_node.next = self.head
       self.head = new_node

    def pop(self):
        if self.head is None:
            raise Exception("Stack is empty")
        data = self.head.data
        self.head = self.head.next
        return data

    def peek(self):
        if self.head is None:
            raise Exception("Stack is empty")
        return self.head.data

    def size(self):
        count = 0:
        current_node = self.head
        while current_node is not None:
            current_node = current_node.next
            count += 1
        return count

    def is_empty(self):
        return self.head is None