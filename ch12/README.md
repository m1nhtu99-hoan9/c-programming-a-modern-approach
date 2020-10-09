#Chapter 12: Pointers and Arrays 

## Reading Notes

- **C99** Pointers to compound literals:

```C
int *p = (int []) {3, 0, 2, 5, 6};
```

- Pointer arithmetic:
    - Postfix version of `++` has precedence over `*` so that `*p++` is the same as `*(p++)` and `*++p` is the same as `*(++p)`.

- Two-dimensional array:
    - `a[i][j]` is the same as `*(a[i] + j)`
    
- Trivia: 
    - In C, `i[a]` is the same as `a[i]` because C interprets them as `*(a + i)`
    
### Related Chapters

- [Chapter 13](../ch13): Strings
- [Chapter 17](../ch17): Advanced Uses of Pointers

## Exercising Notes