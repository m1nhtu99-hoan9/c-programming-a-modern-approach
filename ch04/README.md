# Chapter 4: Expressions

## Reading Notes

### Lvalue

- A `lvalue` represents an object stored in computer memory, not a constant or result of a computations. Variables are `lvalue`s, expressions are not.
- The assignment operator requires an `lvalue` as its left operand. 

### Trivias
- Be aware of implementation-defined behaviour.
- Avoid undefined behaviour.
- `rvalue` and "expression" are the terms can be used interchangeably.
- `v += e` isn't equivalent to `v = v + e`. For instance, `a[i++] += 2` behaves differently to `a[i++] = a[i++] + 2`.

## Relating Chapters

Chapter 23: `pow` function, `fmod` function 

## Exercises Notes

