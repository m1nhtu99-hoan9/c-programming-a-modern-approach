# Chapter 13: String

## Reading Notes

- Split a string over 2 or more lines

```C
printf("Let me tell you this: if you meet a loner, no matter what they tell you, it's not because they enjoy solitude. "
       "It's because they have tried to blend into the world before, and people continue to disappoint them.\n"
       "-- Jodi Picoult");
```

- Attempt to modify a string literal causes undefined behaviours, hence the program may behave erratically.
- Using an uninitialised pointer variable as a string is a serious error which causes undefined behaviour.
- `gets` function reads a full line of string input.
- Functions in `string.h` header: 
    - `strcpy` copies the second string argument into the first string argument. If the second string is longer than 
    the first one, undefined behaviour occurs.
    
    ```C
    char *strcpy(char *s1, const char *s2);
    ```
    -  `strncpy` is safer but slower alternative to `strcpy`. An example of using `strncpy`:
    
    ```C
    strncpy(str1, str2, sizeof(str1));
    ```
  
    - `strlen` return the length of a string:
    
    ```C
    size_t strlen(const char *s); 
    ```
  
    - `strcat` appends the content of the second string argument to the first one:
    
    ```C
    char *strcat(char *s1, const char *s2); 
    ```
  
    - `strcmp` compares two string arguments.

- String idiom: 
    - The below loop terminates when the value of the assignment is null.
    
    ```C
    while (*p++ = *s2++) { /* do something; */}
  
    /* safer way: */
    while ((*p++ = *s2++) != 0);
    ```
 
 - Command-line arguments:
 
    ```C
   int main(int argc, char *argv[]);
    ```
### Related chapters

- [Chapter 23](../ch23): `string.h` header

## Exercising Notes
