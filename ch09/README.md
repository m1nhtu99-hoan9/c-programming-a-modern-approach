# Chapter 9: Functions

## Reading Notes

- **C99** Variable-Length Array Parameters: 

```C
int func_arr(int n, int a[n]);
int func_arr(int n, int a[*]);
int func_arr(int, int a[*]);
```

- **C99** `static` in Array Parameter Declarations: 

```C
int sum_array(int a[static 3], int n);
```

- **C99** Compound Literals:

```C
int total = sum_array((int []) {3, 0, 3, 4, 1}, 5);  
```

### Related Chapters

## Exercising Notes