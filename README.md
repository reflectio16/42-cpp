# 42 — C++ Modules (00–09)

C++ modules from the 42 school curriculum, covering core OOP concepts including classes, memory management, inheritance, polymorphism, templates, exceptions, and the STL.

---

![C++](https://img.shields.io/badge/C%2B%2B-98-blue)
![42](https://img.shields.io/badge/42-school-black)

## Modules

| Module | Topics |
|--------|--------|
| [CPP00](./CPP_00) | Namespaces, classes, member functions, stdio streams, initialization lists |
| [CPP01](./CPP_01) | Memory allocation, pointers to members, references, switch statements |
| [CPP02](./CPP_02) | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form |
| [CPP03](./CPP_03) | Inheritance |
| [CPP04](./CPP_04) | Subtype polymorphism, abstract classes, interfaces |
| [CPP05](./CPP_05) | Repetition and exceptions |
| [CPP06](./CPP_06) | C++ casts (static, dynamic, const, reinterpret) |
| [CPP07](./CPP_07) | C++ templates |
| [CPP08](./CPP_08) | Templated containers, iterators, algorithms |
| [CPP09](./CPP_09) | STL containers (map, stack, vector, list); merge-insertion sort |

---

## Highlights

A few exercises worth pointing at:

- **CPP08/ex02 — MutantStack**: implementing iterators by inheriting from `std::stack` and exposing the underlying container's iterators.
- **CPP09/ex00 — Bitcoin Exchange**: using `std::map` with string-encoded dates for chronological lookups via `lower_bound`.
- **CPP09/ex01 — RPN**: stack-based postfix expression evaluator with overflow detection.
- **CPP09/ex02 — PmergeMe**: full implementation of the Ford-Johnson merge-insertion sort algorithm, on both `std::vector` and `std::list`, with timing comparison demonstrating the real-world impact of cache locality.

---

## Build

Each exercise has its own `Makefile`. To compile any exercise:

```bash
cd CPP_0X/exXX
make
```

To clean:

```bash
make fclean
```

---

## Key takeaways
   
   - The C++ STL provides remarkably efficient general-purpose containers — choosing the right one matters more than micro-optimizing code.
   - Container memory layout (contiguous vs scattered) often dominates performance more than theoretical complexity, due to CPU cache behavior.
   - RAII makes manual memory management unnecessary in most C++ code; exceptions naturally clean up resources.
   - Iterator categories (random-access vs bidirectional) determine which algorithms compile at full efficiency.

## Notes

- Compiled with `c++ -Wall -Wextra -Werror -std=c++98`
- No external libraries used
- All exercises follow the Orthodox Canonical Form where applicable
- Memory-checked with `valgrind` (Linux) / `leaks` (macOS)
