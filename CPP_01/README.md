*Tis project has been created as part of the 42 curriculum by meelma*

# CPP Module 01

## Description

This module focuses on memory allocation, pointers, references and file handling in C++. The goal is to learn when to use ponters vs references, how to work with files, pointers to members and switch statements.

##Instructions

Run `make` in the exercise directory to compile each exercise.

```bash
cd ex00 && make
./zombie

cd ex01 && make
./zombieHorde

cd ex02 && make
./brain

cd ex03 && make
./violence

cd ex04 && make
./sed readFile.txt "search" "replace"

cd ex05 && make
./harl

cd ex06 && make
./harlFilter "WARNING"
```

## Exercises

**ex00 - BraiiiiiiinnnzzzZ**: Create zombies on stack and heap. Learned when to use each — stack for temporary objects, heap when object needs to survive outside the function.

**ex01 - Moar brainz!**: Allocate an array of zombies with `new[]`. Needed a default constructor because array allocation calls it for each element.

**ex02 - HI THIS IS BRAIN**: Print addresses and values using pointer and reference to the same variable. Both point to the same memory location.

**ex03 - Unnecessary violence**: HumanA always has a weapon (use reference), HumanB might not have one (use pointer). Learned when to choose pointer vs reference.

**ex04 - Sed is for losers**: Read a file, replace all occurrences of a string, write to new file. Used `find()` and `substr()` since `replace()` was forbidden.

**ex05 - Harl 2.0**: Use pointers to member functions to call the right function based on a string. Avoids long if-else chains.

**ex06 - Harl filter**: Use switch statement with fall-through to print all messages from a level and above.

## Key Concepts Learned

- Stack is automatic, heap is manual (`new`/`delete`)
- References must be initialized and can't be null
- Pointers can be null and reassigned
- Use `->` with pointers, `.` with objects/references
- `std::ifstream` for reading, `std::ofstream` for writing
- `std::string::npos` means "not found" in string functions
- Pointers to member functions: `void (Class::*ptr)(void)`

## Resources

- C++ documentation on cplusplus.com
- 42 subject PDF



