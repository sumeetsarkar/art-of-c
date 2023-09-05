> Learning C

**How to navigate this repo and learn c?**

For the first part it is quite straight forward the file names and folders make it easy to understand the concept being demostrated in code.
File names follow the format of `<concept>.c` or `<concept>_<sub_concept/scenario>.c`, such as:

```
function_basic.c
function_pass_by_types.c
function_pointer_basic.c
function_pointer_typedef.c
function_pointer_return_from_function.c
```

Regarding learning c, use this repo has a reference repo to check concept code, but there is no substitution to writing code yourself. Learn a concept, build on it, try plenty examples. Once the concept is solidified with example apps, build over it with another C concept (just like a lego) but at each step, build or enhance your existing example apps. Implement data structures and algorithms to further cement your understanding.

Also, do not over focus on having everything right from the very get go, focus on improvements as you feel the need of it. Eg: I do not have a proper build system! - well for your very first few programs you do not need a makefile, punch in those `clang/gcc [various flags] app.c` commands and play around. Learn about the errors and warnings (do not ignore the warnings). Having a good code style guide being followed is good to begin with though.

Note: this repository is constantly evolving and certain code styles & concepts in code as a result is constantly evolving as the c learning advances.

### Topics
- Base C concepts
- [pointers](./pointers)
- [arrays](./arrays)
- [strings](./strings)
- [makefiles](./makefiles)
- [dsa](./dsa)

### Upcoming:
- Header files
- File handling more concepts and reading stdin
- Generic libs for Hashtable, Linkedlist, Stack, Queues
- Tries
- Bit manipulation
- Union
- Threads basic
- More of dsa

### Other meta tasks:
- Mention c development vim config and debugger setup.
- Add a pre-commit hook

### Good references:
- Use your man pages!
- https://cs50.readthedocs.io/style/c/
- https://en.cppreference.com/w/c/keyword
- https://www.youtube.com/@JacobSorber

