# Chapter 11: Pointers

## Reading Notes 

- `&` is called *address* operator, `*` is called *indirection* operator.
- Use the keyword `const` to document that a function won't change an object whose address is passed into the function 
(but it doesn't prevent the function from doing modifications): 

```C
void foo(const int *p) {
  *p = 0; /** ILLEGAL **/
}
```

- Pointers as return values: 
    - **never** return a pointer to an automatic local variable
- A pointer is usually the same as address, but not always.

## Exercising Notes
- In [project 02](./projects/02.c), I've changed declaration of `find_closest_flight` to fit my original solution.


