# Chapter 6: Loops

## Reading Notes

- Comma operator can be used to initialise more than 1 variable when entering a statement. For example:

```C
for (sum = 0, i = 1; i <= N; i++)
  sum += i;
```

- `for (;;)` behave the same as `while (1)`
- Null statement example: 

```C
for (d = 2; d <= n && n % d != 0; d++);

/* or to make it stand out */
for (d = 2; d <= n && n % d != 0; d++) {};
```

### Exercising Notes
- The most significant projects: [Project 08](./projects/08.c)