What follows is a **“Learn C First” path** designed specifically for you:

* systems-minded
* Linux/CLI user
* cybersecurity + low-level interest
* already comfortable with programming concepts

This is **not** a generic beginner tutorial.
This is a **mental model → practice → intuition** path.

---

# The “Learn C First” Roadmap

Think of C as learning the **rules of reality** for software.

We’ll go in **layers**. Each layer answers *why* before *how*.

---

## Layer 0 — Setup & mindset (1 hour)

### Compiler (this matters)

Use `gcc` or `clang`.

```bash
sudo dnf install gcc clang
```

Compile like this **always** while learning:

```bash
gcc -Wall -Wextra -Wpedantic -Werror -g main.c
```

Why:

* C lets you shoot yourself in the foot
* Warnings are *teachers*

---

### Minimal program (understand every byte)

```c
#include <stdio.h>

int main(void) {
    puts("Hello, C");
    return 0;
}
```

Key ideas:

* `main` is just a function
* Program exit code is **data**
* `#include` is **textual substitution**

---

## Layer 1 — Memory is the whole game (core C)

If you understand this layer, you **understand C**.

---

### Stack vs Heap

```c
int x = 10;              // stack
int *p = malloc(sizeof *p);  // heap
*p = 10;
free(p);
```

Mental model:

* Stack: automatic, fast, scoped
* Heap: manual, flexible, dangerous

**Exercise**

* Forget `free`
* Observe with `valgrind`

---

### Pointers (no magic allowed)

```c
int x = 42;
int *p = &x;
printf("%d\n", *p);
```

Rules:

* A pointer is **just an address**
* `*` means “go there”
* `&` means “where is this?”

**Exercise**

* Print addresses
* Modify values via pointers
* Cause a segfault intentionally

---

### Arrays are not arrays

```c
int a[3] = {1,2,3};
int *p = a;
```

Truth:

* Arrays decay into pointers
* No bounds checking
* Compiler trusts you

This is why C vulnerabilities exist.

---

## Layer 2 — Functions, files, and reality

---

### .h vs .c (no confusion allowed)

**math.h**

```c
int add(int a, int b);
```

**math.c**

```c
int add(int a, int b) {
    return a + b;
}
```

**main.c**

```c
#include "math.h"
```

Rules:

* Headers = **contracts**
* C files = **implementations**
* Linker connects everything

---

### Pass-by-value (always)

```c
void inc(int x) {
    x++;
}
```

This does nothing.

To mutate:

```c
void inc(int *x) {
    (*x)++;
}
```

---

## Layer 3 — Undefined behavior (this is where power lives)

C does **not** protect you.

```c
int x;
printf("%d\n", x); // UB
```

Or:

```c
int a[2];
a[5] = 99; // UB
```

Why this matters:

* Compiler optimizations rely on UB
* Exploits live here
* Defensive coding requires understanding it

---

## Layer 4 — Manual resource management

---

### malloc / free discipline

```c
int *buf = malloc(100 * sizeof *buf);
if (!buf) return -1;

/* use buf */

free(buf);
buf = NULL;
```

Rules:

* Every `malloc` has one `free`
* Never free twice
* Never use after free

This maps directly to **real CVEs**.

---

## Layer 5 — The OS boundary (this is gold for you)

C is how you talk to Linux.

---

### Syscalls feel different

```c
#include <unistd.h>

write(1, "Hello\n", 6);
```

No buffering. No safety net.

---

### File descriptors

```c
int fd = open("file.txt", O_RDONLY);
read(fd, buf, size);
close(fd);
```

Understanding this:

* Makes Bash scripts clearer
* Makes Docker clearer
* Makes exploits clearer

---

## Layer 6 — Build something small but real

### Project 1: Memory inspector

* Allocate memory
* Print addresses
* Modify via pointers
* Leak memory on purpose

### Project 2: Mini `cat`

* Use `open/read/write/close`
* No `stdio`
* Handle errors

### Project 3: Vulnerable program

* Buffer overflow
* Fix it
* Understand why it broke

---

## What you should **not** learn yet

❌ C++
❌ Advanced macros
❌ Frameworks
❌ Premature “best practices”

You’re building **instinct**, not style.

---

## When you “know C”

You’ll notice:

* Segfaults make sense
* You read man pages comfortably
* You predict bugs before they happen
* Other languages feel *honest*

---

## How long this takes (realistic)

* 2–3 weeks: functional
* 1–2 months: dangerous (good)
* Lifetime: mastery

---

## Your next concrete step (today)

1. Write a program that:

   * Allocates memory
   * Passes pointers to functions
   * Prints addresses
   * Frees correctly
2. Break it.
3. Fix it.

---

If you want, next we can:

* Walk **one of these layers in code together**
* Tie C concepts directly to **Hermes (your daemon)**
* Do **C → C++ transition properly**
* Build a **security-focused C playground**

Tell me where you want to zoom in.
