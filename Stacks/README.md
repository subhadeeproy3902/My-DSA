# [Stack](https://www.geeksforgeeks.org/stack-data-structure/)

### General Structure - 

```
int top = -1;
int stack[100];

void push(int item)
{
  stack[++top] = item;
}

int pop()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    return -1;
  }
  return stack[top--];
}
```
