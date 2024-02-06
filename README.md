```
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    
}

int main(){
    printf("0. Exit\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    
    int choice, data;
    
    while(1){
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                exit(1);
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                break;
            case 2:
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                break;
            case 3: 
                display();
                printf("\n");
                break;
            default:    
                printf("Invalid choice...\n");
        }
    }
    return 0;
}
```
Practice List for lab exm :(  --->

1. Doubly LL - Done
2. Deque - Done 
3. Priority Q- Done
4. Add and Mul - Done
5. Sort List - Done
6. Parenthesis Checker - Done
7. Binary Search - Done
8. Interpolation Search - Done
9. Merge Sort - Done
10. Insertion Sort - Done
11. CLL - Done
12. BST - Done
13. Insert In a Sorted Way - Done
14. AVL - Done
15. Horner - Done
16. BFS - Done
17. DFS - Done
18. Infix to Postfix - Done
19. Prefix to Postfix - Done
20. Postfix Evaluation - Done
21. Tower Of Hanoi - Done
22. Stack with Q - Done
23. Q with Stack - Done
24. Expression Tree - Done
25. Josephus 
26. Heap Sort - Done