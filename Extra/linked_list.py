class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)

        if self.head == None:
            self.head = new_node
            return

        current_node = self.head
        while current_node.next is not None:
            current_node = current_node.next

        current_node.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_after_node(self, prev_node, data):
        if not prev_node:
            print("Previous node is not in the list.")
            return

        new_node = Node(data)
        prev_node_next = new_node
        new_node.next = prev_node.next

    def delete_node(self, key):
        current_node = self.head
        if current_node and current_node.data == key:
            self.head = current_node.next
            current_node = None
            return

        previous_node = None
        while current_node and current_node.data != key:
            previous_node = current_node
            current_node = current_node.next

        if current_node is None:
            return

        previous_node.next = current_node.next
        current_node = None

    def delete_node_at_position(self, position):
        current_node = self.head

        if position == 0:
            self.head = current_node.next
            current_node = None
            return

        previous_node = None
        count = 0

        while current_node and count != position:
            previous_node = current_node
            current_node = current_node.next
            count += 1

        if current_node is None:
            return

        previous_node.next = current_node.next
        current_node = None

    def print_list(self):
        current_node = self.head
        while current_node:
            print(current_node.data)
            current_node = current_node.next

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, data):
        new_node = DoublyLinkedListNode(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node

    def prepend(self, data):
        new_node = DoublyLinkedListNode(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def insert_after_node(self, prev_node, data):
        if prev_node is None:
            print("Previous node is not in the list.")
            return

        new_node = DoublyLinkedListNode(data)
        new_node.next = prev_node.next
        prev_node.next = new_node
        new_node.prev = prev_node
        if new_node.next is not None:
            new_node.next.prev = new_node

    def delete_node(self, key):
        current_node = self.head
        while current_node is not None and current_node.data != key:
            current_node = current_node.next
        if current_node is None:
            print("Node with key " + str(key) + " not found in the list.")
            return

        if current_node.prev is None:
            self.head = current_node.next
        else:
            current_node.prev.next = current_node.next

        if current_node.next is None:
            self.tail = current_node.prev
        else:
            current_node.next.prev = current_node.prev

        current_node = None

    def print_forward(self):
        current_node = self.head
        while current_node is not None:
            print(current_node.data)
            current_node = current_node.next

    def print_backward(self):
        current_node = self.tail
        while current_node is not None:
            print(current_node.data)
            current_node = current_node.prev


def main():
    list = LinkedList()
    list.append(4)
    list.print_list()
    print()
    new_list = [5,6,7,8,9,10]
    for i in range(len(new_list)):
        list.append(new_list[i])
    list.print_list()
    print()
    list.delete_node(6)
    list.print_list()
    print()
    list.insert_after_node(Node(5), 1)
    list.print_list()

main()

