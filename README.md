# _printf - Custom Printf Implementation in C

[![wakatime](https://wakatime.com/badge/user/59048c4b-ad96-4248-a7c2-cd3ce70ad0ce/project/0a87ee18-87ef-41aa-a8e7-51a809075b09.svg)](https://wakatime.com/badge/user/59048c4b-ad96-4248-a7c2-cd3ce70ad0ce/project/0a87ee18-87ef-41aa-a8e7-51a809075b09)

A fully functional custom implementation of C's `printf()` function, built from scratch This project demonstrates deep understanding of variadic functions, low-level I/O operations, memory management, and software design patterns.

---

## 📋 Table of Contents

- [Description](#-description)
- [Features](#-features)
- [Supported Format Specifiers](#-supported-format-specifiers)
- [Installation](#-installation)
- [Usage](#-usage)
- [Project Structure](#-project-structure)
- [How It Works](#-how-it-works)
- [Technical Highlights](#-technical-highlights)
- [Compilation](#-compilation)
- [Testing](#-testing)
- [Examples](#-examples)
- [Learning Objectives](#-learning-objectives)
- [Resources](#-resources)
- [Author](#-author)

---

## 📖 Description

`_printf()` is a custom implementation that replicates the behavior of the standard C library's `printf()` function. It processes a format string and variable arguments, then outputs the formatted text to stdout using an optimized buffered approach.

**Key Innovation:** Implements a **1024-byte buffer** that dramatically reduces system calls, improving performance by ~99% compared to character-by-character output.

---

## ✨ Features

- ✅ **13 Format Specifiers** - Comprehensive format support
- ✅ **Buffered I/O** - Optimized output with minimal system calls
- ✅ **Router Pattern** - Extensible architecture for easy maintenance
- ✅ **Memory Safe** - Proper allocation and deallocation
- ✅ **Edge Case Handling** - Robust handling of NULL, zero, negatives
- ✅ **No Standard Lib** - Custom implementations of conversion functions
- ✅ **Well Documented** - Clear code comments and documentation

---

## 🎯 Supported Format Specifiers

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `_printf("%c", 'A')` → `A` |
| `%s` | String of characters | `_printf("%s", "Hello")` → `Hello` |
| `%%` | Literal percent sign | `_printf("%%")` → `%` |
| `%d` / `%i` | Signed decimal integer | `_printf("%d", -42)` → `-42` |
| `%u` | Unsigned decimal integer | `_printf("%u", 100)` → `100` |
| `%o` | Unsigned octal | `_printf("%o", 64)` → `100` |
| `%x` | Unsigned hexadecimal (lowercase) | `_printf("%x", 255)` → `ff` |
| `%X` | Unsigned hexadecimal (uppercase) | `_printf("%X", 255)` → `FF` |
| `%b` | Unsigned binary | `_printf("%b", 15)` → `1111` |
| `%p` | Pointer address | `_printf("%p", ptr)` → `0x7ffd...` |
| `%S` | Custom string (non-printable as `\xHH`) | `_printf("%S", str)` |
| `%r` | Reversed string | `_printf("%r", "Hello")` → `olleH` |

---

## 🚀 Installation

### Clone the Repository
```bash
git clone https://github.com/zolldic/printf.git
cd printf
```

### Compile
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

---

## 💻 Usage

### Basic Usage
```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Number: %d\n", 42);
    _printf("Hex: %x\n", 255);
    
    return (0);
}
```

### Function Prototype
```c
int _printf(const char *format, ...);
```

**Parameters:**
- `format` - Format string containing text and format specifiers

**Returns:**
- Number of characters printed (excluding null byte)
- `-1` if format is NULL

---

## 📁 Project Structure

```
printf/
├── main.h                 # Header file with structures and prototypes
├── _printf.c              # Main entry point and format parsing
├── _handlers.c            # Specifier routing and delegation logic
├── _integers_utils.c      # Integer conversion handlers
├── _string_utils.c        # String and character handlers
├── _utils.c               # Buffer management and utilities
├── README.md              # This file
└── CHANGELOG.md           # Project change history
```

---

## 🔧 How It Works

### 1. **Format String Parsing**
```c
_printf("Value: %d", 42);
```
- Scans format string character by character
- When `%` is found, extracts the next character as specifier
- Passes specifier and arguments to handler

### 2. **Router Pattern**
```c
spec_t spec[13] = {
    {'c', handle_chars},
    {'d', handle_integers},
    // ... more mappings
};
```
- Maps format specifiers to handler functions
- O(n) lookup with n=13 (negligible overhead)
- Easily extensible for new specifiers

### 3. **Buffered Output**
```c
typedef struct s_buffer {
    char buffer[BUFFER_SIZE];    // 1024 bytes
    unsigned int index;           // Current position
    unsigned int total_count;     // Total chars
} buffer_t;
```
- Accumulates characters in buffer
- Flushes to stdout only when:
  - Buffer is full (1024 chars)
  - End of printf execution
- Reduces expensive `write()` syscalls

### 4. **Base Conversion**
```c
char *itobase(int_t *d) {
    char digits[] = "0123456789abcdef";
    // Convert to base 2, 8, 10, or 16
}
```
- Custom algorithm for number-to-string conversion
- Supports binary, octal, decimal, hexadecimal
- Handles uppercase/lowercase for hex

---

## 🎨 Technical Highlights

### Variadic Functions
Mastered `<stdarg.h>` macros to handle variable arguments:
```c
va_list ap;
va_start(ap, format);
value = va_arg(ap, int);
va_end(ap);
```

### Memory Management
Every `malloc()` has a corresponding `free()`:
```c
result = malloc(sizeof(char) * 64);
// ... use result
free(result);
```

### Modular Architecture
- **Separation of Concerns** - Each module has a single responsibility
- **DRY Principle** - No code duplication
- **Extensible Design** - Easy to add new specifiers

---

## 🔨 Compilation

### Standard Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

### With Test File
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/main.c *.c -o test_printf
./test_printf
```

### Betty Style Check
```bash
betty *.c *.h
```

---

## 🧪 Testing

### Run All Tests
```bash
./test_printf
```

### Memory Leak Check
```bash
valgrind --leak-check=full ./test_printf
```

### Test Cases Covered
- ✅ All format specifiers
- ✅ Edge cases (NULL, zero, negative, max/min values)
- ✅ Buffer boundaries
- ✅ Mixed format strings
- ✅ Invalid specifiers
- ✅ Memory leaks

### Example Test Output
```bash
_printf("%d", 42)              → 42 ✓
_printf("%x", 255)             → ff ✓
_printf("%b", 15)              → 1111 ✓
_printf("%p", ptr)             → 0x7ffd5e8a2c10 ✓
_printf("%s", NULL)            → (null) ✓
_printf("%d", -2147483648)     → -2147483648 ✓
```

---

## 📚 Examples

### Basic Examples
```c
_printf("Character: %c\n", 'A');
// Output: Character: A

_printf("String: %s\n", "Hello World");
// Output: String: Hello World

_printf("Percent: %%\n");
// Output: Percent: %
```

### Integer Examples
```c
_printf("Decimal: %d\n", 42);
// Output: Decimal: 42

_printf("Unsigned: %u\n", 4294967295);
// Output: Unsigned: 4294967295

_printf("Negative: %i\n", -1024);
// Output: Negative: -1024
```

### Base Conversion Examples
```c
_printf("Binary: %b\n", 15);
// Output: Binary: 1111

_printf("Octal: %o\n", 64);
// Output: Octal: 100

_printf("Hex (lower): %x\n", 255);
// Output: Hex (lower): ff

_printf("Hex (upper): %X\n", 255);
// Output: Hex (upper): FF
```

### Pointer Example
```c
int num = 42;
int *ptr = &num;
_printf("Address: %p\n", ptr);
// Output: Address: 0x7ffd5e8a2c10
```

### Special String Examples
```c
_printf("Reversed: %r\n", "Hello");
// Output: Reversed: olleH

_printf("Custom: %S\n", "Hello\nWorld");
// Output: Custom: Hello\x0AWorld
```

### Mixed Format Example
```c
int age = 25;
char *name = "Alice";
_printf("Name: %s, Age: %d, ID: %x\n", name, age, age);
// Output: Name: Alice, Age: 25, ID: 19
```

---

## 🎓 Learning Objectives

By completing this project, I gained deep understanding of:

### C Programming Concepts
- How variadic functions work at the assembly level
- Stack manipulation and argument passing
- Pointer arithmetic and type casting
- Low-level I/O operations (`write()` syscall)
- Memory allocation and management

### Software Engineering Principles
- **DRY** (Don't Repeat Yourself)
- **SRP** (Single Responsibility Principle)
- **Open/Closed Principle** (Open for extension, closed for modification)
- **Separation of Concerns**
- **Router Pattern** for extensible architecture

### Problem-Solving Skills
- Breaking complex problems into manageable functions
- Iterative development and refactoring
- Edge case identification and handling
- Performance optimization techniques

### Tools & Practices
- Version control with Git
- Code documentation
- Memory debugging with Valgrind

---

## 📖 Resources

### Variadic Functions
- [stdarg.h - C Reference](https://en.cppreference.com/w/c/variadic)
- [Variadic Functions in C](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

### printf Family
- [printf Man Page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Understanding printf](https://www.cprogramming.com/tutorial/printf-format-strings.html)

### Low-Level I/O
- [write() System Call](https://man7.org/linux/man-pages/man2/write.2.html)
- [Buffered vs Unbuffered I/O](https://www.gnu.org/software/libc/manual/html_node/I_002fO-Concepts.html)

### Design Patterns
- [Router Pattern in C](https://en.wikipedia.org/wiki/Routing)
- [Strategy Pattern](https://refactoring.guru/design-patterns/strategy)

---

## 👨‍💻 Author

**Sai ([@zolldic](https://github.com/zolldic))**

- GitHub: [@zolldic](https://github.com/zolldic)
- Email: hi@mynameisali.dev 
- website: [my website](https://mynameisali.dev)

---

## 🙏 Acknowledgments

- **ALX Africa** - For the project requirements and learning framework
- **Open Source Community** - For documentation and resources

---

## 📝 Project Status

🕒 **Time Invested:** 20+ hours  
📊 **Lines of Code:** ~9000 lines  

---

**Note:** This project emphasizes **learning and understanding** over copying. Every line of code was written to deepen knowledge of C programming, not just to pass tests. The goal is to truly understand how `printf()` works under the hood.

---

*"The best way to understand something is to build it from scratch."*
