# Chapter 7: Basic Types

## Reading Notes

- Range of values for integer types are different among 16-bit, 32-bit and 64-bit CPUs.
- **C99** standard allows implementation-defined extended integer types.
- C treats characters as small integers
- For escape characters, numeric escapes can be written using either _octal_ escape sequence (i.e. `\033`, `\33`) or _hexadecimal_ escape sequence (i.e. `\x1b`, `\x1B`)
- To read character, use `ch = getchar()` instead of `scanf("%c", &ch)`

```C
while ((chr = getchar()) != '\n')
  ;
```

- In **C99**, arithmetic types include:
  - Integer types:
    - `char`
    - Signed integer types, both standard (`signed char`, `short int`, `int`, `long int`, `long long int`) and extended
    - Unsigned integer types, both standard (`unsigned char`, `unsigned short int`, `unsigned int`, `unsigned long int`, `unsigned long long int`, `_Bool`) and extended
    - Enumerated types
  - Floating types:
    - Real floating types (`float.double`, `long.double`)
    - Complex types (`float _Complex`, `double _Complex`, `long double _Complex`)
- `sizeof` operator:

```C
printf("Size of int: %zu\n", sizeof(int));
```

### Related Chapters

- Chapter 9: Implicit type conversions
- Chapter 20: Octal & hex notations

## Exercising Notes

- Significant projects:
    - [`project 4`](./projects/04.c) (about string as array notation versus as pointer of `char`)
    - [`project 12`](./projects/12.c) (illustrate on how to take advantage of buffer in C)
    - [`project 14`](./projects/14.c) (discuss on operator precedence in C)
