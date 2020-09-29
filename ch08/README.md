# Chapter 8: Arrays

## Reading Notes

- If the array initialiser is shorter than the array, the remaining elements of array are given the value 0:

```C
  int index_array[128] = {};
```

- **C99**: Designated initialisers:

```C
  int arr[15] = { [2] = 29, [9] = 7, [14] = 35 };
```

- **C99**: Variable-length array

- An initialiser mixes the element-by-element technique and the designated technique:

```C
  int c[10] = { 1, 5, 8, 78, [4] = 3, 7, 2, [8] = 6 };
```

- A trick to calculate length of an array: `(int) sizeof(arr) / sizeof(arr[0])`
- To declare a constant array, start its declaration with `const`.
### Related Chapters

- Chapter 12: relationship between arrays and pointers
- Chapter 26: `time`, `srand`, `rand` functions

## Exercising Notes 
- The most significant projects: 
  - [project 06](./projects/06.c) & [project 15](./projects/15.c): relationship between string and pointer
  - [project 17](./projects/17.c): implement De la Loubère's method to solve `NxN` magic square