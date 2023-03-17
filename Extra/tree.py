class Node:
    def __init__ (self, data):
        self.data = data
        self.left_child = None
        self.right_child = None

class BinaryTree:
    def __init__(self, root):
        self.root = Node(root)

    def inset_node(self, data):
        new_node = Node(data)
        current_node = self.root

       while True:
        if new_node.data < current_node.data:
            if current_node.left_child is None:
                current_node.left_child = new_node
                break
            else:
                current_node = current_node.left_child
        else:
            if current_node.right_child is None:
                current_node.right_child = new_node
                break
            else:
                current_node = current_node.right_child

    def delete_node(self, data):
        if self.root is None:
            return self.root

        current_node = self.root
        parent_node = None
        while current_node is not None and current_node.data != data:
            parent_node = current_node
            if data < current_node.data:
                current_node = current_node.left_child
            else:
                current_node = current_node.right_child

        if current_node is None:
            return self.root

        # Case 1: If the node has no children
        if current_node.left_child is None and current_node.right_child is None:
            if parent_node is None:
                self.root = None
            elif parent_node.left_child == current_node:
                parent_node.left_child = None
            else:
                parent_node.right_child = None

        # Case 2: If the node has one child
        elif current_node.left_child is None:
            if parent_node is None:
                self.root = current_node.right_child
            elif parent_node.left_child == current_node:
                parent_node.left_child = current_node.right_child
            else:
                parent_node.right_child = current_node.right_child

        elif current_node.right_child is None:
            if parent_node is None:
                self.root = current_node.left_child
            elif parent_node.left_child == current_node:
                parent_node.left_child = current_node.left_child
            else:
                parent_node.right_child = current_node.left_child

        # Case 3: if the node has two children
        else:
            min_node = current_node.right_child
            while min_node.left_child is not None:
                min_node = min_node.left_child
            current_node.data = min_node.data
            self.delete_node(min_node.data)

        return self.root

