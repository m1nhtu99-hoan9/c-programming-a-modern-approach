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


### Errata

- In page 217:

 ```C
void create_magic_square (int n, char magic_square[n][n]);
void print_magic_square (int n, char magic_square[n][n]); 
 ```

is actually: 

```C
void create_magic_square (int n, int magic_square[n][n]);
void print_magic_square (int n, int magic_square[n][n]); 
```

## Exercising Notes
- The most significant projects: 
    - [project 01](./projects/01.c): recursive selection sort