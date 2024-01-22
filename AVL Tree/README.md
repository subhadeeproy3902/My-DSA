# [AVL Tree](https://www.geeksforgeeks.org/introduction-to-avl-tree/?ref=lbp)

The difference between the heights of the left subtree and the right subtree for any node is known as the balance factor of the node.

The AVL tree is named after its inventors, Georgy Adelson-Velsky and Evgenii Landis, who published it in their 1962 paper “An algorithm for the organization of information”.

```
        50                30
       /  \              /  \
     30    70           20   40
    /  \  /  \         /  \    \
  20  40 60   80      10   25   50
 /  
10

```

## Time Complexity

* **Insertion**: The time complexity of AVL tree insertions is `O(log n)`. This is because the tree remains balanced after each insertion, which ensures that the maximum number of nodes the algorithm might traverse to insert a new node is logarithmic relative to the number of nodes in the tree.

* **Deletion**: The time complexity of AVL tree deletions is also `O(log n)`. Similar to insertions, the tree remains balanced after each deletion, which ensures that the maximum number of nodes the algorithm might traverse to delete a node is logarithmic relative to the number of nodes in the tree.

## Space Complexity

The space complexity of an AVL tree is `O(n)`, where n is the number of nodes in the tree. This is because each node in the tree uses a constant amount of space, and the total space used is proportional to the number of nodes.