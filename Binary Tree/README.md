# [Binary Tree](https://www.geeksforgeeks.org/binary-tree-data-structure/?ref=lbp)

Binary Tree is defined as a tree data structure where each node has at most 2 children. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.

```
// Structure of each node of the tree
 
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} TreeNode;
```

## Time Complexity

* **Insertion**: The time complexity of insertions in a Binary Tree is `O(n)` in the worst case. This is because in the worst case, the algorithm might need to traverse all nodes of the tree (when the new node is inserted at the deepest and rightmost position).

* **Deletion**: The time complexity of deletions in a Binary Tree is also `O(n)` in the worst case. Similar to insertions, the algorithm might need to traverse all nodes of the tree in the worst case (when the deleted node is the deepest and rightmost node).

## Space Complexity

The space complexity of a Binary Tree is `O(n)`, where n is the number of nodes in the tree. This is because each node in the tree uses a constant amount of space, and the total space used is proportional to the number of nodes.