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

1
2